#include "UserManager.h"
#include "file-manager.h"

UserManager::UserManager(string user_filename, string admin_filename) {
    this->users = loadCustomersFromFile(user_filename);
    this->admins = loadAdminsFromFile(admin_filename);
}

bool UserManager::registerUser(string username, string password) {
    if (password.length() < 4){
        cout << "Password must have at least four figures" << endl;
        return false;
    }

    Customer user(users.getCount()+1, username, password, 0);
    Customer * tempUser = users.search(user);
    if (tempUser == nullptr){
        this->users.insert(user);
        return true;
    }
    return false;

}

User *UserManager::findUser(std::string username, bool isCustomer) {
    if (isCustomer) {
        return users.search(Customer(username));
    } else {
        return admins.search(Admin(username));
    }
}

void UserManager::displayUsers() {
    users.displayInOrder();
}