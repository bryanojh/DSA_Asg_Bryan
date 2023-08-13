#ifndef RESTAURANT_FOOD_H
#define RESTAURANT_FOOD_H

#include <string>
#include <ostream>

using namespace std;

class Food {
private:
    int _food_id{};
    string _food_name;
    double _price{};

public:
    Food();

    Food(int foodId, string foodName, double price);

    int getFoodId() const;

    void setFoodId(int foodId);

    const string &getFoodName() const;

    void setFoodName(const string &foodName);

    double getPrice() const;

    void setPrice(double price);

    bool operator<(const Food &rhs) const;

    bool operator>(const Food &rhs) const;

    bool operator<=(const Food &rhs) const;

    bool operator>=(const Food &rhs) const;

    bool operator==(const Food &rhs) const;

    bool operator!=(const Food &rhs) const;

    friend ostream &operator<<(ostream &os, const Food &food);
};


#endif //RESTAURANT_FOOD_H
