#ifndef ORDER_STATE_HPP
#define ORDER_STATE_HPP
#include <string>
using namespace std;

// Forward declaration
class Order;

class OrderState {
    protected:
        Order* order;
    
    public:
        string name;
        OrderState(Order* order);
        virtual void confirmOrder();
        virtual void prepareOrder();
        virtual void dispatchOrder();
        virtual void deliverOrder();
};

class PlacedState : public OrderState {
    public:
        PlacedState(Order* order);
        void confirmOrder() override;
};

class ConfirmedState : public OrderState {
    public:
        ConfirmedState(Order* order);
        void prepareOrder() override;
};

class InPreparationState : public OrderState {
    public:
        InPreparationState(Order* order);
        void dispatchOrder() override;
};

class DispatchedState : public OrderState {
    public:
        DispatchedState(Order* order);
        void deliverOrder() override;
};

class DeliveredState : public OrderState {
    public:
        DeliveredState(Order* order);
};

#endif // ORDER_STATE_HPP