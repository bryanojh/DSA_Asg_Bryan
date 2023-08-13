#ifndef RESTAURANT_FILE_MANAGER_H
#define RESTAURANT_FILE_MANAGER_H

#include <iostream>
#include <string>

#include "Food.h"
#include "BinarySearchTree.cpp"
#include "Customer.h"
#include "Admin.h"

using namespace std;

BinarySearchTree<Food> loadFoodsFromFile(string filename);
BinarySearchTree<Customer> loadCustomersFromFile(string filename);
BinarySearchTree<Admin> loadAdminsFromFile(string filename);

#endif //RESTAURANT_FILE_MANAGER_H
