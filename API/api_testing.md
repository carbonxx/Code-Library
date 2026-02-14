# API Testing

Testing ensures your API works correctly, handles errors properly, and meets requirements.

## Table of Contents
- [Why Test APIs?](#why-test-apis)
- [Types of API Tests](#types-of-api-tests)
- [Testing Tools](#testing-tools)
- [Postman](#postman)
- [cURL](#curl)
- [Python Testing](#python-testing)
- [JavaScript Testing](#javascript-testing)
- [Best Practices](#best-practices)

---

## Why Test APIs?

API testing verifies:
- **Functionality**: Does it work as expected?
- **Reliability**: Does it handle errors gracefully?
- **Performance**: Is it fast enough?
- **Security**: Is data protected?
- **Integration**: Do components work together?

### Benefits
- Find bugs early
- Ensure quality
- Document API behavior
- Enable refactoring with confidence
- Prevent regression

---

## Types of API Tests

### 1. Unit Tests

Test individual functions or endpoints in isolation.

```python
def test_get_user():
    response = get_user(user_id=42)
    assert response.status_code == 200
    assert response.json()["id"] == 42
```

### 2. Integration Tests

Test how multiple components work together.

```python
def test_create_and_retrieve_user():
    # Create user
    response = create_user({"name": "John"})
    user_id = response.json()["id"]
    
    # Retrieve user
    response = get_user(user_id)
    assert response.json()["name"] == "John"
```

### 3. Functional Tests

Test complete workflows from the user's perspective.

```python
def test_user_registration_flow():
    # 1. Register
    # 2. Verify email
    # 3. Login
    # 4. Access protected resource
```

### 4. Load Tests

Test API performance under heavy load.

```python
# Simulate 1000 concurrent users
for i in range(1000):
    make_request()
```

### 5. Security Tests

Test for vulnerabilities.

```python
def test_authentication_required():
    response = requests.get("/api/users")
    assert response.status_code == 401
```

---

## Testing Tools

### Overview

| Tool | Type | Best For |
|------|------|----------|
| **Postman** | GUI | Manual testing, exploration |
| **cURL** | CLI | Quick tests, scripts |
| **pytest** | Framework | Python automated tests |
| **Jest** | Framework | JavaScript automated tests |
| **Thunder Client** | VS Code | Testing within editor |
| **Insomnia** | GUI | API design and testing |
| **JMeter** | Load testing | Performance testing |

---

## Postman

Popular GUI tool for API testing.

### Basic Usage

**1. Create Request**
```
Method: GET
URL: https://api.example.com/users/42
Headers:
  Authorization: Bearer token123
```

**2. Send Request**

Click "Send" button

**3. View Response**
```json
{
  "id": 42,
  "name": "John Doe",
  "email": "john@example.com"
}
```

### Collections

Group related requests together.

```
User API Collection
├── Create User (POST /users)
├── Get User (GET /users/:id)
├── Update User (PUT /users/:id)
└── Delete User (DELETE /users/:id)
```

### Environment Variables

Store reusable values.

```
{{base_url}} = https://api.example.com
{{api_key}} = abc123xyz789

Usage: {{base_url}}/users
```

### Tests in Postman

**JavaScript snippets to validate responses:**

```javascript
// Test status code
pm.test("Status code is 200", function () {
    pm.response.to.have.status(200);
});

// Test response time
pm.test("Response time is less than 200ms", function () {
    pm.expect(pm.response.responseTime).to.be.below(200);
});

// Test response body
pm.test("User has correct name", function () {
    var jsonData = pm.response.json();
    pm.expect(jsonData.name).to.eql("John Doe");
});

// Test header
pm.test("Content-Type is JSON", function () {
    pm.response.to.have.header("Content-Type", "application/json");
});

// Save response data to variable
pm.environment.set("user_id", pm.response.json().id);
```

### Pre-request Scripts

Run code before sending request.

```javascript
// Generate timestamp
pm.environment.set("timestamp", new Date().toISOString());

// Create signature
const signature = CryptoJS.SHA256(pm.request.url).toString();
pm.environment.set("signature", signature);
```

---

## cURL

Command-line tool for making HTTP requests.

### Basic Syntax

```bash
curl [options] [URL]
```

### GET Request

```bash
# Simple GET
curl https://api.example.com/users

# With headers
curl -H "Authorization: Bearer token123" \
     https://api.example.com/users

# Pretty print JSON
curl https://api.example.com/users | jq

# Save to file
curl https://api.example.com/users -o users.json

# Include response headers
curl -i https://api.example.com/users

# Verbose output
curl -v https://api.example.com/users
```

### POST Request

```bash
# JSON data
curl -X POST https://api.example.com/users \
  -H "Content-Type: application/json" \
  -d '{
    "name": "John Doe",
    "email": "john@example.com"
  }'

# From file
curl -X POST https://api.example.com/users \
  -H "Content-Type: application/json" \
  -d @user.json

# Form data
curl -X POST https://api.example.com/users \
  -d "name=John Doe" \
  -d "email=john@example.com"
```

### PUT Request

```bash
curl -X PUT https://api.example.com/users/42 \
  -H "Content-Type: application/json" \
  -H "Authorization: Bearer token123" \
  -d '{
    "name": "John Doe",
    "email": "john.new@example.com"
  }'
```

### DELETE Request

```bash
curl -X DELETE https://api.example.com/users/42 \
  -H "Authorization: Bearer token123"
```

### Authentication

```bash
# Bearer token
curl -H "Authorization: Bearer token123" \
     https://api.example.com/users

# API key
curl -H "X-API-Key: abc123xyz789" \
     https://api.example.com/users

# Basic auth
curl -u username:password \
     https://api.example.com/users

# Or
curl -H "Authorization: Basic $(echo -n user:pass | base64)" \
     https://api.example.com/users
```

### Common Options

```bash
-X, --request METHOD    # HTTP method (GET, POST, etc.)
-H, --header HEADER     # Add header
-d, --data DATA         # Request body
-i, --include           # Include response headers
-v, --verbose           # Verbose output
-o, --output FILE       # Save to file
-u, --user USER:PASS    # Basic authentication
-L, --location          # Follow redirects
-k, --insecure          # Ignore SSL certificate errors
```

---

## Python Testing

### Using pytest

**Install**
```bash
pip install pytest requests --break-system-packages
```

**Basic Test**
```python
import requests
import pytest

BASE_URL = "https://api.example.com"

def test_get_users():
    response = requests.get(f"{BASE_URL}/users")
    
    assert response.status_code == 200
    assert isinstance(response.json(), list)

def test_get_specific_user():
    response = requests.get(f"{BASE_URL}/users/42")
    
    assert response.status_code == 200
    data = response.json()
    assert data["id"] == 42
    assert "name" in data
    assert "email" in data

def test_create_user():
    new_user = {
        "name": "John Doe",
        "email": "john@example.com"
    }
    
    response = requests.post(
        f"{BASE_URL}/users",
        json=new_user
    )
    
    assert response.status_code == 201
    data = response.json()
    assert data["name"] == new_user["name"]
    assert data["email"] == new_user["email"]
    assert "id" in data

def test_update_user():
    update_data = {"email": "john.new@example.com"}
    
    response = requests.patch(
        f"{BASE_URL}/users/42",
        json=update_data
    )
    
    assert response.status_code == 200
    data = response.json()
    assert data["email"] == update_data["email"]

def test_delete_user():
    response = requests.delete(f"{BASE_URL}/users/42")
    
    assert response.status_code == 204

def test_user_not_found():
    response = requests.get(f"{BASE_URL}/users/99999")
    
    assert response.status_code == 404

def test_unauthorized_access():
    response = requests.get(f"{BASE_URL}/admin/users")
    
    assert response.status_code == 401
```

**Run Tests**
```bash
pytest test_api.py -v
```

### Fixtures for Setup/Teardown

```python
import pytest
import requests

@pytest.fixture
def api_client():
    """Create authenticated client"""
    class APIClient:
        def __init__(self):
            self.base_url = "https://api.example.com"
            self.headers = {"Authorization": "Bearer token123"}
        
        def get(self, endpoint):
            return requests.get(
                f"{self.base_url}{endpoint}",
                headers=self.headers
            )
        
        def post(self, endpoint, data):
            return requests.post(
                f"{self.base_url}{endpoint}",
                json=data,
                headers=self.headers
            )
    
    return APIClient()

@pytest.fixture
def created_user(api_client):
    """Create user for testing, cleanup after"""
    new_user = {
        "name": "Test User",
        "email": "test@example.com"
    }
    
    response = api_client.post("/users", new_user)
    user = response.json()
    
    yield user  # Test runs here
    
    # Cleanup
    requests.delete(
        f"https://api.example.com/users/{user['id']}",
        headers=api_client.headers
    )

def test_get_created_user(api_client, created_user):
    response = api_client.get(f"/users/{created_user['id']}")
    
    assert response.status_code == 200
    assert response.json()["name"] == created_user["name"]
```

### Parameterized Tests

```python
import pytest

@pytest.mark.parametrize("user_id,expected_status", [
    (1, 200),    # Valid user
    (2, 200),    # Valid user
    (999, 404),  # Non-existent user
])
def test_get_user_status(user_id, expected_status):
    response = requests.get(f"https://api.example.com/users/{user_id}")
    assert response.status_code == expected_status

@pytest.mark.parametrize("email,expected_valid", [
    ("valid@example.com", True),
    ("invalid", False),
    ("", False),
])
def test_email_validation(email, expected_valid):
    response = requests.post(
        "https://api.example.com/users",
        json={"name": "Test", "email": email}
    )
    
    if expected_valid:
        assert response.status_code == 201
    else:
        assert response.status_code == 422
```

---

## JavaScript Testing

### Using Jest

**Install**
```bash
npm install --save-dev jest node-fetch
```

**Basic Test**
```javascript
const fetch = require('node-fetch');

const BASE_URL = "https://api.example.com";

describe('User API', () => {
  
  test('GET /users returns list', async () => {
    const response = await fetch(`${BASE_URL}/users`);
    const data = await response.json();
    
    expect(response.status).toBe(200);
    expect(Array.isArray(data)).toBe(true);
  });
  
  test('GET /users/:id returns user', async () => {
    const response = await fetch(`${BASE_URL}/users/42`);
    const data = await response.json();
    
    expect(response.status).toBe(200);
    expect(data.id).toBe(42);
    expect(data).toHaveProperty('name');
    expect(data).toHaveProperty('email');
  });
  
  test('POST /users creates user', async () => {
    const newUser = {
      name: "John Doe",
      email: "john@example.com"
    };
    
    const response = await fetch(`${BASE_URL}/users`, {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json'
      },
      body: JSON.stringify(newUser)
    });
    
    const data = await response.json();
    
    expect(response.status).toBe(201);
    expect(data.name).toBe(newUser.name);
    expect(data.email).toBe(newUser.email);
    expect(data).toHaveProperty('id');
  });
  
  test('DELETE /users/:id removes user', async () => {
    const response = await fetch(`${BASE_URL}/users/42`, {
      method: 'DELETE'
    });
    
    expect(response.status).toBe(204);
  });
  
  test('GET /users/99999 returns 404', async () => {
    const response = await fetch(`${BASE_URL}/users/99999`);
    
    expect(response.status).toBe(404);
  });
});
```

**Run Tests**
```bash
npm test
```

### Setup and Teardown

```javascript
let createdUserId;

beforeAll(async () => {
  // Runs once before all tests
  console.log('Setting up tests...');
});

beforeEach(async () => {
  // Runs before each test
  const newUser = {
    name: "Test User",
    email: "test@example.com"
  };
  
  const response = await fetch(`${BASE_URL}/users`, {
    method: 'POST',
    headers: { 'Content-Type': 'application/json' },
    body: JSON.stringify(newUser)
  });
  
  const data = await response.json();
  createdUserId = data.id;
});

afterEach(async () => {
  // Runs after each test - cleanup
  if (createdUserId) {
    await fetch(`${BASE_URL}/users/${createdUserId}`, {
      method: 'DELETE'
    });
  }
});

afterAll(async () => {
  // Runs once after all tests
  console.log('Tests complete!');
});

test('can get created user', async () => {
  const response = await fetch(`${BASE_URL}/users/${createdUserId}`);
  expect(response.status).toBe(200);
});
```

---

## Best Practices

### 1. Test Both Success and Failure Cases

```python
def test_success_case():
    response = requests.get("/api/users/42")
    assert response.status_code == 200

def test_not_found():
    response = requests.get("/api/users/99999")
    assert response.status_code == 404

def test_unauthorized():
    response = requests.get("/api/admin/users")
    assert response.status_code == 401

def test_invalid_data():
    response = requests.post(
        "/api/users",
        json={"email": "invalid"}  # Missing required field
    )
    assert response.status_code == 422
```

### 2. Use Meaningful Test Names

```python
# Good
def test_get_user_returns_user_data_when_user_exists():
    pass

def test_get_user_returns_404_when_user_not_found():
    pass

# Bad
def test_1():
    pass

def test_user():
    pass
```

### 3. Test One Thing Per Test

```python
# Good - separate tests
def test_create_user_returns_201():
    response = create_user({"name": "John"})
    assert response.status_code == 201

def test_create_user_returns_user_data():
    response = create_user({"name": "John"})
    assert response.json()["name"] == "John"

# Bad - testing multiple things
def test_create_user():
    response = create_user({"name": "John"})
    assert response.status_code == 201
    assert response.json()["name"] == "John"
    assert "id" in response.json()
    # ... many more assertions
```

### 4. Clean Up Test Data

```python
def test_user_workflow():
    # Create
    response = create_user({"name": "Test User"})
    user_id = response.json()["id"]
    
    try:
        # Test operations
        # ...
    finally:
        # Always cleanup
        delete_user(user_id)
```

### 5. Use Environment Variables

```python
import os

# Don't hardcode URLs or credentials
BASE_URL = os.environ.get("API_BASE_URL", "http://localhost:5000")
API_KEY = os.environ.get("API_KEY")
```

### 6. Test Response Schema

```python
def test_user_response_schema():
    response = requests.get("/api/users/42")
    data = response.json()
    
    # Check all expected fields are present
    required_fields = ["id", "name", "email", "created_at"]
    for field in required_fields:
        assert field in data
    
    # Check field types
    assert isinstance(data["id"], int)
    assert isinstance(data["name"], str)
    assert isinstance(data["email"], str)
```

### 7. Test Error Messages

```python
def test_validation_error_message():
    response = requests.post(
        "/api/users",
        json={"name": "John"}  # Missing email
    )
    
    assert response.status_code == 422
    error = response.json()
    assert "email" in error["errors"]
    assert "required" in error["errors"]["email"].lower()
```

### 8. Use Mocking for External Services

```python
from unittest.mock import patch

@patch('requests.get')
def test_external_api_call(mock_get):
    # Mock external API response
    mock_get.return_value.json.return_value = {
        "data": "mocked data"
    }
    mock_get.return_value.status_code = 200
    
    # Your code that calls the external API
    result = fetch_external_data()
    
    assert result == "mocked data"
```

---

## Complete Testing Example

**test_user_api.py**
```python
import pytest
import requests
import os

BASE_URL = os.environ.get("API_BASE_URL", "http://localhost:5000")
API_KEY = os.environ.get("API_KEY", "test-key")

class TestUserAPI:
    
    @pytest.fixture
    def headers(self):
        return {"Authorization": f"Bearer {API_KEY}"}
    
    @pytest.fixture
    def test_user(self, headers):
        """Create and cleanup test user"""
        new_user = {
            "name": "Test User",
            "email": "test@example.com",
            "age": 25
        }
        
        response = requests.post(
            f"{BASE_URL}/users",
            json=new_user,
            headers=headers
        )
        
        user = response.json()
        yield user
        
        # Cleanup
        requests.delete(
            f"{BASE_URL}/users/{user['id']}",
            headers=headers
        )
    
    def test_create_user_success(self, headers):
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
        
        assert response.status_code == 201
        data = response.json()
        assert data["name"] == new_user["name"]
        assert data["email"] == new_user["email"]
        assert "id" in data
        
        # Cleanup
        requests.delete(f"{BASE_URL}/users/{data['id']}", headers=headers)
    
    def test_get_users_list(self, headers):
        response = requests.get(f"{BASE_URL}/users", headers=headers)
        
        assert response.status_code == 200
        assert isinstance(response.json(), list)
    
    def test_get_user_by_id(self, headers, test_user):
        response = requests.get(
            f"{BASE_URL}/users/{test_user['id']}",
            headers=headers
        )
        
        assert response.status_code == 200
        data = response.json()
        assert data["id"] == test_user["id"]
        assert data["name"] == test_user["name"]
    
    def test_update_user(self, headers, test_user):
        update_data = {"email": "newemail@example.com"}
        
        response = requests.patch(
            f"{BASE_URL}/users/{test_user['id']}",
            json=update_data,
            headers=headers
        )
        
        assert response.status_code == 200
        data = response.json()
        assert data["email"] == update_data["email"]
    
    def test_delete_user(self, headers, test_user):
        response = requests.delete(
            f"{BASE_URL}/users/{test_user['id']}",
            headers=headers
        )
        
        assert response.status_code == 204
    
    def test_user_not_found(self, headers):
        response = requests.get(
            f"{BASE_URL}/users/99999",
            headers=headers
        )
        
        assert response.status_code == 404
    
    def test_unauthorized_access(self):
        response = requests.get(f"{BASE_URL}/users")
        assert response.status_code == 401
    
    @pytest.mark.parametrize("invalid_email", [
        "notanemail",
        "",
        "missing@domain",
    ])
    def test_invalid_email_validation(self, headers, invalid_email):
        new_user = {
            "name": "John",
            "email": invalid_email
        }
        
        response = requests.post(
            f"{BASE_URL}/users",
            json=new_user,
            headers=headers
        )
        
        assert response.status_code == 422
```

---

## Summary

**Key Testing Principles:**
- Test both success and failure cases
- Use meaningful test names
- Clean up test data
- Test one thing per test
- Use fixtures for setup/teardown
- Parameterize similar tests
- Mock external dependencies
- Test response schemas
- Validate error messages

**Tools:**
- Postman: GUI, manual testing
- cURL: Quick CLI tests
- pytest: Python automated testing
- Jest: JavaScript automated testing