#include <iostream>
#include <iomanip>

#include "Queue.cpp"
#include "Food.h"
#include "UserManager.h"
#include "file-manager.h"
#include "Admin.h"

#define FOODS_DB "DB/foods.txt"
#define USERS_DB "DB/users.txt"
#define ADMINS_DB "DB/admins.txt"

#define CUSTOMER 1
#define ADMIN 2

void displayMenu();

int handlePreLoginStatus(UserManager userManager, User **user);

void displayCustomerMenu(User user);

void displayAdminMenu(User admin);


int main() {
    BinarySearchTree<Food> foodList = loadFoodsFromFile(FOODS_DB);
    UserManager userManager(USERS_DB,ADMINS_DB);
    Queue<Order> currOrdersPending;
    Queue<Order> ordersInKitchen;

    int orderCount = 0;

    User *userPtr = nullptr;
    int userType;
    do {
        userType = handlePreLoginStatus(userManager, &userPtr);

        int choice;

        if (userType == CUSTOMER) {

            int foodItemId;
            auto * customerPtr = dynamic_cast<Customer*>(userPtr);
            do {
                displayCustomerMenu(*userPtr);
                cin >> choice;

                if (choice == 1){
                    cout << left << setw(6) << "ID" << setw(20) << "Name" << setw(10) << "Price ($)\n";
                    cout << "------------------------------\n";
                    foodList.displayInOrder();
                }
                else if(choice == 2){
                    bool isFreeQueue = true;
                    Order * order = customerPtr->getOrder();

                    cout << left << setw(6) << "ID" << setw(20) << "Name" << setw(10) << "Price ($)\n";
                    cout << "------------------------------\n";
                    foodList.displayInOrder();
                    cout << "------------------------------\n";

                    if (order != NULL){
                        if (order->getOrderStatus() != OrderStatus::READY && order->getOrderStatus() != OrderStatus::CANCEL){
                            cout << "You already have an order, Please wait\n\n";
                            isFreeQueue = false;
                        }
                    }

                    Order newOrder(++orderCount, *customerPtr);

                    do {

                        if (!isFreeQueue) break;

                        cout << "Enter Food ID (0 to finish): ";
                        cin >> foodItemId;
                        if (foodItemId == 0) {
                            break;
                        }

                        Food *searchedFood = foodList.fullTreeSearch(Food(foodItemId, "Searching food", 0.00));
                        if (searchedFood) {
                            if (newOrder.addFood(*searchedFood)) {
                                cout << "Food added to the order." << endl;
                            } else {
                                break;
                            }

                        } else {
                            cout << "Food not found." << endl;
                        }
                    } while (true);

                    if (newOrder.getSize() >= 1) {
                        cout << newOrder << endl;
                        cout << "Want to confirm the order (y/or any other to no):";
                        char c;
                        cin >> c;

                        if (c == 'y' || c == 'Y'){
                            cout << "Order created with ID: " << newOrder.getOrderId() << endl;
                            customerPtr->setOrder(newOrder);
                            currOrdersPending.push(newOrder);
                        }


                    } else {
                        orderCount--;
                    }
                }

                else if(choice == 3){
                    Order * order = customerPtr->getOrder();
                    if (order){
                        cout << *customerPtr->getOrder() << endl;
                    }
                    else{
                        cout << "No items in the cart\n\n";
                    }
                }

                else if (choice == 4){
                    Order* currOrder = customerPtr->getOrder();
                    if (currOrder){
                        if (currOrder->getOrderStatus() == OrderStatus::PENDING){
                            cout << *currOrder << endl;
                            cout << "Are you sure to cancel this order (y or any other to no):";
                            char c;
                            cin >> c;
                            if (c == 'y' || c == 'Y'){
                                customerPtr->cancelOrder();
                            }
                        }
                    }
                }

            } while (choice != 5);

        }
        else if(userType == ADMIN) {

            do {
                displayAdminMenu(*userPtr);
                cin >> choice;

                if (choice == 1){
                    cout << left << setw(6) << "ID" << setw(20) << "Name" << setw(10) << "Price ($)\n";
                    cout << "------------------------------\n";
                    foodList.displayInOrder();
                }
                else if(choice == 2){
                    cout << "Adding food to kitchen....\n\n";
                    for (int i = 0; i < currOrdersPending.size(); ++i) {
                        Order order = currOrdersPending.pop();

                        if (order.getOrderStatus() != OrderStatus::CANCEL){
                            ordersInKitchen.push(order);
                            order.changeOrderStatus(OrderStatus::PREPARING);
                        }
                    }

                    cout << "Order are in the kitchen ....\n\n";
                }
                else if (choice == 3){

                    if (!ordersInKitchen.is_empty()){
                        Order order = ordersInKitchen.pop();
                        order.changeOrderStatus(OrderStatus::READY);
                    }


                }
                else if(choice == 4){
                    userManager.displayUsers();
                }
                else if (choice == 5){
                    string food_name;
                    double price;

                    cout << "Food Name : ";
                    cin >> food_name;

                    cout << "Price : ";
                    cin>> price;

                    Food food(foodList.getCount()+1, food_name, price);
                    foodList.insert(food);
                    cout << "Food is created\n\n";
                }
                else if (choice == 6){
                    string username;
                    cout << "Enter username of the user : ";
                    cin >> username;

                    Customer * customer = dynamic_cast<Customer *>(userManager.findUser(username, true));

                    int points;
                    cout << "Enter the amount of loyalty points : ";
                    cin >> points;

                    customer->setLoyaltyPoints(customer->getLoyaltyPoints() + points);


                }
            }while(choice != 7);
        }

    }while(userType != 4);

    return 0;
}

