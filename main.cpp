#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <memory>
#include <algorithm>
#include <queue>

using namespace std;

// Forward declarations
class Order;
class Restaurant;
class Customer;
class DeliveryExecutive;
class Location;
class Payment;
class DeliveryExecutiveManager;

// Location class
class Location {
private:
    string address;
public:
    Location(string addr) : address(std::move(addr)) {}
    const string& getAddress() const { return address; }
};

// Observer interface
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const string& message) = 0;
};

// Subject class for Observer pattern
class Subject {
private:
    vector<Observer*> observers;

public:
    virtual ~Subject() = default;
    
    void addObserver(Observer* observer) {
        if (observer != nullptr) {
            observers.push_back(observer);
        }
    }

    void removeObserver(Observer* observer) {
        observers.erase(
            remove(observers.begin(), observers.end(), observer),
            observers.end()
        );
    }

    void notify(const string& message) {
        for (Observer* observer : observers) {
            if (observer != nullptr) {
                observer->update(message);
            }
        }
    }
};

// Base User class
class User : public Observer {
protected:
    string id;
    string name;
    string mobile;

public:
    User(string id, string name, string mobile)
        : id(std::move(id)), name(std::move(name)), mobile(std::move(mobile)) {}
    
    virtual ~User() = default;
    
    void update(const string& message) override {
        cout << "Notification for " << name << ": " << message << endl;
    }

    const string& getId() const { return id; }
    const string& getName() const { return name; }
};

// Customer class
class Customer : public User {
private:
    Location location;
public:
    Customer(string id, string name, string mobile, Location loc)
        : User(std::move(id), std::move(name), std::move(mobile)), location(std::move(loc)) {}
    
    void getOrderUpdate() {
        cout << "Getting order update for customer: " << name << endl;
    }
};

// CustomerManager class
class CustomerManager {
private:
    map<string, shared_ptr<Customer>> customers;

public:
    void registerCustomer(shared_ptr<Customer> customer) {
        customers[customer->getId()] = customer;
        cout << "Customer registered: " << customer->getName() << endl;
    }

    shared_ptr<Customer> getCustomer(const string& id) {
        auto it = customers.find(id);
        return (it != customers.end()) ? it->second : nullptr;
    }

    void login() {
        // Implementation for login functionality
        cout << "Customer login" << endl;
    }
};

// MenuItem class
class MenuItem {
private:
    string id;
    string title;
    string description;
    double price;
    string photo;

public:
    MenuItem(string id, string title, string desc, double price)
        : id(std::move(id)), title(std::move(title)), 
          description(std::move(desc)), price(price) {}

    double getPrice() const { return price; }
    const string& getTitle() const { return title; }
};

// Menu class
class Menu {
private:
    string id;
    vector<MenuItem> items;

public:
    explicit Menu(string id) : id(std::move(id)) {}

    void addItem(MenuItem item) {
        items.push_back(std::move(item));
    }

    const vector<MenuItem>& getItems() const { return items; }
};

// DeliveryExecutive class
class DeliveryExecutive : public User {
private:
    Location location;
    DeliveryExecutiveManager* manager;

public:
    DeliveryExecutive(string id, string name, string mobile, 
                     Location loc, DeliveryExecutiveManager* mgr = nullptr)
        : User(std::move(id), std::move(name), std::move(mobile)),
          location(std::move(loc)), manager(mgr) {}

    void acceptOrder() {
        cout << "Order accepted by " << name << endl;
    }

    void pickupOrder() {
        cout << "Order picked up by " << name << endl;
    }

    void deliverOrder() {
        cout << "Order delivered by " << name << endl;
    }

    void updateLocation(Location newLoc) {
        location = std::move(newLoc);
    }
};

// DeliveryExecutiveManager class
class DeliveryExecutiveManager {
private:
    vector<shared_ptr<DeliveryExecutive>> executives;

public:
    void onboard(shared_ptr<DeliveryExecutive> executive) {
        executives.push_back(executive);
        cout << "Delivery executive onboarded: " << executive->getName() << endl;
    }

    shared_ptr<DeliveryExecutive> findExecutive() {
        return !executives.empty() ? executives[0] : nullptr;
    }

    void login() {
        // Implementation for login functionality
        cout << "Delivery executive login" << endl;
    }

    void getOrderUpdates() {
        cout << "Getting order updates for delivery executives" << endl;
    }
};

// Payment States
class PaymentState {
public:
    virtual ~PaymentState() = default;
    virtual string getStateName() const = 0;
};

class InitiatedState : public PaymentState {
public:
    string getStateName() const override { return "Initiated"; }
};

class CompletedState : public PaymentState {
public:
    string getStateName() const override { return "Completed"; }
};

class CancelledState : public PaymentState {
public:
    string getStateName() const override { return "Cancelled"; }
};

// Payment class
class Payment {
private:
    string id;
    double amount;
    unique_ptr<PaymentState> state;

public:
    Payment(string id, double amount)
        : id(std::move(id)), amount(amount), 
          state(make_unique<InitiatedState>()) {}

    void setState(unique_ptr<PaymentState> newState) {
        state = std::move(newState);
    }

    void completePayment() {
        setState(make_unique<CompletedState>());
    }

    void cancelPayment() {
        setState(make_unique<CancelledState>());
    }
};

// Order States
class OrderState {
public:
    virtual ~OrderState() = default;
    virtual string getStateName() const = 0;
};

class PlacedState : public OrderState {
public:
    string getStateName() const override { return "Placed"; }
};

class ConfirmedState : public OrderState {
public:
    string getStateName() const override { return "Confirmed"; }
};

