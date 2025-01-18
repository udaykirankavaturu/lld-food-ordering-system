# Food Ordering System

This C++ program implements a simplified food ordering system with features like user management, restaurant management, menu management, order processing, and delivery tracking. The design leverages object-oriented programming principles and design patterns to ensure scalability and maintainability.

---

## Features

### 1. User Management

- Supports different types of users: **Customers**, **Delivery Executives**, and **Restaurant Owners**.
- Users are derived from a common base class `User` to ensure code reuse and extensibility.

### 2. Restaurant Management

- `Restaurant` class stores restaurant details such as name, location, and menu.
- Restaurants can add menu items and receive orders from customers.

### 3. Menu Management

- `MenuItem` class represents individual food items with details like name, description, and price.
- `Menu` class aggregates multiple `MenuItem` objects for a restaurant.

### 4. Order Processing

- `Order` class manages the lifecycle of an order, from placement to delivery.
- Orders can have multiple items and are associated with a customer and a restaurant.
- Order states include **Placed**, **Confirmed**, **In Preparation**, **On The Way**, **Delivered**, and **Cancelled**.

### 5. Delivery Tracking

- `DeliveryExecutive` class handles the delivery of orders.
- Delivery executives can accept, pick up, and deliver orders.
- The `DeliveryExecutiveManager` class manages the onboarding and assignment of delivery executives.

### 6. Payment Processing

- `Payment` class handles payment processing for orders.
- Payment states include **Initiated**, **Completed**, and **Cancelled**.

---

## Design Patterns Used

### 1. **Observer Pattern**

- The `Order` class acts as a subject, notifying observers (e.g., customers, delivery executives) about order updates.

### 2. **State Pattern**

- The program uses the state pattern to manage order states (`PlacedState`, `ConfirmedState`, etc.) and payment states (`InitiatedState`, `CompletedState`, etc.).

### 3. **Singleton Pattern**

- Managers like `CustomerManager`, `RestaurantManager`, and `DeliveryExecutiveManager` act as centralized controllers for their respective entities.

### 4. **Factory Pattern**

- `OrderManager` is responsible for creating orders and payments.

### 5. **Composite Pattern**

- MenuItems combine to form larger Menus.

### 6. **Facade Pattern**

- `OrderManager` is acting as the front facing interface for the clients for all order management.

---

## Code Structure

### Core Classes

1. **User**

   - Base class for `Customer`, `DeliveryExecutive`, and `RestaurantOwner`.

2. **Restaurant**

   - Stores details about a restaurant, including its menu and location.

3. **MenuItem**

   - Represents individual food items with details like name, description, and price.

4. **Order**

   - Manages the lifecycle of an order, including state transitions and payment processing.

5. **DeliveryExecutive**

   - Handles the delivery of orders, including accepting, picking up, and delivering orders.

### Supporting Classes

1. **Payment**

   - Handles payment processing for orders.

2. **OrderManager**

   - Manages the creation and processing of orders.

3. **DeliveryExecutiveManager**

   - Manages the onboarding and assignment of delivery executives.

---

## How to Use

- Compile the code using a C++ compiler:
  ```bash
  g++ -std=c++14 main.cpp -o main
  ```
- Execute the program:
  ```bash
  ./main
  ```

## How to Extend

- **New User Roles:** Extend the `User` class to add new user types like `Admin` or `Manager`.
- **Additional Order States:** Derive new classes from `OrderState` to implement custom order states.
- **Enhanced Payment Methods:** Extend the `Payment` class to support additional payment methods like UPI or Net Banking.

---

## Conclusion

This food ordering system demonstrates the use of object-oriented programming principles and design patterns to create a scalable and maintainable application. It can be easily extended to support additional features and functionalities.
