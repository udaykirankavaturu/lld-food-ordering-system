#ifndef __DE_STATE_HPP
#define __DE_STATE_HPP

#include <iostream>
#include "user.hpp"
using namespace std;


class DEState{
    protected:
        DeliveryExecutive* de;
    
    public:

    void setDE(DeliveryExecutive* de){
        this->de = de;
    }

    virtual void goOnline() {
        cout<<"cannot change state from here"<<endl;
    };
    virtual void goOffline() {
        cout<<"cannot change state from here"<<endl;
    };
    virtual void processOrder() {
        cout<<"cannot change state from here"<<endl;
    };
};

// forward declarations
class AvailableState : public DEState{
    public:
        void goOffline() override;
        void processOrder() override;
};

class OfflineState : public DEState{
    public:
        void goOnline() override;
};

class BusyState : public DEState{
    public:
        void goOnline() override;
        void goOffline() override;
};


// implementations
void AvailableState :: goOffline(){
    this->de->setState(new OfflineState());
}

void AvailableState :: processOrder(){
    this->de->setState(new BusyState());
}

void OfflineState :: goOnline(){
    this->de->setState(new AvailableState());
}

void BusyState :: goOnline(){
    this->de->setState(new AvailableState());
}   

void BusyState :: goOffline(){
    this->de->setState(new OfflineState());
}

#endif //__DE_STATE_HPP