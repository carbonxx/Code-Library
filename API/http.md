# HTTP Methods

HTTP methods (also called HTTP verbs) define the type of operation to perform on a resource.

## Table of Contents
- [Overview](#overview)
- [GET](#get)
- [POST](#post)
- [PUT](#put)
- [PATCH](#patch)
- [DELETE](#delete)
- [HEAD](#head)
- [OPTIONS](#options)
- [Method Comparison](#method-comparison)

---

## Overview

HTTP methods indicate the desired action to be performed on a resource. The most commonly used methods are:

| Method | Purpose | Safe | Idempotent |
|--------|---------|------|------------|
| GET | Retrieve data | Yes | Yes |
| POST | Create new resource | No | No |
| PUT | Update/Replace resource | No | Yes |
| PATCH | Partial update | No | No |
| DELETE | Remove resource | No | Yes |

**Safe**: Method doesn't modify data  
**Idempotent**: Multiple identical requests have the same effect as one request

---

## GET

**Purpose**: Retrieve data from the server

### Characteristics
- **Read-only operation**
- Data sent via URL (query parameters)
- Can be cached
- Can be bookmarked
- Should not modify server state

### Syntax
```
GET /api/users HTTP/1.1
Host: example.com
```

### Examples

**Python**
```python
import requests

# Get all users
response = requests.get("https://api.example.com/users")
print(response.json())

# Get specific user
response = requests.get("https://api.example.com/users/123")
print(response.json())

# Get with query parameters
params = {"age": 25, "city": "Mumbai"}
response = requests.get("https://api.example.com/users", params=params)
print(response.json())
```

**JavaScript**
```javascript
// Get all users
fetch("https://api.example.com/users")
  .then(res => res.json())
  .then(data => console.log(data));

// Get specific user
fetch("https://api.example.com/users/123")
  .then(res => res.json())
  .then(data => console.log(data));

// Get with query parameters
fetch("https://api.example.com/users?age=25&city=Mumbai")
  .then(res => res.json())
  .then(data => console.log(data));
```

**cURL**
```bash
# Get all users
curl https://api.example.com/users

# Get specific user
curl https://api.example.com/users/123

# Get with query parameters
curl "https://api.example.com/users?age=25&city=Mumbai"
```

### Use Cases
- Fetching a list of items
- Retrieving a single resource
- Searching with filters
- Reading configuration data

---

## POST

**Purpose**: Create a new resource or submit data

### Characteristics
- **Creates new data**
- Data sent in request body
- Not idempotent (multiple requests create multiple resources)
- Not cacheable
- Cannot be bookmarked

### Syntax
```
POST /api/users HTTP/1.1
Host: example.com
Content-Type: application/json

{
  "name": "John Doe",
  "email": "john@example.com"
}
```

### Examples

**Python**
```python
import requests

# Create new user
new_user = {
    "name": "John Doe",
    "email": "john@example.com",
    "age": 30
}

response = requests.post(
    "https://api.example.com/users",
    json=new_user
)

print(response.status_code)  # 201 Created
print(response.json())
```

**JavaScript**
```javascript
// Create new user
const newUser = {
  name: "John Doe",
  email: "john@example.com",
  age: 30
};

fetch("https://api.example.com/users", {
  method: "POST",
  headers: {
    "Content-Type": "application/json"
  },
  body: JSON.stringify(newUser)
})
  .then(res => res.json())
  .then(data => console.log(data));
```

**cURL**
```bash
curl -X POST https://api.example.com/users \
  -H "Content-Type: application/json" \
  -d '{
    "name": "John Doe",
    "email": "john@example.com",
    "age": 30
  }'
```

### Use Cases
- Creating a new user account
- Submitting a form
- Uploading a file
- Adding an item to a cart

---

## PUT

**Purpose**: Update or replace an entire resource

### Characteristics
- **Replaces entire resource**
- Idempotent (multiple identical requests have same effect)
- Requires sending complete resource data
- Creates resource if it doesn't exist (sometimes)

### Syntax
```
PUT /api/users/123 HTTP/1.1
Host: example.com
Content-Type: application/json

{
  "name": "John Doe",
  "email": "john.doe@example.com",
  "age": 31
}
```

### Examples

**Python**
```python
import requests

# Update entire user resource
updated_user = {
    "name": "John Doe",
    "email": "john.doe@example.com",
    "age": 31,
    "city": "Mumbai"
}

response = requests.put(
    "https://api.example.com/users/123",
    json=updated_user
)

print(response.status_code)  # 200 OK
print(response.json())
```

**JavaScript**
```javascript
// Update entire user resource
const updatedUser = {
  name: "John Doe",
  email: "john.doe@example.com",
  age: 31,
  city: "Mumbai"
};

fetch("https://api.example.com/users/123", {
  method: "PUT",
  headers: {
    "Content-Type": "application/json"
  },
  body: JSON.stringify(updatedUser)
})
  .then(res => res.json())
  .then(data => console.log(data));
```

**cURL**
```bash
curl -X PUT https://api.example.com/users/123 \
  -H "Content-Type: application/json" \
  -d '{
    "name": "John Doe",
    "email": "john.doe@example.com",
    "age": 31,
    "city": "Mumbai"
  }'
```

### Use Cases
- Replacing user profile completely
- Updating configuration settings
- Overwriting a document

---

## PATCH

**Purpose**: Partially update a resource

### Characteristics
- **Updates specific fields only**
- More efficient than PUT for small changes
- Not necessarily idempotent
- Requires only changed fields

### Syntax
```
PATCH /api/users/123 HTTP/1.1
Host: example.com
Content-Type: application/json

{
  "email": "newemail@example.com"
}
```

### Examples

**Python**
```python
import requests

# Update only email field
partial_update = {
    "email": "newemail@example.com"
}

response = requests.patch(
    "https://api.example.com/users/123",
    json=partial_update
)

print(response.status_code)  # 200 OK
print(response.json())
```

**JavaScript**
```javascript
// Update only email field
const partialUpdate = {
  email: "newemail@example.com"
};

fetch("https://api.example.com/users/123", {
  method: "PATCH",
  headers: {
    "Content-Type": "application/json"
  },
  body: JSON.stringify(partialUpdate)
})
  .then(res => res.json())
  .then(data => console.log(data));
```

**cURL**
```bash
curl -X PATCH https://api.example.com/users/123 \
  -H "Content-Type: application/json" \
  -d '{
    "email": "newemail@example.com"
  }'
```

### Use Cases
- Updating a single field (email, password)
- Marking item as complete
- Incrementing a counter

---

## DELETE

**Purpose**: Remove a resource from the server

### Characteristics
- **Deletes data**
- Idempotent (deleting same resource multiple times has same effect)
- Usually returns 204 No Content or 200 OK
- No request body needed

### Syntax
```
DELETE /api/users/123 HTTP/1.1
Host: example.com
```

### Examples

**Python**
```python
import requests

# Delete user
response = requests.delete("https://api.example.com/users/123")

print(response.status_code)  # 204 No Content or 200 OK
```

**JavaScript**
```javascript
// Delete user
fetch("https://api.example.com/users/123", {
  method: "DELETE"
})
  .then(res => {
    if (res.status === 204) {
      console.log("User deleted successfully");
    }
  });
```

**cURL**
```bash
curl -X DELETE https://api.example.com/users/123
```

### Use Cases
- Deleting a user account
- Removing an item from cart
- Canceling a subscription

---

## HEAD

**Purpose**: Same as GET, but only retrieves headers (no body)

### Use Cases
- Checking if resource exists
- Getting metadata (content length, last modified)
- Verifying link validity

### Example
```bash
curl -I https://api.example.com/users/123
```

---

## OPTIONS

**Purpose**: Describes communication options for the target resource

### Use Cases
- CORS preflight requests
- Discovering allowed methods
- Checking API capabilities

### Example
```bash
curl -X OPTIONS https://api.example.com/users
```

---

## Method Comparison

### PUT vs PATCH

| Aspect | PUT | PATCH |
|--------|-----|-------|
| Update Type | Full replacement | Partial update |
| Fields Required | All fields | Only changed fields |
| Idempotent | Yes | Not guaranteed |
| Bandwidth | More data sent | Less data sent |

**Example Scenario**: Updating user email

**PUT** (must send all fields)
```json
{
  "name": "John Doe",
  "email": "newemail@example.com",
  "age": 30,
  "city": "Mumbai"
}
```

**PATCH** (send only changed field)
```json
{
  "email": "newemail@example.com"
}
```

### POST vs PUT

| Aspect | POST | PUT |
|--------|------|-----|
| Purpose | Create new | Update existing |
| Idempotent | No | Yes |
| Resource ID | Server generates | Client provides |
| Use Case | Unknown ID | Known ID |

---

## Best Practices

1. **Use the correct method**: Don't use POST for everything
2. **Follow REST conventions**: Use methods as intended
3. **Be idempotent when possible**: Makes APIs more reliable
4. **Use PATCH for small updates**: More efficient than PUT
5. **Return appropriate status codes**: 201 for POST, 204 for DELETE
6. **Don't use GET to modify data**: Breaks expectations and caching

---

## Summary

- **GET**: Read data
- **POST**: Create new
- **PUT**: Replace entire resource
- **PATCH**: Update specific fields
- **DELETE**: Remove resource

Choose the method that best matches your operation's intent.