#include <string>
using namespace std;

class Observer {
public:
    virtual void update(const string& message) = 0;
};