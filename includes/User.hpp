#ifndef USER_HPP
#define USER_HPP

#include <ExternalLibraries.hpp>

class User
{
protected:
    std::string Name;
    std::string Email;
    std::string Password;

public:
    User(std::string &nome, std::string &email, std::string &password);

    static bool getUser(std::string email, const std::string &arquivo);

    virtual bool createNewUser() const = 0;
};

#endif