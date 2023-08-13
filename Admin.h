#ifndef RESTAURANT_ADMIN_H
#define RESTAURANT_ADMIN_H

#include "User.h"
class Admin: public User{
public:
    using User::User;


    void printDetails();
};


#endif //RESTAURANT_ADMIN_H
