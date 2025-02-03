#ifndef CART_HPP
#define CART_HPP

#include <CustomLibraries.hpp>
#include <Product.hpp>

class Cart
{
private:
    float total;
    std::vector<Product> products;
    

public:
    Cart();
    void displayCartProducts();
    void addProductToCart(Product product, int quantity);
    bool removeProductFromCart(int productId, int quantity); // Nova função
    void clear();

    std::vector<Product> getProducts();
    void sumTotal(float price);
    float getTotal();
    int getProductQuantity(int productId);
    void checkout();
};

#endif
