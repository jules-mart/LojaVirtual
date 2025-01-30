#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <ExternalLibraries.hpp>
#include <CustomLibraries.hpp>

class Customer : public User
{
public:
    Customer(std::string &nome, std::string &email, std::string &password);
    ~Customer();

    static bool login(std::string loginEmail, std::string loginPassword);
    static bool createNewUser(std::string name, std::string email, std::string password);
    static bool getUser(std::string email);
};

#endif
