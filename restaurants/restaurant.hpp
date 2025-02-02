#ifndef __RESTAURANT_HPP
#define __RESTAURANT_HPP

#include "../utils/location.hpp"
#include "../orders/order.hpp"
#include "../managers/order-manager.hpp"

class Menu;

class Restaurant {
    public:
        int id;
        string name;
        string mobile;
        string address;
        Location* location;
        Menu* menu;
        OrderManager* orderManager;
        vector<Order*> orders;

        Restaurant(int id, string name, string mobile, string address, Location* location, OrderManager* orderManager);
        void addMenu(Menu* menu);
        Menu* getMenu();
        void addOrder(Order* order);
        void confirmOrder(Order* order);
        void prepareOrder(Order* order);
        void dispatchOrder(Order* order);


};

#endif //__RESTAURANT_HPP