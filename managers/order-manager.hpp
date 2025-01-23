#ifndef __ORDER_MANAGER_HPP
#define __ORDER_MANAGER_HPP
#include <vector>
using namespace std;

class Order;
class Customer;
class Restaurant;
class MenuItem;
class DeliveryExecutiveManager;


class OrderManager {
    public:
    vector<Order*> orders;
    DeliveryExecutiveManager* dem;

    void createOrder(vector<MenuItem*> items, Customer* customer, Restaurant* restaurant);
    void getOrders();
    void dispatchOrder(Order* order);
    void setDeliveryExecutiveManager(DeliveryExecutiveManager* dem);

};

#endif // __ORDER_MANAGER_HPP