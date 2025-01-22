#ifndef __LOCATION_HPP
#define __LOCATION_HPP


#include <string>
using namespace std;

class Location {
    public:
        string latitude;
        string longitude;

        Location(string latitude, string longitude);
};

#endif // __LOCATION_HPP
