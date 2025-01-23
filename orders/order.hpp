#ifndef __ORDER_HPP
#define __ORDER_HPP
#include <vector>
using namespace std;

class Location;
class Restaurant;
class Customer;
class MenuItem;

class Order {
    public:
        int id;
        Location* location;
        Restaurant* restaurant;
        Customer* customer;
        vector<MenuItem*> items;

        Order(int id,Restaurant* restaurant, Customer* customer, vector<MenuItem*> items);
        void getOrderDetails();
};

#endif // __ORDER_HPP