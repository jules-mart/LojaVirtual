#ifndef COSTUMER_HPP
#define COSTUMER_HPP

#include <ExternalLibraries.hpp>
#include <CustomLibraries.hpp>

class Costumer : public User
{
    Costumer(std::string &nome, std::string &email, std::string &password);

    bool createNewUser() const override;
};

#endif