#ifndef RESTAURANT_ORDER_H
#define RESTAURANT_ORDER_H

#include <string>
#include <ostream>
#include "Food.h"
#include "User.h"

using namespace std;
enum OrderStatus {
    PENDING,
    ACCEPTED,
    PREPARING,
    READY,
    CANCEL
};

class Order {
private:
    static const int MAX_FOODS = 3;
    int order_id;
    int size;
    Food foods[MAX_FOODS];
    OrderStatus orderStatus;
    User * _customer;

public:

    explicit Order(int order_id, User &user);

    int getOrderId() const;

    int getSize() const;

    OrderStatus getOrderStatus() const;

    double getTotalPrice() const;

    User *getUser() const;

    void setUser(User *user);

    bool addFood(const Food &food);

    void changeOrderStatus(OrderStatus newStatus);

    void cancelOrder();

    friend ostream &operator<<(ostream &os, const Order &order);

};

#endif //RESTAURANT_ORDER_H
