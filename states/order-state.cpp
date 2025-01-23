#include "./order-state.hpp"
#include "../orders/order.hpp"
#include <iostream>

using namespace std;

OrderState::OrderState(Order* order)  {
    this->order = order;
}

// Definitions for PlacedState constructor
PlacedState::PlacedState(Order* order) : OrderState(order) {this->name = "Placed";}

// Definitions for ConfirmedState constructor
ConfirmedState::ConfirmedState(Order* order) : OrderState(order) {this->name = "Confirmed";}

// Definitions for InPreparationState constructor
InPreparationState::InPreparationState(Order* order) : OrderState(order) {this->name = "In preparation";}

// Definitions for DispatchedState constructor
DispatchedState::DispatchedState(Order* order) : OrderState(order) {this->name = "On the way";}

// Definitions for DeliveredState constructor
DeliveredState::DeliveredState(Order* order) : OrderState(order) {this->name = "Delivered";}

void OrderState::confirmOrder() {
    cout << "cannot change state from here" << endl;
}

void OrderState::prepareOrder() {
    cout << "cannot change state from here" << endl;
}

void OrderState::dispatchOrder() {
    cout << "cannot change state from here" << endl;
}

void OrderState::deliverOrder() {
    cout << "cannot change state from here" << endl;
}

void PlacedState::confirmOrder(){
    this->order->setState(new ConfirmedState(this->order));
}

void ConfirmedState::prepareOrder(){
    this->order->setState(new InPreparationState(this->order));
}

void InPreparationState::dispatchOrder(){
    this->order->setState(new DispatchedState(this->order));
}

void DispatchedState::deliverOrder(){
    this->order->setState(new DeliveredState(this->order));
}