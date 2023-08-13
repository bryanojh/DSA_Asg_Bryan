#ifndef RESTAURANT_CUSTOMER_H
#define RESTAURANT_CUSTOMER_H

#include <string>
#include <ostream>

#include "User.h"
#include "Order.h"

using namespace std;
class Customer : public User{
private:
    int _loyalty_points;
    Order * _order;

public:
    using User::User;

    Customer(int userId, string username, string password, int loyaltyPoints);

    int getLoyaltyPoints() const;

    void setLoyaltyPoints(int loyaltyPoints);

    Order *getOrder() const;

    void setOrder(Order &order);

    void cancelOrder();

    friend ostream &operator<<(ostream &os, const Customer &user);

    void printDetails() override;
};


#endif //RESTAURANT_CUSTOMER_H
