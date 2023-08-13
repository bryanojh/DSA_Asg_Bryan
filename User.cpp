#include "User.h"
User::User(const std::string &username) {
    this->_username = username;
}

User::User(const string &username, const string &password) : _username(username), _password(password) {}

User::User(int userId, const string &username, const string &password) : _user_id(userId), _username(username),
                                                                         _password(password) {}

int User::getUserId() const {
    return _user_id;
}

void User::setUserId(int userId) {
    _user_id = userId;
}

string User::getUsername() const {
    return _username;
}

void User::setUsername(const string &username) {
    _username = username;
}

const string &User::getPassword() const {
    return _password;
}

void User::setPassword(const string &password) {
    _password = password;
}

bool User::authenticate(std::string password) {
    return this->_password == password;
}

bool User::operator<(const User &rhs) const {
    return _username < rhs._username;
}

bool User::operator>(const User &rhs) const {
    return rhs < *this;
}

bool User::operator<=(const User &rhs) const {
    return !(rhs < *this);
}

bool User::operator>=(const User &rhs) const {
    return !(*this < rhs);
}

bool User::operator==(const User &rhs) const {
    return _username == rhs._username;
}

bool User::operator!=(const User &rhs) const {
    return !(rhs == *this);
}


void User::printDetails() {

}

