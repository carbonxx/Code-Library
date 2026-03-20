# HTTP Status Codes

HTTP status codes indicate the result of an API request.

## Table of Contents
- [Status Code Categories](#status-code-categories)
- [1xx Informational](#1xx-informational)
- [2xx Success](#2xx-success)
- [3xx Redirection](#3xx-redirection)
- [4xx Client Error](#4xx-client-error)
- [5xx Server Error](#5xx-server-error)
- [Quick Reference](#quick-reference)
- [Handling Status Codes](#handling-status-codes)

---

## Status Code Categories

Status codes are grouped into five categories:

| Range | Category | Meaning |
|-------|----------|---------|
| **1xx** | Informational | Request received, continuing process |
| **2xx** | Success | Request successfully received and processed |
| **3xx** | Redirection | Further action needed to complete request |
| **4xx** | Client Error | Request contains bad syntax or cannot be fulfilled |
| **5xx** | Server Error | Server failed to fulfill valid request |

---

## 1xx Informational

Rarely used in REST APIs. Indicates the request was received and is being processed.

| Code | Status | Description |
|------|--------|-------------|
| **100** | Continue | Client should continue with request |
| **101** | Switching Protocols | Server is switching protocols as requested |

---

## 2xx Success

Indicates the request was successfully received, understood, and accepted.

### 200 OK
**General success status**

Used for successful GET, PUT, PATCH requests.

```json
{
  "status": "success",
  "data": {
    "id": 42,
    "name": "John Doe"
  }
}
```

**Example**
```python
import requests

response = requests.get("https://api.example.com/users/42")
if response.status_code == 200:
    data = response.json()
    print(data)
```

---

### 201 Created
**Resource successfully created**

Used for successful POST requests that create new resources.

**Response should include Location header** pointing to the new resource.

```
HTTP/1.1 201 Created
Location: /api/users/42
Content-Type: application/json

{
  "id": 42,
  "name": "John Doe",
  "email": "john@example.com"
}
```

**Example**
```python
import requests

new_user = {"name": "John Doe", "email": "john@example.com"}
response = requests.post("https://api.example.com/users", json=new_user)

if response.status_code == 201:
    print("User created successfully")
    created_user = response.json()
    print(f"New user ID: {created_user['id']}")
```

---

### 202 Accepted
**Request accepted for processing**

Used for asynchronous operations. The request is valid but processing hasn't completed yet.

```json
{
  "status": "accepted",
  "message": "Your request is being processed",
  "job_id": "abc-123",
  "status_url": "/api/jobs/abc-123"
}
```

---

### 204 No Content
**Success but no content to return**

Commonly used for successful DELETE requests or updates that don't return data.

```
HTTP/1.1 204 No Content
```

**Example**
```python
import requests

response = requests.delete("https://api.example.com/users/42")

if response.status_code == 204:
    print("User deleted successfully")
    # No response body to parse
```

---

### Other 2xx Codes

| Code | Status | Usage |
|------|--------|-------|
| **206** | Partial Content | Used for range requests (downloading parts of a file) |

---

## 3xx Redirection

Indicates the client must take additional action to complete the request.

| Code | Status | Description |
|------|--------|-------------|
| **301** | Moved Permanently | Resource permanently moved to new URL |
| **302** | Found | Resource temporarily at different URL |
| **304** | Not Modified | Cached version is still valid |
| **307** | Temporary Redirect | Like 302, but method must not change |
| **308** | Permanent Redirect | Like 301, but method must not change |

**Example**
```python
import requests

response = requests.get("https://api.example.com/old-endpoint")

if response.status_code == 301:
    new_url = response.headers["Location"]
    print(f"Resource moved to: {new_url}")
```

---

## 4xx Client Error

Indicates the client made an error in the request.

### 400 Bad Request
**Invalid request syntax**

The request is malformed or has invalid parameters.

```json
{
  "status": "error",
  "message": "Invalid request",
  "errors": [
    {
      "field": "email",
      "message": "Email format is invalid"
    }
  ]
}
```

**Example**
```python
import requests

# Invalid data (missing required field)
new_user = {"name": "John Doe"}  # email is required

response = requests.post("https://api.example.com/users", json=new_user)

if response.status_code == 400:
    error = response.json()
    print(f"Bad request: {error['message']}")
```

---

### 401 Unauthorized
**Authentication required or failed**

The request lacks valid authentication credentials.

```json
{
  "status": "error",
  "message": "Authentication required",
  "code": 401
}
```

**Example**
```python
import requests

# Request without authentication
response = requests.get("https://api.example.com/protected")

if response.status_code == 401:
    print("Authentication required. Please provide valid credentials.")

# Request with authentication
headers = {"Authorization": "Bearer your-token-here"}
response = requests.get("https://api.example.com/protected", headers=headers)
```

---

### 403 Forbidden
**Client lacks permission**

Authentication succeeded but user doesn't have permission to access the resource.

```json
{
  "status": "error",
  "message": "You don't have permission to access this resource",
  "code": 403
}
```

**401 vs 403**
- **401**: Not authenticated (login required)
- **403**: Authenticated but not authorized (insufficient permissions)

---

### 404 Not Found
**Resource doesn't exist**

The requested resource was not found on the server.

```json
{
  "status": "error",
  "message": "User not found",
  "code": 404
}
```

**Example**
```python
import requests

response = requests.get("https://api.example.com/users/999")

if response.status_code == 404:
    print("User not found")
elif response.status_code == 200:
    user = response.json()
    print(f"User found: {user['name']}")
```

---

### 405 Method Not Allowed
**HTTP method not supported**

The endpoint exists, but the HTTP method is not allowed.

```json
{
  "status": "error",
  "message": "Method DELETE not allowed",
  "allowed_methods": ["GET", "POST"]
}
```

---

### 409 Conflict
**Request conflicts with current state**

Commonly used when trying to create a resource that already exists.

```json
{
  "status": "error",
  "message": "User with this email already exists",
  "code": 409
}
```

**Example**
```python
import requests

new_user = {
    "name": "John Doe",
    "email": "existing@example.com"  # Already exists
}

response = requests.post("https://api.example.com/users", json=new_user)

if response.status_code == 409:
    print("User already exists")
```

---

### 422 Unprocessable Entity
**Validation error**

Request is well-formed but contains semantic errors.

```json
{
  "status": "error",
  "message": "Validation failed",
  "errors": [
    {
      "field": "age",
      "message": "Age must be between 0 and 120"
    },
    {
      "field": "email",
      "message": "Email is already taken"
    }
  ]
}
```

---

### 429 Too Many Requests
**Rate limit exceeded**

Client has sent too many requests in a given time period.

```json
{
  "status": "error",
  "message": "Rate limit exceeded",
  "retry_after": 60
}
```

**Example**
```python
import requests
import time

response = requests.get("https://api.example.com/users")

if response.status_code == 429:
    retry_after = int(response.headers.get("Retry-After", 60))
    print(f"Rate limited. Retry after {retry_after} seconds")
    time.sleep(retry_after)
    # Retry the request
    response = requests.get("https://api.example.com/users")
```

---

### Other 4xx Codes

| Code | Status | Description |
|------|--------|-------------|
| **402** | Payment Required | Reserved for future use |
| **406** | Not Acceptable | Server cannot produce response matching Accept headers |
| **408** | Request Timeout | Client took too long to send request |
| **410** | Gone | Resource permanently removed |
| **413** | Payload Too Large | Request body exceeds size limit |
| **414** | URI Too Long | URL is too long |
| **415** | Unsupported Media Type | Content-Type not supported |

---

## 5xx Server Error

Indicates the server failed to fulfill a valid request.

### 500 Internal Server Error
**Generic server error**

Something went wrong on the server, but the server doesn't know what.

```json
{
  "status": "error",
  "message": "Internal server error",
  "code": 500
}
```

**Example**
```python
import requests

response = requests.get("https://api.example.com/users")

if response.status_code == 500:
    print("Server error. Please try again later.")
```

---

### 502 Bad Gateway
**Invalid response from upstream server**

Server acting as gateway received invalid response from upstream server.

---

### 503 Service Unavailable
**Server temporarily unavailable**

Server is temporarily unable to handle the request (maintenance, overload).

```json
{
  "status": "error",
  "message": "Service temporarily unavailable",
  "retry_after": 300
}
```

---

### 504 Gateway Timeout
**Gateway timeout**

Server acting as gateway didn't receive timely response from upstream server.

---

### Other 5xx Codes

| Code | Status | Description |
|------|--------|-------------|
| **501** | Not Implemented | Server doesn't support the functionality |
| **505** | HTTP Version Not Supported | HTTP version not supported |

---

## Quick Reference

### Most Common Codes

| Code | Name | Use Case |
|------|------|----------|
| **200** | OK | Successful GET, PUT, PATCH |
| **201** | Created | Successful POST (resource created) |
| **204** | No Content | Successful DELETE |
| **400** | Bad Request | Invalid request data |
| **401** | Unauthorized | Missing/invalid authentication |
| **403** | Forbidden | Insufficient permissions |
| **404** | Not Found | Resource doesn't exist |
| **409** | Conflict | Duplicate resource |
| **422** | Unprocessable Entity | Validation error |
| **429** | Too Many Requests | Rate limit exceeded |
| **500** | Internal Server Error | Server error |
| **503** | Service Unavailable | Server temporarily down |

---

## Handling Status Codes

### Python Complete Example

```python
import requests

def make_api_request(url, method="GET", **kwargs):
    """Make API request with comprehensive error handling"""
    
    try:
        response = requests.request(method, url, **kwargs)
        
        # Handle different status codes
        if response.status_code == 200:
            return response.json()
        
        elif response.status_code == 201:
            print("Resource created successfully")
            return response.json()
        
        elif response.status_code == 204:
            print("Resource deleted successfully")
            return None
        
        elif response.status_code == 400:
            error = response.json()
            print(f"Bad request: {error.get('message')}")
            return None
        
        elif response.status_code == 401:
            print("Authentication required")
            return None
        
        elif response.status_code == 403:
            print("Permission denied")
            return None
        
        elif response.status_code == 404:
            print("Resource not found")
            return None
        
        elif response.status_code == 409:
            print("Resource already exists")
            return None
        
        elif response.status_code == 422:
            error = response.json()
            print(f"Validation error: {error.get('errors')}")
            return None
        
        elif response.status_code == 429:
            retry_after = response.headers.get("Retry-After", 60)
            print(f"Rate limited. Retry after {retry_after} seconds")
            return None
        
        elif 500 <= response.status_code < 600:
            print("Server error. Please try again later")
            return None
        
        else:
            print(f"Unexpected status code: {response.status_code}")
            return None
    
    except requests.RequestException as e:
        print(f"Request failed: {e}")
        return None

# Usage
data = make_api_request("https://api.example.com/users/42")
```

### JavaScript Complete Example

```javascript
async function makeApiRequest(url, options = {}) {
  try {
    const response = await fetch(url, options);
    
    // 2xx Success
    if (response.ok) {
      if (response.status === 204) {
        console.log("Resource deleted successfully");
        return null;
      }
      return await response.json();
    }
    
    // 4xx Client Error
    if (response.status === 400) {
      const error = await response.json();
      console.error(`Bad request: ${error.message}`);
      return null;
    }
    
    if (response.status === 401) {
      console.error("Authentication required");
      return null;
    }
    
    if (response.status === 403) {
      console.error("Permission denied");
      return null;
    }
    
    if (response.status === 404) {
      console.error("Resource not found");
      return null;
    }
    
    if (response.status === 409) {
      console.error("Resource already exists");
      return null;
    }
    
    if (response.status === 422) {
      const error = await response.json();
      console.error("Validation error:", error.errors);
      return null;
    }
    
    if (response.status === 429) {
      const retryAfter = response.headers.get("Retry-After") || 60;
      console.error(`Rate limited. Retry after ${retryAfter} seconds`);
      return null;
    }
    
    // 5xx Server Error
    if (response.status >= 500) {
      console.error("Server error. Please try again later");
      return null;
    }
    
    console.error(`Unexpected status code: ${response.status}`);
    return null;
    
  } catch (error) {
    console.error("Request failed:", error);
    return null;
  }
}

// Usage
const data = await makeApiRequest("https://api.example.com/users/42");
```

---

## Best Practices

1. **Always check status codes**: Never assume success
2. **Handle errors gracefully**: Provide user-friendly messages
3. **Use appropriate codes**: Match the situation
4. **Return consistent error format**: Makes client-side handling easier
5. **Include error details**: Help clients understand what went wrong
6. **Log server errors**: For debugging and monitoring
7. **Respect rate limits**: Implement retry logic with backoff

---

## Summary

- **2xx**: Success
- **4xx**: Client error (check your request)
- **5xx**: Server error (not your fault)

Remember: Status codes are the first thing to check when debugging API issues.