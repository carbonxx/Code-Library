# API (Application Programming Interface)

## Table of Contents
- [What is an API?](#what-is-an-api)
- [How APIs Work](#how-apis-work)
- [Client-Server Architecture](#client-server-architecture)
- [HTTP Methods](#http-methods)
- [Request and Response](#request-and-response)
- [Status Codes](#status-codes)
- [REST API](#rest-api)
- [Authentication](#authentication)
- [API Testing](#api-testing)

---

## What is an API?

An **API (Application Programming Interface)** is a set of rules and protocols that allows different software applications to communicate with each other. It acts as an intermediary that enables data exchange between systems.

### Real-World Analogy

Think of an API like a **waiter in a restaurant**:
- **You (Client)**: You look at the menu and decide what you want
- **Waiter (API)**: Takes your order to the kitchen
- **Kitchen (Server)**: Prepares your food
- **Waiter (API)**: Brings the food back to you

The waiter (API) is the messenger between you and the kitchen, just like an API is the messenger between your application and a server.

### Why APIs Matter

- **Integration**: Connect different services (payment gateways, weather data, social media)
- **Efficiency**: Reuse existing functionality instead of building from scratch
- **Scalability**: Separate frontend and backend concerns
- **Security**: Control access to data and functionality

---

## How APIs Work

APIs enable communication through **requests** and **responses**:

1. **Client** sends a request to the API
2. **API** processes the request and communicates with the server
3. **Server** performs the operation and sends data back
4. **API** returns the response to the client

```
[Client Application] 
       ↓ (Request)
    [API Layer]
       ↓
   [Server/Database]
       ↓
    [API Layer]
       ↓ (Response)
[Client Application]
```

---

## Client-Server Architecture

### Client
The **client** is the application or device that requests data:
- Web browsers
- Mobile apps
- Desktop applications
- Other servers

### Server
The **server** is the system that provides data or services:
- Stores data in databases
- Processes business logic
- Manages authentication
- Returns responses to clients

### Communication Flow
```
Client → Request → API → Server → Database
                             ↓
Client ← Response ← API ← Server
```

---

## HTTP Methods

APIs use HTTP methods to perform different operations. See [http.md](http.md) for detailed information.

### Quick Reference

| Method | Purpose | Example |
|--------|---------|---------|
| **GET** | Retrieve data | Get user profile |
| **POST** | Create new data | Create new user |
| **PUT** | Update entire resource | Replace user data |
| **PATCH** | Partial update | Update user email only |
| **DELETE** | Remove data | Delete user account |

---

## Request and Response

Every API interaction consists of a **request** from the client and a **response** from the server. See [req_&_resp.md](req_&_resp.md) for complete details.

### Request Components
- **URL/Endpoint**: Where to send the request
- **Method**: What operation to perform
- **Headers**: Metadata about the request
- **Body**: Data being sent (for POST/PUT/PATCH)

### Response Components
- **Status Code**: Success or error indicator
- **Headers**: Metadata about the response
- **Body**: Data returned from the server

---

## Status Codes

HTTP status codes indicate the result of an API request. See [status_codes.md](status_codes.md) for the complete list.

### Categories

- **2xx Success**: Request succeeded
- **3xx Redirection**: Further action needed
- **4xx Client Error**: Problem with the request
- **5xx Server Error**: Server failed to process request

---

## REST API

**REST (Representational State Transfer)** is an architectural style for designing APIs. See [rest_api.md](rest_api.md) for comprehensive coverage.

### Key Principles
- **Stateless**: Each request contains all necessary information
- **Resource-based**: Everything is a resource with a unique URL
- **Standard methods**: Use HTTP methods appropriately
- **JSON format**: Typically use JSON for data exchange

---

## Authentication

Authentication ensures only authorized users can access API resources. See [auth.md](auth.md) for security details.

### Common Methods
- **API Keys**: Simple token passed in headers
- **OAuth**: Industry-standard authorization framework
- **JWT (JSON Web Tokens)**: Encoded tokens with user data
- **Basic Auth**: Username and password encoded in headers

---

## API Testing

Testing ensures your API works correctly and handles errors properly. See [api_testing.md](api_testing.md) for testing strategies.

### Popular Tools
- **Postman**: GUI-based API testing
- **cURL**: Command-line tool
- **Thunder Client**: VS Code extension
- **Insomnia**: API design and testing platform

---

## Quick Start Example

### Python Example
```python
import requests

# GET request
response = requests.get("https://api.example.com/users")
print(response.json())

# POST request
new_user = {"name": "John Doe", "email": "john@example.com"}
response = requests.post("https://api.example.com/users", json=new_user)
print(response.status_code)
```

### JavaScript Example
```javascript
// GET request
fetch("https://api.example.com/users")
  .then(res => res.json())
  .then(data => console.log(data));

// POST request
fetch("https://api.example.com/users", {
  method: "POST",
  headers: {
    "Content-Type": "application/json"
  },
  body: JSON.stringify({
    name: "John Doe",
    email: "john@example.com"
  })
})
  .then(res => res.json())
  .then(data => console.log(data));
```

---

## Further Reading

- [HTTP Methods](http.md) - Detailed guide to GET, POST, PUT, DELETE, PATCH
- [Request & Response](req_&_resp.md) - Structure and examples
- [Status Codes](status_codes.md) - Complete reference guide
- [REST API](rest_api.md) - Design principles and best practices
- [Authentication](auth.md) - Security methods and implementation
- [API Testing](api_testing.md) - Tools and techniques