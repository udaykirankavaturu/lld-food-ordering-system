#include "./delivery-executive-manager.hpp"
#include "../users/user.hpp"

void DeliveryExecutiveManager::addDeliveryExecutive(DeliveryExecutive* deliveryExecutive)
{
    this->deliveryExecutives.push_back(deliveryExecutive);
}