void displayMenu() {
    cout << "-----------------------------\n";
    cout << "Welcome to Food Ordering System\n";
    cout << "-----------------------------\n";
    cout << "1. Log in as a user\n";
    cout << "2. Log in as a Admin\n";
    cout << "3. Register as a user\n";
    cout << "4. Exit\n";
    cout << "-----------------------------\n";
    cout << "Enter your choice: ";
}


void displayCustomerMenu(User user) {
    cout << "--------------------------------\n";
    cout << user.getUsername() << ", Welcome to Food Ordering System\n";
    cout << "--------------------------------\n";
    cout << "1. Browse food list\n";
    cout << "2. Create an Order\n";
    cout << "3. Check the status\n";
    cout << "4. Cancel current Order\n";
    cout << "5. Log out\n";
    cout << "--------------------------------\n";
    cout << "Enter your choice : ";

}


void displayAdminMenu(User admin){
    cout << "--------------------------------\n";
    cout << admin.getUsername() << ", Welcome to Food Ordering System\n";
    cout << "--------------------------------\n";
    cout << "1. Browse food list\n";
    cout << "2. Add orders to kitchen\n";
    cout << "3. Update the latest order status\n";
    cout << "4. See the registered users\n";
    cout << "5. Add food item to list\n";
    cout << "6. Give loyalty point to users\n";
    cout << "7. Log out\n";
    cout << "--------------------------------\n";
    cout << "Enter your choice : ";
}
int handlePreLoginStatus(UserManager userManager, User **user) {
    string username, password;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        if (choice == 1 || choice == 2) {
            cout << "Enter username : ";
            cin >> username;

            cout << "Enter password : ";
            cin >> password;

            *user = choice == 1 ? userManager.findUser(username, true) : userManager.findUser(username, false);

            if (*user && (*user)->authenticate(password)) {
                cout << "Successfully login as " << (choice == 1 ? "a Customer" : "an Admin") << endl << endl;
                return choice == 1 ? CUSTOMER : ADMIN;
            }

            cout << "your login credentials don't match an account in your system. Try Again!" << endl << endl;
        } else if (choice == 3) {
            cout << "Enter username : ";
            cin >> username;

            cout << "Enter password : ";
            cin >> password;

            if (userManager.registerUser(username, password)) {
                cout << "Successfully Registered  into system" << endl << endl;
                continue;
            }
            cout << "Can not register. Try Again!" << endl << endl;
        }
        else if (choice == 4){
            return 4;
        }
    } while (true);
}

