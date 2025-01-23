#include "./menu.hpp"
#include "./menu-item.hpp"
#include <string>
#include <vector>
using namespace std;


void Menu::addMenuItem(MenuItem* item) {
    items.push_back(item);
}