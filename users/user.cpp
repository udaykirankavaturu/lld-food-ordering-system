#include "user.hpp"
#include "../states/de-state.hpp"
#include "../orders/order.hpp"
#include <string>

User::User(int id, string name, string mobile) {
        this->id = id;
        this->name = name;
        this->mobile = mobile;
    }

void User::update(const string& message) {
    cout << "User " << name << " received message: " << message << endl;
}

Customer::Customer(int id, string name, string mobile, Location* location) : User(id, name, mobile) {
    this->location = location;
}

RestaurantOwner::RestaurantOwner(int id, string name, string mobile)
    : User(id, name, mobile) {}


DeliveryExecutive::DeliveryExecutive(int id, string name, string mobile, Location* location, DeliveryExecutiveManager* dem)
    : User(id, name, mobile), location(location), dem(dem), state(nullptr) {
        this->location = location;
        this->state = new AvailableState();
        this->state->setDE(this);
    }

void DeliveryExecutive::setState(DEState* state) {
    this->state = state;
}

void DeliveryExecutive::receiveOrder(Order* order) {
    cout << "Order received by DE" << endl;
    this->acceptOrder(order);
}

void DeliveryExecutive::acceptOrder(Order* order) {
    cout << "Order accepted by DE" << endl;
    this->state->processOrder();
    this->navigate(order, true);
}

void DeliveryExecutive::navigate(Order* order,bool pickup) {
    if (pickup) {
        cout << "DE is navigating to " << order->location->latitude << " " << order->location->longitude << " to pick up order" << endl;
        this->pickUpOrder(order);
    } else {
        cout << "DE is navigating to customer location " << order->location->latitude << " " << order->location->longitude << endl;
        this->deliverOrder(order);
    }
}

void DeliveryExecutive::pickUpOrder(Order* order) {
    cout << "Order picked up by DE" << endl;
}

void DeliveryExecutive::deliverOrder(Order* order) {
    cout << "Order delivered by DE" << endl;
}
