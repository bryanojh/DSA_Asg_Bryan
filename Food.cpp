#include "Food.h"
#include <iomanip>

Food::Food() {}

Food::Food(int foodId, string foodName, double price) : _food_id(foodId), _food_name(std::move(foodName)), _price(price) {}

int Food::getFoodId() const {
    return _food_id;
}

void Food::setFoodId(int foodId) {
    _food_id = foodId;
}

const string &Food::getFoodName() const {
    return _food_name;
}

void Food::setFoodName(const string &foodName) {
    _food_name = foodName;
}

double Food::getPrice() const {
    return _price;
}

void Food::setPrice(double price) {
    Food::_price = price;
}

bool Food::operator<(const Food &rhs) const {
    if (_food_name < rhs._food_name)
        return true;
    if (rhs._food_name < _food_name)
        return false;
    return _price < rhs._price;
}

bool Food::operator>(const Food &rhs) const {
    return rhs < *this;
}

bool Food::operator<=(const Food &rhs) const {
    return !(rhs < *this);
}

bool Food::operator>=(const Food &rhs) const {
    return !(*this < rhs);
}

ostream &operator<<(ostream &os, const Food &food) {
    os << left <<setw(6) << food._food_id << setw(20) << food._food_name << setw(10) << food._price;
    return os;
}

bool Food::operator==(const Food &rhs) const {
    return _food_id == rhs._food_id;

}

bool Food::operator!=(const Food &rhs) const {
    return !(rhs == *this);
}



