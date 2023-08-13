#include "file-manager.h"
#include <fstream>
#include <sstream>

BinarySearchTree<Food> loadFoodsFromFile(string filename){
    BinarySearchTree<Food> foodBST;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return foodBST;  // Return an empty BST
    }

    string line;
    int count = 0;
    while (getline(file, line)) {
        istringstream iss(line);
        int food_id;
        string food_name;
        double price;

        if (iss >> food_id >> food_name >> price) {
            foodBST.insert(Food(food_id, food_name, price));
            count++;
        }
    }

    file.close();
    foodBST.setCount(count);
    return foodBST;
}

BinarySearchTree<Customer> loadCustomersFromFile(string filename){
    BinarySearchTree<Customer> userBST;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return userBST;  // Return an empty BST
    }

    int user_id, loyalty_points, count =0;
    std::string username, password;
    while (file >> user_id >> username >> password >> loyalty_points) {
        userBST.insert(Customer(user_id, username, password, loyalty_points));
        count++;
    }

    file.close();
    userBST.setCount(count);
    return userBST;
}

BinarySearchTree<Admin> loadAdminsFromFile(string filename){
    BinarySearchTree<Admin> adminBST;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return adminBST;  // Return an empty BST
    }

    int user_id, loyalty_points, count =0;
    std::string username, password;
    while (file >> user_id >> username >> password) {
        adminBST.insert(Admin(user_id, username, password));
        count++;
    }

    file.close();
    adminBST.setCount(count);
    return adminBST;
}