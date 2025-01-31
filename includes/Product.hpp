#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <ExternalLibraries.hpp>

class Product
{
private:
    int id;
    std::string name;
    float price;
    int quantity;

public:
    Product(int id, std::string name, float price, int quantity);
    ~Product();

    int getId();
    std::string getName();
    float getPrice();
    int getQuantity();

    void setId(int id);
    void setName(std::string name);
    void setPrice(float price);
    void setQuantity(int quantity);

    
};

#endif