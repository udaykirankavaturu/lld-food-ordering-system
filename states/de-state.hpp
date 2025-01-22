// de-state.hpp
#ifndef DE_STATE_HPP
#define DE_STATE_HPP

#include <iostream>

// Forward declaration
class DeliveryExecutive;

class DEState {
    protected:
        DeliveryExecutive* de;
    
    public:
        void setDE(DeliveryExecutive* de);
        virtual void goOnline();
        virtual void goOffline();
        virtual void processOrder();
};

class AvailableState : public DEState {
    public:
        void goOffline() override;
        void processOrder() override;
};

class OfflineState : public DEState {
    public:
        void goOnline() override;
};

class BusyState : public DEState {
    public:
        void goOnline() override;
        void goOffline() override;
};

#endif // DE_STATE_HPP
