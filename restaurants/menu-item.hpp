#ifndef __MENU_ITEM_HPP
#define __MENU_ITEM_HPP
#include <string>
using namespace std;

class MenuItem{
    public:
        int id;
        string title;
        string description;
        float price;

        MenuItem(int id, string title, string description, float price);
};
#endif //__MENU_ITEM_HPP