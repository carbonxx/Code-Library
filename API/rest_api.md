# REST API

**REST (Representational State Transfer)** is an architectural style for designing networked applications.

## Table of Contents
- [What is REST?](#what-is-rest)
- [REST Principles](#rest-principles)
- [Resources and URIs](#resources-and-uris)
- [CRUD Operations](#crud-operations)
- [REST Constraints](#rest-constraints)
- [Best Practices](#best-practices)
- [API Design Examples](#api-design-examples)

---

## What is REST?

REST is an architectural style that defines a set of constraints for creating web services. A RESTful API:
- Uses HTTP methods explicitly
- Is stateless
- Exposes directory structure-like URIs
- Transfers data in JSON or XML

### Key Characteristics

- **Client-Server**: Separation of concerns
- **Stateless**: Each request is independent
- **Cacheable**: Responses can be cached
- **Uniform Interface**: Consistent resource access
- **Layered System**: Client doesn't know if it's connected to the end server

---

## REST Principles

### 1. Resource-Based

Everything is a **resource** with a unique identifier (URI).

```
Resources (nouns):
- User: /users
- Product: /products
- Order: /orders

Not actions (verbs):
❌ /getUsers
❌ /createUser
❌ /deleteProduct
```

### 2. HTTP Methods for Actions

Use HTTP methods to perform operations:

| Operation | HTTP Method | Example |
|-----------|-------------|---------|
| Create | POST | POST /users |
| Read | GET | GET /users/42 |
| Update | PUT/PATCH | PUT /users/42 |
| Delete | DELETE | DELETE /users/42 |

### 3. Representations

Resources can have multiple representations (JSON, XML, HTML).

```json
// JSON representation
{
  "id": 42,
  "name": "John Doe",
  "email": "john@example.com"
}
```

### 4. Stateless Communication

Each request must contain all information needed to understand it.

```python
# Bad: Relies on server-side session state
GET /next-page

# Good: Request contains all necessary information
GET /users?page=2&limit=20
```

---

## Resources and URIs

### URI Structure

```
https://api.example.com/v1/users/42/orders/123

Protocol: https
Domain: api.example.com
Version: v1
Resource: users
ID: 42
Sub-resource: orders
Sub-ID: 123
```

### URI Best Practices

**Use Nouns (not verbs)**
```
✅ GET /users
❌ GET /getUsers

✅ POST /orders
❌ POST /createOrder
```

**Use Plural Names**
```
✅ /users
❌ /user

✅ /products
❌ /product
```

**Use Hierarchies for Relationships**
```
✅ /users/42/orders        # All orders for user 42
✅ /users/42/orders/123    # Specific order for user 42
```

**Use Hyphens (not underscores)**
```
✅ /user-profiles
❌ /user_profiles
```

**Use Lowercase**
```
✅ /users
❌ /Users
❌ /USERS
```

---

## CRUD Operations

REST maps CRUD operations to HTTP methods.

### Create (POST)

Create a new resource.

```python
import requests

new_user = {
    "name": "John Doe",
    "email": "john@example.com"
}

response = requests.post(
    "https://api.example.com/users",
    json=new_user
)

# Response: 201 Created
# Location: /users/42
```

**Endpoint Pattern**
```
POST /users
POST /products
POST /orders
```

---

### Read (GET)

Retrieve resource(s).

**Get Collection**
```python
import requests

# Get all users
response = requests.get("https://api.example.com/users")
users = response.json()
```

**Get Single Resource**
```python
# Get specific user
response = requests.get("https://api.example.com/users/42")
user = response.json()
```

**Endpoint Patterns**
```
GET /users              # List all users
GET /users/42           # Get user 42
GET /users/42/orders    # Get orders for user 42
```

---

### Update (PUT / PATCH)

**PUT: Replace entire resource**
```python
import requests

updated_user = {
    "name": "John Doe",
    "email": "john.new@example.com",
    "age": 31
}

response = requests.put(
    "https://api.example.com/users/42",
    json=updated_user
)
```

**PATCH: Update specific fields**
```python
import requests

partial_update = {
    "email": "john.new@example.com"
}

response = requests.patch(
    "https://api.example.com/users/42",
    json=partial_update
)
```

**Endpoint Patterns**
```
PUT /users/42       # Replace user 42
PATCH /users/42     # Update user 42 partially
```

---

### Delete (DELETE)

Remove a resource.

```python
import requests

response = requests.delete("https://api.example.com/users/42")

# Response: 204 No Content
```

**Endpoint Pattern**
```
DELETE /users/42
DELETE /products/99
DELETE /orders/123
```

---

## REST Constraints

### 1. Stateless

**Server doesn't store client context between requests.**

Each request must contain:
- Authentication credentials
- Session information
- All necessary data

```python
# Every request includes auth token
headers = {"Authorization": "Bearer token123"}

requests.get("https://api.example.com/users", headers=headers)
requests.get("https://api.example.com/products", headers=headers)
```

### 2. Client-Server

**Separation of concerns.**

- **Client**: User interface and experience
- **Server**: Data storage and business logic

This allows them to evolve independently.

### 3. Cacheable

**Responses must define themselves as cacheable or not.**

```
HTTP/1.1 200 OK
Cache-Control: max-age=3600
Content-Type: application/json

{
  "id": 42,
  "name": "John Doe"
}
```

### 4. Uniform Interface

**Consistent way to interact with resources.**

- Identify resources via URIs
- Manipulate resources via representations
- Self-descriptive messages
- HATEOAS (optional)

### 5. Layered System

**Client can't tell if connected directly to end server.**

```
[Client] → [Load Balancer] → [API Gateway] → [Server] → [Database]
```

Client doesn't know about intermediate layers.

---

## Best Practices

### 1. Versioning

**Include API version in URL or header.**

```
✅ /v1/users
✅ /v2/users

Header: Accept: application/vnd.api.v1+json
```

### 2. Filtering, Sorting, Pagination

**Use query parameters.**

```python
import requests

# Filtering
params = {
    "status": "active",
    "age": "25"
}
response = requests.get("https://api.example.com/users", params=params)

# Sorting
params = {
    "sort": "name",
    "order": "asc"
}
response = requests.get("https://api.example.com/users", params=params)

# Pagination
params = {
    "page": 2,
    "limit": 20
}
response = requests.get("https://api.example.com/users", params=params)
```

**URL Examples**
```
/users?status=active&age=25
/users?sort=name&order=asc
/users?page=2&limit=20
```

### 3. Use HTTP Status Codes Correctly

```python
# Create
return 201 Created

# Success
return 200 OK

# No content (delete)
return 204 No Content

# Not found
return 404 Not Found

# Validation error
return 422 Unprocessable Entity
```

### 4. Consistent Error Format

```json
{
  "status": "error",
  "code": 422,
  "message": "Validation failed",
  "errors": [
    {
      "field": "email",
      "message": "Email is already taken"
    }
  ]
}
```

### 5. Use Nouns, Not Verbs

```
✅ GET /users/42
❌ GET /getUser/42

✅ POST /users
❌ POST /createUser

✅ DELETE /users/42
❌ DELETE /deleteUser/42
```

### 6. Relationships

**Use sub-resources for relationships.**

```
/users/42/orders          # Orders belonging to user 42
/users/42/orders/123      # Specific order for user 42
/products/99/reviews      # Reviews for product 99
```

### 7. Rate Limiting

**Include rate limit info in headers.**

```
HTTP/1.1 200 OK
X-RateLimit-Limit: 1000
X-RateLimit-Remaining: 999
X-RateLimit-Reset: 1633072800
```

---

## API Design Examples

### User Management API

```python
# Create user
POST /v1/users
{
  "name": "John Doe",
  "email": "john@example.com"
}
→ 201 Created, Location: /v1/users/42

# Get all users
GET /v1/users
→ 200 OK

# Get specific user
GET /v1/users/42
→ 200 OK

# Update user
PUT /v1/users/42
{
  "name": "John Doe",
  "email": "john.new@example.com"
}
→ 200 OK

# Partial update
PATCH /v1/users/42
{
  "email": "john.new@example.com"
}
→ 200 OK

# Delete user
DELETE /v1/users/42
→ 204 No Content

# Search users
GET /v1/users?search=john&status=active
→ 200 OK

# Paginate users
GET /v1/users?page=2&limit=20
→ 200 OK
```

### E-commerce API

```python
# Products
GET /v1/products                    # List products
GET /v1/products/99                 # Get product
GET /v1/products?category=electronics&price_max=1000
POST /v1/products                   # Create product
PUT /v1/products/99                 # Update product
DELETE /v1/products/99              # Delete product

# Product reviews
GET /v1/products/99/reviews         # Get reviews for product
POST /v1/products/99/reviews        # Add review
DELETE /v1/products/99/reviews/5    # Delete review

# Orders
GET /v1/orders                      # List orders
GET /v1/orders/123                  # Get order
POST /v1/orders                     # Create order
PUT /v1/orders/123                  # Update order

# User orders
GET /v1/users/42/orders             # Orders for user 42
GET /v1/users/42/orders/123         # Specific order

# Shopping cart
GET /v1/users/42/cart               # Get cart
POST /v1/users/42/cart/items        # Add item
DELETE /v1/users/42/cart/items/7    # Remove item
```

### Complete Python Example

```python
import requests

BASE_URL = "https://api.example.com/v1"
headers = {"Authorization": "Bearer token123"}

# Create user
new_user = {
    "name": "John Doe",
    "email": "john@example.com",
    "age": 30
}

response = requests.post(
    f"{BASE_URL}/users",
    json=new_user,
    headers=headers
)

if response.status_code == 201:
    user = response.json()
    user_id = user["id"]
    print(f"Created user: {user_id}")
    
    # Get user
    response = requests.get(
        f"{BASE_URL}/users/{user_id}",
        headers=headers
    )
    print(response.json())
    
    # Update user
    update = {"email": "john.new@example.com"}
    response = requests.patch(
        f"{BASE_URL}/users/{user_id}",
        json=update,
        headers=headers
    )
    print(response.json())
    
    # Get user's orders
    response = requests.get(
        f"{BASE_URL}/users/{user_id}/orders",
        headers=headers
    )
    print(response.json())
    
    # Delete user
    response = requests.delete(
        f"{BASE_URL}/users/{user_id}",
        headers=headers
    )
    
    if response.status_code == 204:
        print("User deleted")
```

### Complete JavaScript Example

```javascript
const BASE_URL = "https://api.example.com/v1";
const headers = {
  "Authorization": "Bearer token123",
  "Content-Type": "application/json"
};

async function userWorkflow() {
  try {
    // Create user
    const newUser = {
      name: "John Doe",
      email: "john@example.com",
      age: 30
    };
    
    let response = await fetch(`${BASE_URL}/users`, {
      method: "POST",
      headers: headers,
      body: JSON.stringify(newUser)
    });
    
    const user = await response.json();
    const userId = user.id;
    console.log(`Created user: ${userId}`);
    
    // Get user
    response = await fetch(`${BASE_URL}/users/${userId}`, {
      headers: headers
    });
    console.log(await response.json());
    
    // Update user
    response = await fetch(`${BASE_URL}/users/${userId}`, {
      method: "PATCH",
      headers: headers,
      body: JSON.stringify({ email: "john.new@example.com" })
    });
    console.log(await response.json());
    
    // Get user's orders
    response = await fetch(`${BASE_URL}/users/${userId}/orders`, {
      headers: headers
    });
    console.log(await response.json());
    
    // Delete user
    response = await fetch(`${BASE_URL}/users/${userId}`, {
      method: "DELETE",
      headers: headers
    });
    
    if (response.status === 204) {
      console.log("User deleted");
    }
    
  } catch (error) {
    console.error("Error:", error);
  }
}

userWorkflow();
```

---

## REST vs GraphQL vs SOAP

| Feature | REST | GraphQL | SOAP |
|---------|------|---------|------|
| Data Format | JSON, XML | JSON | XML |
| Over/Under Fetching | Yes | No | Yes |
| Versioning | URL/Header | Schema evolution | WSDL versions |
| Caching | HTTP caching | Complex | Limited |
| Learning Curve | Easy | Medium | Steep |

---

## Summary

**REST Key Points:**
- Resource-based (nouns, not verbs)
- Use HTTP methods correctly
- Stateless communication
- Use standard status codes
- Version your API
- Keep URIs simple and hierarchical
- Support filtering, sorting, pagination

**When to use REST:**
- Public APIs
- Simple CRUD operations
- Caching is important
- Standard HTTP clients
- Wide compatibility needed