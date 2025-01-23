#ifndef __USER_HPP
#define __USER_HPP
 
#include <iostream>
#include <string>
#include "observer.hpp"
#include "../utils/location.hpp"
#include "../states/de-state.hpp"
#include "../orders/order.hpp"
#include "../managers/delivery-executive-manager.hpp"

using namespace std;


class User : public Observer {
public:
    int id;
    string name;
    string mobile;

    User(int id, string name, string mobile);

    void update(Order* order) override;
};

class Customer : public User {
    public:
        Location* location;
        Customer(int id, string name, string mobile, Location* location);
};

class RestaurantOwner : public User {
    public:
        RestaurantOwner(int id, string name, string mobile);
};

class DeliveryExecutive : public User {
    public:
        Location* location;
        DeliveryExecutiveManager* dem;
        DEState* state;

    DeliveryExecutive(int id, string name, string mobile, Location* location, DeliveryExecutiveManager* dem);

    void setState(DEState* state);
    void assignOrder(Order* order);
    void navigate(Order* order, bool pickup);
    void pickUpOrder(Order* order);
    void deliverOrder(Order* order);

        
};

#endif // __USER_HPP

