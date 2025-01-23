#include <string>
using namespace std;

class Order;

class Observer {
public:
    virtual void update(Order* order) = 0;
};