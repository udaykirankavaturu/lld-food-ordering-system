#include "./order-manager.hpp"
#include "../orders/order.hpp"
#include "../restaurants/restaurant.hpp"
#include "../restaurants/menu-item.hpp"
#include "../users/user.hpp"
#include "../states/order-state.hpp"

#include <iostream>
#include <vector>
using namespace std;

void OrderManager::createOrder(vector<MenuItem*> items, Customer* customer, Restaurant* restaurant){
    Order* o1 = new Order(orders.size()+1,restaurant, customer, items);

    o1->placeOrder();
    restaurant->addOrder(o1);

    orders.push_back(o1);
}

void OrderManager::getOrders(){
    // loop through orders and print them
    for(int i=0; i<orders.size(); i++){
        orders[i]->getOrderDetails();
    }
}

void OrderManager::dispatchOrder(Order* order){
    cout<<"Dispatching order"<<endl;
    this->dem->assignExecutive(order);
}

void OrderManager::setDeliveryExecutiveManager(DeliveryExecutiveManager* dem){
    this->dem = dem;
}