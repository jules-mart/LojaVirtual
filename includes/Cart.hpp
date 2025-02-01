#ifndef CART_HPP
#define CART_HPP

#include <CustomLibraries.hpp>

class Cart
{
private:
    float total;
    std::vector<Product> products;

public:
    Cart();
    void displayCartProducts();
    void addProductToCart(Product product, int quantity);
    void clear();
};

#endif