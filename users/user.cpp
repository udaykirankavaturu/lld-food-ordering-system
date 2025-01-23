#include "user.hpp"
#include "../states/de-state.hpp"
#include "../orders/order.hpp"
#include "../restaurants/restaurant.hpp"
#include <string>

User::User(int id, string name, string mobile) {
        this->id = id;
        this->name = name;
        this->mobile = mobile;
    }

void User::update(Order* order) {
    order->getState();
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

void DeliveryExecutive::assignOrder(Order* order) {
    cout << "Order accepted by delivery executive" << endl;
    this->state->processOrder();

    // navigate to restaurant for pickup
    this->navigate(order, true);

    // navigate to customer for delivery
    this->navigate(order, false);
}

void DeliveryExecutive::navigate(Order* order,bool pickup) {
    if (pickup) {
        cout << "DE is navigating to " << order->restaurant->location->latitude << " " << order->restaurant->location->longitude << " to pick up order" << endl;
        this->pickUpOrder(order);
    } else {
        cout << "DE is navigating to customer location " << order->customer->location->latitude << " " << order->customer->location->longitude << endl;
        this->deliverOrder(order);
    }
}

void DeliveryExecutive::pickUpOrder(Order* order) {
    cout << "Order picked up by DE" << endl;
}

void DeliveryExecutive::deliverOrder(Order* order) {
    order->deliverOrder();
}
