#include "./order-manager.hpp"
#include "../orders/order.hpp"
#include "../restaurants/restaurant.hpp"
#include "../restaurants/menu-item.hpp"
#include "../users/user.hpp"

#include <iostream>
#include <vector>
using namespace std;

void OrderManager::createOrder(vector<MenuItem*> items, Customer* customer, Restaurant* restaurant){
    Order* o1 = new Order(orders.size()+1,restaurant, customer, items);
    cout<<"new order created"<<endl;

    orders.push_back(o1);
}

void OrderManager::getOrders(){
    // loop through orders and print them
    for(int i=0; i<orders.size(); i++){
        orders[i]->getOrderDetails();
    }
}