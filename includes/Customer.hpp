#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <ExternalLibraries.hpp>
#include <CustomLibraries.hpp>
#include <User.hpp>
#include <Cart.hpp>

class Customer : public User
{

public:
    Customer(const std::string &username, const std::string &email, const std::string &password);
    Customer(const std::string &email, const std::string &password);
    ~Customer();

    void addProductToCart(Product product, int quantity);
    void clearCart();
    Cart cart;

    static bool login(std::string loginEmail, std::string loginPassword);
    static bool createNewUser(const std::string &name, const std::string &email, const std::string &password);
    static Customer getUser(const std::string &email);

    std::string getEmail();
    std::string getName();
    void setEmail(const std::string &email);
    void setName(const std::string &name);
};

#endif
