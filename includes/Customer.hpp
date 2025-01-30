#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <ExternalLibraries.hpp>
#include <CustomLibraries.hpp>

class Customer : public User
{
public:
    Customer(std::string &nome, std::string &email, std::string &password);
    ~Customer();

    bool getUser(std::string email) const override;
    bool createNewUser() const override;
};

#endif
