#include <CustomLibraries.hpp>

using namespace std;

Product::Product(std::string id, std::string name, double price, int quantity) : id(id), name(name), price(price), quantity(quantity)
{
}
Product::~Product() {};

std::string Product::getId() {
    return this->id;
};
std::string Product::getName() {
    return this->name;
};
double Product::getPrice() {
    return this->price;
};
int Product::getQuantity() {
    return this->quantity;
};

void Product::setId(std::string id) {
    this->id = id;
};
void Product::setName(std::string name) {
    this->name = name;
};
void Product::setPrice(double price) {
    this->price = price;
};
void Product::setQuantity(int quantity) {
    this->quantity = quantity;
};
