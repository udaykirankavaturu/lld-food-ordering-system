#include "./users/user.hpp"
#include "./utils/location.hpp"
#include "./managers/delivery-executive-manager.hpp"
#include "./restaurants/restaurant.hpp"
#include <iostream>
using namespace std;

int main(){
    // create customer
    Location* location = new Location("31.77","31.726");
    Customer* c1 = new Customer(1, "uday","9989321234", location);

    // create delivery executive manager
    DeliveryExecutiveManager* dem = new DeliveryExecutiveManager();

    // create delivery executives
    Location* location2 = new Location("34.77", "31.7298");
    DeliveryExecutive* de1 = new DeliveryExecutive(1, "uday", "9989321234", location2, dem); 

    Location* location3 = new Location("40.77", "40.7298");
    DeliveryExecutive* de2 = new DeliveryExecutive(2, "uday", "9989321234", location3, dem);

    // add delivery executives to delivery executive manager
    dem->addDeliveryExecutive(de1);
    dem->addDeliveryExecutive(de2);

    // create restaurant
    Location* location4 = new Location("40.77", "40.7298");
    Restaurant* r1 = new Restaurant(1, "Van Lavino", "9989321234", "Jubilee Hills, Hyderabad",location4);


    cout<<"all good!"<<endl;

}
