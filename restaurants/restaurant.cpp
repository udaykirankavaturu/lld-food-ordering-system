#include "./restaurant.hpp"

Restaurant::Restaurant(int id, string name, string mobile, string address, Location* location){
    this->id = id;
    this->name = name;
    this->mobile = mobile;
    this->address = address;
    this->location = location;
}