class InPreparationState : public OrderState {
public:
    string getStateName() const override { return "In Preparation"; }
};

class OnTheWayState : public OrderState {
public:
    string getStateName() const override { return "On The Way"; }
};

class DeliveredState : public OrderState {
public:
    string getStateName() const override { return "Delivered"; }
};

class CancelledOrderState : public OrderState {
public:
    string getStateName() const override { return "Cancelled"; }
};

// Order class
class Order : public Subject {
private:
    string id;
    vector<MenuItem> items;
    shared_ptr<Restaurant> restaurant;
    shared_ptr<Customer> customer;
    unique_ptr<Payment> payment;
    unique_ptr<OrderState> state;
    double amount;

public:
    Order(string id, shared_ptr<Customer> customer, shared_ptr<Restaurant> restaurant)
        : id(std::move(id)), customer(customer), restaurant(restaurant),
          state(make_unique<PlacedState>()), amount(0.0) {}

    void addItem(MenuItem item) {
        items.push_back(item);
        amount += item.getPrice();
    }

    void setState(unique_ptr<OrderState> newState) {
        state = std::move(newState);
    }

    void createPayment() {
        payment = make_unique<Payment>(id + "_payment", amount);
    }

    const string& getId() const { return id; }
    double getAmount() const { return amount; }
};

// Restaurant class
class Restaurant {
private:
    string id;
    string name;
    string mobile;
    Location location;
    Menu menu;
    shared_ptr<User> owner;
    queue<shared_ptr<Order>> orderQueue;

public:
    Restaurant(string id, string name, string mobile, Location loc)
        : id(std::move(id)), name(std::move(name)), mobile(std::move(mobile)),
          location(std::move(loc)), menu(id + "_menu") {}

    void addMenuItem(MenuItem item) {
        menu.addItem(std::move(item));
    }

    void receiveOrder(shared_ptr<Order> order) {
        orderQueue.push(order);
    }

    const string& getId() const { return id; }
    const string& getName() const { return name; }
    const Menu& getMenu() const { return menu; }
};

// RestaurantManager class
class RestaurantManager {
private:
    map<string, shared_ptr<Restaurant>> restaurants;

public:
    void onboardRestaurant(shared_ptr<Restaurant> restaurant) {
        restaurants[restaurant->getId()] = restaurant;
        cout << "Restaurant onboarded: " << restaurant->getName() << endl;
    }

    shared_ptr<Restaurant> getRestaurant(const string& id) {
        auto it = restaurants.find(id);
        return (it != restaurants.end()) ? it->second : nullptr;
    }

    void login() {
        // Implementation for login functionality
        cout << "Restaurant login" << endl;
    }
};

// OrderManager class
class OrderManager {
private:
    vector<shared_ptr<Order>> orders;

public:
    shared_ptr<Order> createOrder(shared_ptr<Customer> customer, 
                                 shared_ptr<Restaurant> restaurant) {
        auto order = make_shared<Order>(
            "ORD_" + to_string(orders.size() + 1),
            customer,
            restaurant
        );
        orders.push_back(order);
        return order;
    }

    void confirmOrder(shared_ptr<Order> order) {
        order->setState(make_unique<ConfirmedState>());
    }

    void prepareOrder(shared_ptr<Order> order) {
        order->setState(make_unique<InPreparationState>());
    }

    void dispatchOrder(shared_ptr<Order> order) {
        order->setState(make_unique<OnTheWayState>());
    }

    void deliverOrder(shared_ptr<Order> order) {
        order->setState(make_unique<DeliveredState>());
    }

    void cancelOrder(shared_ptr<Order> order) {
        order->setState(make_unique<CancelledOrderState>());
    }
};

int main() {
    try {
        // Initialize managers
        auto customerManager = make_unique<CustomerManager>();
        auto restaurantManager = make_unique<RestaurantManager>();
        auto orderManager = make_unique<OrderManager>();
        auto deliveryManager = make_unique<DeliveryExecutiveManager>();

        // Create and register a customer
        auto customer = make_shared<Customer>(
            "C1", "Rahul Sharma", "9876543210", Location("123 MG Road, Mumbai")
        );
        customerManager->registerCustomer(customer);

        // Create and onboard a restaurant
        auto restaurant = make_shared<Restaurant>(
            "R1", "Bombay Spice", "8765432109", Location("456 Food Street, Delhi")
        );
        restaurant->addMenuItem(MenuItem("M1", "Paneer Tikka", "Spicy grilled cottage cheese", 250.0));
        restaurant->addMenuItem(MenuItem("M2", "Butter Chicken", "Creamy chicken curry", 350.0));
        restaurantManager->onboardRestaurant(restaurant);

        // Create and onboard delivery executive
        auto executive = make_shared<DeliveryExecutive>(
            "D1", "Ramesh Kumar", "7894561230", 
            Location("789 Delivery Lane, Bangalore"), 
            deliveryManager.get()
        );
        deliveryManager->onboard(executive);

        // Create and process order
        auto order = orderManager->createOrder(customer, restaurant);
        order->addItem(MenuItem("M1", "Paneer Tikka", "Spicy grilled cottage cheese", 250.0));
        order->createPayment();

        // Process order through states
        orderManager->confirmOrder(order);
        orderManager->prepareOrder(order);
        orderManager->dispatchOrder(order);
        
        // Assign delivery
        auto assignedExecutive = deliveryManager->findExecutive();
        if (assignedExecutive) {
            assignedExecutive->acceptOrder();
            assignedExecutive->pickupOrder();
            assignedExecutive->deliverOrder();
            orderManager->deliverOrder(order);
        }

        cout << "Order processing completed successfully!" << endl;

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}