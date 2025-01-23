#include "./restaurant.hpp"
#include "./menu.hpp"
#include <vector>
using namespace std;



Restaurant::Restaurant(int id, string name, string mobile, string address, Location* location){
    this->id = id;
    this->name = name;
    this->mobile = mobile;
    this->address = address;
    this->location = location;
}

void Restaurant::addMenu(Menu* menu){
    this->menu = menu;
}

Menu* Restaurant::getMenu(){
    return this->menu;
}