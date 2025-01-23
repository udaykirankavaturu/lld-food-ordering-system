#include "./restaurant.hpp"
#include "./menu.hpp"
#include <vector>
using namespace std;



Restaurant::Restaurant(int id, string name, string mobile, string address, Location* location, OrderManager* orderManager){
    this->id = id;
    this->name = name;
    this->mobile = mobile;
    this->address = address;
    this->location = location;
    this->orderManager = orderManager;
}

void Restaurant::addMenu(Menu* menu){
    this->menu = menu;
}

void Restaurant::addOrder(Order* order){
    this->orders.push_back(order);

    this->confirmOrder(order);
}

void Restaurant::confirmOrder(Order* order){
    order->confirmOrder();

    this->prepareOrder(order);
}

void Restaurant::prepareOrder(Order* order){
    order->prepareOrder();

    this->dispatchOrder(order);
}

void Restaurant::dispatchOrder(Order* order){
    this->orderManager->dispatchOrder(order);
}

Menu* Restaurant::getMenu(){
    return this->menu;
}