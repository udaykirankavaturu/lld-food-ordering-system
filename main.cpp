#include "./users/user.hpp"
#include "./utils/location.hpp"
#include "./managers/delivery-executive-manager.hpp"
#include "./restaurants/restaurant.hpp"
#include "./restaurants/menu.hpp"
#include "./restaurants/menu-item.hpp"
#include "./managers/order-manager.hpp"
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
    DeliveryExecutive* de1 = new DeliveryExecutive(1, "Mustafa", "9989321234", location2, dem); 

    Location* location3 = new Location("40.77", "40.7298");
    DeliveryExecutive* de2 = new DeliveryExecutive(2, "Peter", "9989321234", location3, dem);

    // add delivery executives to delivery executive manager
    dem->addDeliveryExecutive(de1);
    dem->addDeliveryExecutive(de2);

    // create order manager
    OrderManager* om = new OrderManager();
    om->setDeliveryExecutiveManager(dem);

    // create restaurant
    Location* location4 = new Location("40.77", "40.7298");
    Restaurant* r1 = new Restaurant(1, "Van Lavino", "9989321234", "Jubilee Hills, Hyderabad",location4, om);

    // create menu
    Menu* menu1 = new Menu();

    // create menu items
    MenuItem* mi1 = new MenuItem(1, "Hummus and falafel combo", "Protein rich falafel and fresh hummus",300);
    MenuItem* mi2 = new MenuItem(1, "Red velvet cookies", "Baked fresh every day",150);

    // add items to menu
    menu1->addMenuItem(mi1);
    menu1->addMenuItem(mi2);

    // add menu to restaurant
    r1->addMenu(menu1);



    // create order
    vector<MenuItem*> orderItems;
    orderItems.push_back(mi1);
    orderItems.push_back(mi2);

    om->createOrder(orderItems, c1, r1);
    // om->getOrders();

    cout<<endl<<"Process completed!"<<endl;

}
