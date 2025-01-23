#ifndef __ORDER_MANAGER_HPP
#define __ORDER_MANAGER_HPP
#include <vector>
using namespace std;

class Order;
class Customer;
class Restaurant;
class MenuItem;


class OrderManager {
    public:
    vector<Order*> orders;

    void createOrder(vector<MenuItem*> items, Customer* customer, Restaurant* restaurant);
    void getOrders();

};

#endif // __ORDER_MANAGER_HPP