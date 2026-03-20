# Request and Response

Every API interaction consists of a **request** sent by the client and a **response** returned by the server.

## Table of Contents
- [Request Structure](#request-structure)
- [Response Structure](#response-structure)
- [Headers](#headers)
- [Request Body](#request-body)
- [Response Body](#response-body)
- [Query Parameters](#query-parameters)
- [Complete Examples](#complete-examples)

---

## Request Structure

An HTTP request consists of:

```
[METHOD] [URL] HTTP/[VERSION]
[HEADERS]

[BODY]
```

### Components

1. **Method**: HTTP verb (GET, POST, PUT, DELETE, etc.)
2. **URL**: Endpoint to access
3. **Headers**: Metadata about the request
4. **Body**: Data being sent (for POST, PUT, PATCH)

### Example Request
```
POST /api/users HTTP/1.1
Host: api.example.com
Content-Type: application/json
Authorization: Bearer abc123xyz
User-Agent: MyApp/1.0

{
  "name": "John Doe",
  "email": "john@example.com"
}
```

---

## Response Structure

An HTTP response consists of:

```
HTTP/[VERSION] [STATUS CODE] [STATUS MESSAGE]
[HEADERS]

[BODY]
```

### Components

1. **Status Code**: Indicates success or failure
2. **Headers**: Metadata about the response
3. **Body**: Data returned from the server

### Example Response
```
HTTP/1.1 201 Created
Content-Type: application/json
Content-Length: 123
Date: Fri, 14 Feb 2026 10:00:00 GMT

{
  "id": 42,
  "name": "John Doe",
  "email": "john@example.com",
  "created_at": "2026-02-14T10:00:00Z"
}
```

---

## Headers

Headers provide additional information about the request or response.

### Common Request Headers

| Header | Purpose | Example |
|--------|---------|---------|
| **Content-Type** | Format of request body | `application/json` |
| **Authorization** | Authentication credentials | `Bearer token123` |
| **Accept** | Desired response format | `application/json` |
| **User-Agent** | Client application info | `Mozilla/5.0` |
| **Cookie** | Session information | `session_id=xyz` |

### Common Response Headers

| Header | Purpose | Example |
|--------|---------|---------|
| **Content-Type** | Format of response body | `application/json` |
| **Content-Length** | Size of response body | `1234` |
| **Cache-Control** | Caching directives | `max-age=3600` |
| **Set-Cookie** | Set client cookie | `token=abc; HttpOnly` |
| **Location** | URL of created resource | `/api/users/42` |

### Examples

**Python - Setting Headers**
```python
import requests

headers = {
    "Content-Type": "application/json",
    "Authorization": "Bearer abc123xyz",
    "User-Agent": "MyApp/1.0"
}

response = requests.get(
    "https://api.example.com/users",
    headers=headers
)

print(response.headers)  # View response headers
```

**JavaScript - Setting Headers**
```javascript
fetch("https://api.example.com/users", {
  method: "POST",
  headers: {
    "Content-Type": "application/json",
    "Authorization": "Bearer abc123xyz",
    "User-Agent": "MyApp/1.0"
  },
  body: JSON.stringify({ name: "John" })
})
  .then(res => {
    console.log(res.headers.get("Content-Type"));
    return res.json();
  });
```

---

## Request Body

The request body contains data being sent to the server (for POST, PUT, PATCH).

### JSON Format (Most Common)

```json
{
  "name": "John Doe",
  "email": "john@example.com",
  "age": 30
}
```

**Python**
```python
import requests

data = {
    "name": "John Doe",
    "email": "john@example.com",
    "age": 30
}

response = requests.post(
    "https://api.example.com/users",
    json=data  # Automatically sets Content-Type to application/json
)
```

**JavaScript**
```javascript
const data = {
  name: "John Doe",
  email: "john@example.com",
  age: 30
};

fetch("https://api.example.com/users", {
  method: "POST",
  headers: {
    "Content-Type": "application/json"
  },
  body: JSON.stringify(data)
});
```

### Form Data

```
name=John+Doe&email=john@example.com&age=30
```

**Python**
```python
import requests

data = {
    "name": "John Doe",
    "email": "john@example.com",
    "age": 30
}

response = requests.post(
    "https://api.example.com/users",
    data=data  # Sends as form data
)
```

### File Upload

**Python**
```python
import requests

files = {
    "file": open("profile.jpg", "rb")
}

data = {
    "name": "John Doe"
}

response = requests.post(
    "https://api.example.com/upload",
    files=files,
    data=data
)
```

**JavaScript**
```javascript
const formData = new FormData();
formData.append("file", fileInput.files[0]);
formData.append("name", "John Doe");

fetch("https://api.example.com/upload", {
  method: "POST",
  body: formData  // Don't set Content-Type, browser sets it automatically
});
```

---

## Response Body

The response body contains data returned from the server.

### JSON Response (Most Common)

```json
{
  "status": "success",
  "data": {
    "id": 42,
    "name": "John Doe",
    "email": "john@example.com"
  }
}
```

**Python - Parsing Response**
```python
import requests

response = requests.get("https://api.example.com/users/42")

# Parse JSON
data = response.json()
print(data["name"])  # John Doe

# Access raw text
print(response.text)

# Access raw bytes
print(response.content)
```

**JavaScript - Parsing Response**
```javascript
fetch("https://api.example.com/users/42")
  .then(res => res.json())  // Parse JSON
  .then(data => {
    console.log(data.name);  // John Doe
  });

// Alternative with async/await
async function getUser() {
  const response = await fetch("https://api.example.com/users/42");
  const data = await response.json();
  console.log(data.name);
}
```

### Error Response

```json
{
  "status": "error",
  "message": "User not found",
  "code": 404,
  "details": {
    "user_id": 42
  }
}
```

**Python - Handling Errors**
```python
import requests

response = requests.get("https://api.example.com/users/999")

if response.status_code == 200:
    data = response.json()
    print(data)
else:
    error = response.json()
    print(f"Error: {error['message']}")
```

**JavaScript - Handling Errors**
```javascript
fetch("https://api.example.com/users/999")
  .then(res => {
    if (!res.ok) {
      throw new Error(`HTTP error! status: ${res.status}`);
    }
    return res.json();
  })
  .then(data => console.log(data))
  .catch(error => console.error("Error:", error));
```

---

## Query Parameters

Query parameters add additional information to GET requests via the URL.

### Syntax
```
https://api.example.com/users?age=25&city=Mumbai&sort=name
```

### Structure
- Start with `?`
- Key-value pairs: `key=value`
- Multiple parameters separated by `&`
- Values should be URL-encoded

### Examples

**Python**
```python
import requests

# Method 1: String concatenation
response = requests.get("https://api.example.com/users?age=25&city=Mumbai")

# Method 2: Using params (recommended)
params = {
    "age": 25,
    "city": "Mumbai",
    "sort": "name"
}

response = requests.get(
    "https://api.example.com/users",
    params=params
)

print(response.url)  # Shows full URL with encoded parameters
```

**JavaScript**
```javascript
// Method 1: String concatenation
fetch("https://api.example.com/users?age=25&city=Mumbai")
  .then(res => res.json());

// Method 2: Using URLSearchParams
const params = new URLSearchParams({
  age: 25,
  city: "Mumbai",
  sort: "name"
});

fetch(`https://api.example.com/users?${params}`)
  .then(res => res.json());
```

### Common Use Cases

**Filtering**
```
/api/products?category=electronics&price_max=1000
```

**Pagination**
```
/api/users?page=2&limit=20
```

**Sorting**
```
/api/posts?sort=created_at&order=desc
```

**Searching**
```
/api/search?q=laptop&type=product
```

---

## Complete Examples

### GET Request Example

**Python**
```python
import requests

response = requests.get(
    "https://api.example.com/users/42",
    headers={
        "Authorization": "Bearer token123",
        "Accept": "application/json"
    }
)

if response.status_code == 200:
    user = response.json()
    print(f"User: {user['name']}")
    print(f"Email: {user['email']}")
else:
    print(f"Error: {response.status_code}")
```

**JavaScript**
```javascript
fetch("https://api.example.com/users/42", {
  method: "GET",
  headers: {
    "Authorization": "Bearer token123",
    "Accept": "application/json"
  }
})
  .then(res => {
    if (!res.ok) {
      throw new Error(`HTTP error! status: ${res.status}`);
    }
    return res.json();
  })
  .then(user => {
    console.log(`User: ${user.name}`);
    console.log(`Email: ${user.email}`);
  })
  .catch(error => console.error("Error:", error));
```

### POST Request Example

**Python**
```python
import requests

new_user = {
    "name": "John Doe",
    "email": "john@example.com",
    "age": 30
}

response = requests.post(
    "https://api.example.com/users",
    json=new_user,
    headers={
        "Authorization": "Bearer token123",
        "Content-Type": "application/json"
    }
)

if response.status_code == 201:
    created_user = response.json()
    print(f"Created user with ID: {created_user['id']}")
else:
    error = response.json()
    print(f"Error: {error['message']}")
```

**JavaScript**
```javascript
const newUser = {
  name: "John Doe",
  email: "john@example.com",
  age: 30
};

fetch("https://api.example.com/users", {
  method: "POST",
  headers: {
    "Authorization": "Bearer token123",
    "Content-Type": "application/json"
  },
  body: JSON.stringify(newUser)
})
  .then(res => {
    if (res.status === 201) {
      return res.json();
    } else {
      throw new Error(`HTTP error! status: ${res.status}`);
    }
  })
  .then(createdUser => {
    console.log(`Created user with ID: ${createdUser.id}`);
  })
  .catch(error => console.error("Error:", error));
```

### PUT Request Example

**Python**
```python
import requests

updated_user = {
    "name": "John Doe",
    "email": "john.doe@example.com",
    "age": 31
}

response = requests.put(
    "https://api.example.com/users/42",
    json=updated_user,
    headers={
        "Authorization": "Bearer token123"
    }
)

if response.status_code == 200:
    print("User updated successfully")
    print(response.json())
```

**JavaScript**
```javascript
const updatedUser = {
  name: "John Doe",
  email: "john.doe@example.com",
  age: 31
};

fetch("https://api.example.com/users/42", {
  method: "PUT",
  headers: {
    "Authorization": "Bearer token123",
    "Content-Type": "application/json"
  },
  body: JSON.stringify(updatedUser)
})
  .then(res => res.json())
  .then(data => {
    console.log("User updated successfully");
    console.log(data);
  });
```

### DELETE Request Example

**Python**
```python
import requests

response = requests.delete(
    "https://api.example.com/users/42",
    headers={
        "Authorization": "Bearer token123"
    }
)

if response.status_code == 204:
    print("User deleted successfully")
elif response.status_code == 404:
    print("User not found")
```

**JavaScript**
```javascript
fetch("https://api.example.com/users/42", {
  method: "DELETE",
  headers: {
    "Authorization": "Bearer token123"
  }
})
  .then(res => {
    if (res.status === 204) {
      console.log("User deleted successfully");
    } else if (res.status === 404) {
      console.log("User not found");
    }
  });
```

---

## Best Practices

1. **Always check status codes**: Don't assume success
2. **Handle errors gracefully**: Provide meaningful error messages
3. **Use appropriate Content-Type**: Match your request body format
4. **Include authentication**: Most APIs require authorization
5. **Parse JSON safely**: Check response format before parsing
6. **Set timeouts**: Prevent requests from hanging indefinitely
7. **Log requests**: Helps with debugging

### Python Timeout Example
```python
import requests

try:
    response = requests.get(
        "https://api.example.com/users",
        timeout=5  # 5 seconds timeout
    )
except requests.Timeout:
    print("Request timed out")
```

### JavaScript Timeout Example
```javascript
const controller = new AbortController();
const timeoutId = setTimeout(() => controller.abort(), 5000);

fetch("https://api.example.com/users", {
  signal: controller.signal
})
  .then(res => res.json())
  .catch(error => {
    if (error.name === 'AbortError') {
      console.log('Request timed out');
    }
  })
  .finally(() => clearTimeout(timeoutId));
```

---

## Summary

- **Request**: Method + URL + Headers + Body
- **Response**: Status Code + Headers + Body
- **Headers**: Provide metadata
- **Body**: Contains actual data (JSON most common)
- **Query Parameters**: Add filters/options to GET requests
- **Always handle errors**: Check status codes and parse errors