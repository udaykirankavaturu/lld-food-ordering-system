#include "./delivery-executive-manager.hpp"
#include "../users/user.hpp"
#include "../orders/order.hpp"

void DeliveryExecutiveManager::addDeliveryExecutive(DeliveryExecutive* deliveryExecutive)
{
    this->deliveryExecutives.push_back(deliveryExecutive);
}

void DeliveryExecutiveManager::assignExecutive(Order* order){
    order->dispatchOrder();
    DeliveryExecutive* deliveryExecutive = this->deliveryExecutives[0];
    deliveryExecutive->assignOrder(order);
}