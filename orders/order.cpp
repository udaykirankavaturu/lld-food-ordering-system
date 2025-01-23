#include "./order.hpp"
#include "../restaurants/restaurant.hpp"
#include "../users/user.hpp"
#include "../restaurants/menu-item.hpp"
#include "../states/order-state.hpp"
#include <iostream>
using namespace std;

Order::Order(int id,Restaurant* restaurant, Customer* customer, vector<MenuItem*> items){
    this->id = id;
    this->restaurant = restaurant;
    this->customer = customer;
    this->items = items;
}

void Order::getOrderDetails(){
    cout<<"Order ID: "<<id<<endl;
    cout<<"Restaurant: "<<restaurant->name<<endl;
    cout<<"Customer: "<<customer->name<<endl;
    cout<<"Items: "<<endl;
    for(int i = 0; i < items.size(); i++){
        cout<<items[i]->title<<endl;
    }
}

void Order::setState(OrderState* orderState){
    this->orderState = orderState;
}

void Order::getState(){
    cout<<this->orderState->name<<endl;
}

void Order::placeOrder(){
    this->orderState = new PlacedState(this);
}

void Order::confirmOrder(){
    this->orderState->confirmOrder();
}

void Order::prepareOrder(){
    this->orderState->prepareOrder();
}

void Order::dispatchOrder(){
    this->orderState->dispatchOrder();
}

void Order::deliverOrder(){
    this->orderState->deliverOrder();
}