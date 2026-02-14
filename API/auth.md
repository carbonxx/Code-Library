# API Authentication

Authentication verifies the identity of a user or application accessing an API.

## Table of Contents
- [Why Authentication?](#why-authentication)
- [Authentication vs Authorization](#authentication-vs-authorization)
- [API Keys](#api-keys)
- [Bearer Tokens](#bearer-tokens)
- [JWT (JSON Web Tokens)](#jwt-json-web-tokens)
- [OAuth 2.0](#oauth-20)
- [Basic Authentication](#basic-authentication)
- [Comparison Table](#comparison-table)
- [Best Practices](#best-practices)

---

## Why Authentication?

Authentication is essential for:
- **Security**: Protect sensitive data
- **Rate Limiting**: Control API usage per user
- **Analytics**: Track who uses what
- **Access Control**: Restrict certain operations
- **Billing**: Charge based on usage

---

## Authentication vs Authorization

| Aspect | Authentication | Authorization |
|--------|---------------|---------------|
| Question | Who are you? | What can you do? |
| Process | Verify identity | Check permissions |
| Example | Login with password | Admin vs regular user |
| HTTP Code | 401 Unauthorized | 403 Forbidden |

**Example**
```
Authentication: "I am user John" (verified by password/token)
Authorization: "Can John delete this post?" (checked against permissions)
```

---

## API Keys

Simple authentication using a unique key.

### How It Works

1. Generate API key (long random string)
2. Include key in every request
3. Server validates key

### Implementation

**Request with API Key**
```
GET /api/users
Host: api.example.com
X-API-Key: abc123xyz789
```

**Python Example**
```python
import requests

API_KEY = "abc123xyz789"

# Method 1: Header
headers = {"X-API-Key": API_KEY}
response = requests.get("https://api.example.com/users", headers=headers)

# Method 2: Query parameter (less secure)
params = {"api_key": API_KEY}
response = requests.get("https://api.example.com/users", params=params)
```

**JavaScript Example**
```javascript
const API_KEY = "abc123xyz789";

// Using header
fetch("https://api.example.com/users", {
  headers: {
    "X-API-Key": API_KEY
  }
})
  .then(res => res.json())
  .then(data => console.log(data));
```

### Pros and Cons

**Pros:**
- Simple to implement
- Easy to understand
- No expiration needed

**Cons:**
- If leaked, valid until manually revoked
- Hard to rotate
- No built-in expiration
- Usually tied to account, not user

### Use Cases
- Internal APIs
- Server-to-server communication
- Third-party service integration (Stripe, SendGrid)

---

## Bearer Tokens

Generic token passed in Authorization header.

### How It Works

1. User logs in
2. Server generates token
3. Client includes token in subsequent requests
4. Server validates token

### Implementation

**Request with Bearer Token**
```
GET /api/users
Authorization: Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9...
```

**Python Example**
```python
import requests

TOKEN = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9..."

headers = {"Authorization": f"Bearer {TOKEN}"}
response = requests.get("https://api.example.com/users", headers=headers)

print(response.json())
```

**JavaScript Example**
```javascript
const TOKEN = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9...";

fetch("https://api.example.com/users", {
  headers: {
    "Authorization": `Bearer ${TOKEN}`
  }
})
  .then(res => res.json())
  .then(data => console.log(data));
```

### Complete Login Flow

**Python**
```python
import requests

# Step 1: Login
login_data = {
    "username": "john@example.com",
    "password": "secret123"
}

response = requests.post(
    "https://api.example.com/auth/login",
    json=login_data
)

if response.status_code == 200:
    token = response.json()["token"]
    print(f"Token: {token}")
    
    # Step 2: Use token for authenticated requests
    headers = {"Authorization": f"Bearer {token}"}
    
    response = requests.get(
        "https://api.example.com/users/me",
        headers=headers
    )
    
    print(response.json())
```

**JavaScript**
```javascript
async function loginAndFetch() {
  // Step 1: Login
  const loginResponse = await fetch("https://api.example.com/auth/login", {
    method: "POST",
    headers: {
      "Content-Type": "application/json"
    },
    body: JSON.stringify({
      username: "john@example.com",
      password: "secret123"
    })
  });
  
  const { token } = await loginResponse.json();
  console.log(`Token: ${token}`);
  
  // Step 2: Use token
  const userResponse = await fetch("https://api.example.com/users/me", {
    headers: {
      "Authorization": `Bearer ${token}`
    }
  });
  
  const user = await userResponse.json();
  console.log(user);
}
```

---

## JWT (JSON Web Tokens)

Self-contained tokens that carry user information.

### Structure

JWT has three parts separated by dots:
```
header.payload.signature
eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VyX2lkIjo0MiwibmFtZSI6IkpvaG4gRG9lIiwiZXhwIjoxNjMzMDcyODAwfQ.4pcPyMD09olPSyXnrXCjTwXyr4BsezdI1AVTmud2fU4
```

**Header**
```json
{
  "alg": "HS256",
  "typ": "JWT"
}
```

**Payload (Claims)**
```json
{
  "user_id": 42,
  "name": "John Doe",
  "email": "john@example.com",
  "exp": 1633072800,
  "iat": 1633069200
}
```

**Signature**
```
HMACSHA256(
  base64UrlEncode(header) + "." +
  base64UrlEncode(payload),
  secret
)
```

### Standard Claims

| Claim | Meaning |
|-------|---------|
| **iss** | Issuer |
| **sub** | Subject (user ID) |
| **aud** | Audience |
| **exp** | Expiration time |
| **iat** | Issued at |
| **nbf** | Not before |

### Implementation

**Python - Creating JWT**
```python
import jwt
from datetime import datetime, timedelta

# Create JWT
payload = {
    "user_id": 42,
    "name": "John Doe",
    "exp": datetime.utcnow() + timedelta(hours=1)  # Expires in 1 hour
}

secret = "your-secret-key"
token = jwt.encode(payload, secret, algorithm="HS256")

print(token)
```

**Python - Verifying JWT**
```python
import jwt

token = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9..."
secret = "your-secret-key"

try:
    payload = jwt.decode(token, secret, algorithms=["HS256"])
    print(f"User ID: {payload['user_id']}")
    print(f"Name: {payload['name']}")
except jwt.ExpiredSignatureError:
    print("Token has expired")
except jwt.InvalidTokenError:
    print("Invalid token")
```

**JavaScript - Verifying JWT**
```javascript
// Using jsonwebtoken library
const jwt = require('jsonwebtoken');

const token = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9...";
const secret = "your-secret-key";

try {
  const payload = jwt.verify(token, secret);
  console.log(`User ID: ${payload.user_id}`);
  console.log(`Name: ${payload.name}`);
} catch (error) {
  if (error.name === 'TokenExpiredError') {
    console.log('Token has expired');
  } else {
    console.log('Invalid token');
  }
}
```

### Refresh Tokens

Long-lived tokens used to get new access tokens.

```python
import requests

# Use refresh token to get new access token
refresh_token = "long_lived_refresh_token"

response = requests.post(
    "https://api.example.com/auth/refresh",
    json={"refresh_token": refresh_token}
)

if response.status_code == 200:
    new_access_token = response.json()["access_token"]
    print(f"New access token: {new_access_token}")
```

**Typical Flow:**
1. Login → Receive access token (short-lived) + refresh token (long-lived)
2. Use access token for API calls
3. When access token expires, use refresh token to get new access token
4. Repeat until refresh token expires

### Pros and Cons

**Pros:**
- Self-contained (server doesn't need to store sessions)
- Can include user data
- Supports expiration
- Stateless

**Cons:**
- Cannot be revoked before expiration (unless using token blacklist)
- Larger than simple tokens
- Payload is readable (base64 encoded, not encrypted)

---

## OAuth 2.0

Industry-standard authorization framework.

### Common Use Cases
- "Login with Google"
- "Login with Facebook"
- "Login with GitHub"

### OAuth Roles

- **Resource Owner**: User
- **Client**: Your application
- **Resource Server**: API server
- **Authorization Server**: Issues tokens

### Authorization Code Flow

```
1. User clicks "Login with Google"
2. Redirected to Google login page
3. User logs in and grants permissions
4. Google redirects back with authorization code
5. Your server exchanges code for access token
6. Use access token to access user's Google data
```

### Implementation Example

**Python - GitHub OAuth**
```python
import requests

# Step 1: Redirect user to GitHub authorization
client_id = "your_client_id"
redirect_uri = "http://localhost:5000/callback"
scope = "user:email"

auth_url = (
    f"https://github.com/login/oauth/authorize"
    f"?client_id={client_id}"
    f"&redirect_uri={redirect_uri}"
    f"&scope={scope}"
)

print(f"Visit: {auth_url}")

# Step 2: User is redirected back with code
# http://localhost:5000/callback?code=abc123

# Step 3: Exchange code for access token
code = "abc123"  # From callback URL
client_secret = "your_client_secret"

response = requests.post(
    "https://github.com/login/oauth/access_token",
    data={
        "client_id": client_id,
        "client_secret": client_secret,
        "code": code
    },
    headers={"Accept": "application/json"}
)

access_token = response.json()["access_token"]

# Step 4: Use access token to get user data
headers = {"Authorization": f"Bearer {access_token}"}
response = requests.get("https://api.github.com/user", headers=headers)

user = response.json()
print(f"GitHub user: {user['login']}")
```

### OAuth Scopes

Scopes define what access the token grants.

```python
# Read-only access to user profile
scope = "user:email"

# Read and write access
scope = "repo user:email"

# Limited access
scope = "read:user"
```

---

## Basic Authentication

Username and password sent with each request.

### How It Works

1. Combine username and password: `username:password`
2. Encode with Base64
3. Send in Authorization header

### Implementation

**Manual Example**
```python
import base64
import requests

username = "john@example.com"
password = "secret123"

# Encode credentials
credentials = f"{username}:{password}"
encoded = base64.b64encode(credentials.encode()).decode()

headers = {"Authorization": f"Basic {encoded}"}
response = requests.get("https://api.example.com/users", headers=headers)
```

**Using Requests Library**
```python
import requests

response = requests.get(
    "https://api.example.com/users",
    auth=("john@example.com", "secret123")  # Automatically encodes
)

print(response.json())
```

**JavaScript Example**
```javascript
const username = "john@example.com";
const password = "secret123";

// Encode credentials
const credentials = btoa(`${username}:${password}`);

fetch("https://api.example.com/users", {
  headers: {
    "Authorization": `Basic ${credentials}`
  }
})
  .then(res => res.json())
  .then(data => console.log(data));
```

### Pros and Cons

**Pros:**
- Simple to implement
- Widely supported
- No session management

**Cons:**
- Sends credentials with every request
- Must use HTTPS (credentials easily decoded)
- No built-in token expiration
- Password changes break all sessions

### When to Use
- Internal tools
- Quick prototypes
- When combined with HTTPS

---

## Comparison Table

| Method | Security | Complexity | Expiration | Best For |
|--------|----------|------------|------------|----------|
| **API Key** | Low-Medium | Low | Manual | Server-to-server |
| **Bearer Token** | Medium | Medium | Yes | Modern APIs |
| **JWT** | Medium-High | Medium | Yes | Stateless APIs |
| **OAuth 2.0** | High | High | Yes | Third-party auth |
| **Basic Auth** | Low | Low | No | Internal tools |

---

## Best Practices

### 1. Always Use HTTPS

**Never** send authentication credentials over HTTP.

```python
# Good
response = requests.get("https://api.example.com/users", headers=headers)

# Bad - credentials can be intercepted
response = requests.get("http://api.example.com/users", headers=headers)
```

### 2. Store Tokens Securely

**Never** store tokens in:
- URL parameters
- Local storage (for sensitive tokens)
- Git repositories
- Plain text files

**Do** store tokens in:
- Environment variables
- Secure credential managers
- HTTP-only cookies (for web apps)

```python
import os

# Good - from environment variable
API_KEY = os.environ.get("API_KEY")

# Bad - hardcoded
API_KEY = "abc123xyz789"
```

### 3. Use Token Expiration

```python
# Short-lived access tokens
access_token_expiry = 1 hour

# Long-lived refresh tokens
refresh_token_expiry = 30 days
```

### 4. Implement Rate Limiting

```python
# Limit requests per user
max_requests_per_hour = 1000
```

### 5. Validate Tokens on Server

```python
def validate_token(token):
    try:
        payload = jwt.decode(token, SECRET_KEY, algorithms=["HS256"])
        
        # Check if token is expired
        if payload["exp"] < time.time():
            return None
        
        # Check if user still exists
        user = get_user(payload["user_id"])
        if not user:
            return None
        
        return payload
    except:
        return None
```

### 6. Handle Token Refresh

```python
import requests

def make_authenticated_request(url, access_token, refresh_token):
    headers = {"Authorization": f"Bearer {access_token}"}
    response = requests.get(url, headers=headers)
    
    # If access token expired
    if response.status_code == 401:
        # Refresh access token
        refresh_response = requests.post(
            "https://api.example.com/auth/refresh",
            json={"refresh_token": refresh_token}
        )
        
        if refresh_response.status_code == 200:
            new_access_token = refresh_response.json()["access_token"]
            
            # Retry original request
            headers = {"Authorization": f"Bearer {new_access_token}"}
            response = requests.get(url, headers=headers)
    
    return response
```

### 7. Log Authentication Attempts

```python
# Log failed login attempts
failed_attempts[user_id] += 1

# Block after too many failures
if failed_attempts[user_id] > 5:
    block_user(user_id, duration=timedelta(minutes=15))
```

---

## Summary

**Choose authentication based on your needs:**

- **API Key**: Simple internal APIs
- **Bearer Token**: Modern stateless APIs
- **JWT**: Microservices, stateless architecture
- **OAuth 2.0**: Third-party authentication
- **Basic Auth**: Quick prototypes, HTTPS required

**Key Principles:**
- Always use HTTPS
- Store tokens securely
- Implement expiration
- Validate on server
- Handle refresh gracefully
- Log authentication events