#include "Order.h"
#include <iostream>
#include <iomanip>

Order::Order(int order_id, User &user) : order_id(order_id), _customer(&user), size(0), orderStatus(PENDING) {}

int Order::getOrderId() const {
    return order_id;
}

int Order::getSize() const {
    return size;
}

OrderStatus Order::getOrderStatus() const {
    return orderStatus;
}

double Order::getTotalPrice() const {
    double total = 0.0;
    for (int i = 0; i < size; ++i) {
        total += foods[i].getPrice();
    }
    return total;
}

bool Order::addFood(const Food &food) {
    if (size < MAX_FOODS) {
        foods[size++] = food;
        return true;
    } else {
        std::cout << "Cannot add more food. Maximum limit reached." << std::endl;
        return false;
    }
}

void Order::changeOrderStatus(OrderStatus newStatus) {
    orderStatus = newStatus;
}

void Order::cancelOrder() {
    size = 0; // Clear the food array
    orderStatus = PENDING; // Reset the order status
}

User *Order::getUser() const {
    return _customer;
}

void Order::setUser(User *user) {
    _customer = user;
}

std::ostream &operator<<(std::ostream &os, const Order &order) {
    os << "Order ID: " << order.order_id << std::endl;
    os << "Total Price: $" << std::fixed << std::setprecision(2) << order.getTotalPrice() << std::endl;

    os << "Order Status: ";
    switch (order.orderStatus) {
        case OrderStatus::ACCEPTED: os << "Accepted"; break;
        case OrderStatus::PREPARING: os << "Preparing"; break;
        case OrderStatus::READY: os << "Ready"; break;
        case OrderStatus::PENDING: os << "Pending"; break;
        case OrderStatus::CANCEL: os << "Cancel"; break;
        default: os << "Unknown"; break;
    }
    os << std::endl;

    os << "User: " << order._customer->getUsername() << std::endl;
    os << "Food Items:" << std::endl;

    for (int i = 0; i < order.size; ++i) {
        os << "   - " << std::left << std::setw(20) << order.foods[i].getFoodName() << " ($" << std::fixed << std::setprecision(2) << order.foods[i].getPrice() << ")" << std::endl;
    }

    return os;
}