// de-state.cpp
#include "de-state.hpp"
#include "../users/user.hpp"  // Include this to access DeliveryExecutive class
using namespace std;

// DEState implementations
void DEState::setDE(DeliveryExecutive* de) {
    this->de = de;
}

void DEState::goOnline() {
    cout << "cannot change state from here" << endl;
}

void DEState::goOffline() {
    cout << "cannot change state from here" << endl;
}

void DEState::processOrder() {
    cout << "cannot change state from here" << endl;
}

// AvailableState implementations
void AvailableState::goOffline() {
    this->de->setState(new OfflineState());
}

void AvailableState::processOrder() {
    this->de->setState(new BusyState());
}

// OfflineState implementations
void OfflineState::goOnline() {
    this->de->setState(new AvailableState());
}

// BusyState implementations
void BusyState::goOnline() {
    this->de->setState(new AvailableState());
}

void BusyState::goOffline() {
    this->de->setState(new OfflineState());
}
