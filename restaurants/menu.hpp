#ifndef __MENU_HPP
#define __MENU_HPP
#include <vector>
using namespace std;

class MenuItem;

class Menu{
    public:
        int id;
        vector<MenuItem*> items;

        void addMenuItem(MenuItem* item);
};

#endif // __MENU_HPP