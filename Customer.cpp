#include "Customer.h"
#include <iomanip>

Customer::Customer(int user_id, string username, string password, int loyaltyPoints)
        : User(user_id, username, password), _loyalty_points(loyaltyPoints),_order(nullptr) {}

int Customer::getLoyaltyPoints() const {
    return _loyalty_points;
}

void Customer::setLoyaltyPoints(int loyaltyPoints) {
    _loyalty_points = loyaltyPoints;
}


ostream &operator<<(ostream &os, const Customer &user) {
    os << setw(12) << left << "_user_id:" << setw(10) << user.getUserId() << "\n"
       << setw(12) << left << "_username:" << setw(20) << user.getUsername() << "\n"
       << setw(12) << left << "_loyalty_points:" << setw(10) << user.getLoyaltyPoints();
    return os;
}

Order *Customer::getOrder() const {
    return _order;
}

void Customer::cancelOrder() {
    this->_order->changeOrderStatus(OrderStatus::CANCEL);
}

void Customer::setOrder(Order &order) {
    this->_order = &order;
}

void Customer::printDetails() {

}