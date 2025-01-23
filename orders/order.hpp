#ifndef __ORDER_HPP
#define __ORDER_HPP
#include <vector>
using namespace std;

class Location;
class Restaurant;
class Customer;
class MenuItem;
class OrderState;

class Order {
    public:
        int id;
        Location* location;
        Restaurant* restaurant;
        Customer* customer;
        vector<MenuItem*> items;
        OrderState* orderState;

        Order(int id,Restaurant* restaurant, Customer* customer, vector<MenuItem*> items);
        void getOrderDetails();

        void setState(OrderState* orderState);
        void getState();

        void placeOrder();
        void confirmOrder();
        void prepareOrder();
        void dispatchOrder();
        void deliverOrder();
};

#endif // __ORDER_HPP