#include <CustomLibraries.hpp>

using namespace std;

Product::Product(int id, std::string name, float price, int quantity) : id(id), name(name), price(price), quantity(quantity)
{
}

Product::Product() {};

Product::~Product() {};

int Product::getId()
{
    return id;
};
std::string Product::getName()
{
    return name;
};
float Product::getPrice()
{
    return price;
};
int Product::getQuantity()
{
    return quantity;
};

void Product::setId(int id)
{
    this->id = id;
};
void Product::setName(std::string name)
{
    this->name = name;
};
void Product::setPrice(float price)
{
    this->price = price;
};
void Product::setQuantity(int quantity)
{
    this->quantity = quantity;
};

bool Product::isValidProduct()
{
    if (this->id != 0 && this->name != "" && this->price != 0 && this->quantity != 0)
    {
        return true;
    }
    return false;
};