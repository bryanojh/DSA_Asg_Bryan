#ifndef RESTAURANT_USER_H
#define RESTAURANT_USER_H

#include <string>
#include <ostream>

using namespace std;
class User {
private:
    int _user_id;
    string _username;
    string _password;

public:
    User(const string &username);

    User(const string &username, const string &password);

    User(int userId, const string &username, const string &password);

    int getUserId() const;

    void setUserId(int userId);

    string getUsername() const;

    void setUsername(const string &username);

    const string &getPassword() const;

    void setPassword(const string &password);

    bool authenticate(string password);

    bool operator<(const User &rhs) const;

    bool operator>(const User &rhs) const;

    bool operator<=(const User &rhs) const;

    bool operator>=(const User &rhs) const;

    bool operator==(const User &rhs) const;

    bool operator!=(const User &rhs) const;

    virtual void printDetails();
};


#endif //RESTAURANT_USER_H
