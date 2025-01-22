#ifndef __DEM_HPP
#define __DEM_HPP

#include <vector>
using namespace std;

class DeliveryExecutive;


class DeliveryExecutiveManager {
    public:
        vector<DeliveryExecutive*> deliveryExecutives;

        void addDeliveryExecutive(DeliveryExecutive* deliveryExecutive);
};

#endif // __DEM_HPP
