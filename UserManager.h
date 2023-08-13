#ifndef RESTAURANT_USER_MANAGER_H
#define RESTAURANT_USER_MANAGER_H

#include "BinarySearchTree.h"
#include "Customer.h"
#include "Admin.h"

class UserManager {
private:
    BinarySearchTree<Customer> users;
    BinarySearchTree<Admin> admins;
public:
    explicit UserManager(string user_filename, string admin_filename);
    bool registerUser( string username, string password);
    User * findUser(string username, bool isCustomer);
    void displayUsers();
};


#endif //RESTAURANT_USER_MANAGER_H
