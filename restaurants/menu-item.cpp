#include "./menu-item.hpp"

MenuItem::MenuItem(int id, string title, string description, float price){
    this->id = id;
    this->title = title;
    this->description = description;
    this->price = price;
}