#ifndef __DEM_HPP
#define __DEM_HPP

#include <vector>
using namespace std;

class DeliveryExecutive;
class Order;


class DeliveryExecutiveManager {
    public:
        vector<DeliveryExecutive*> deliveryExecutives;

        void addDeliveryExecutive(DeliveryExecutive* deliveryExecutive);
        void assignExecutive(Order* order);
};

#endif // __DEM_HPP
