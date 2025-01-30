#ifndef USER_HPP
#define USER_HPP

#include <ExternalLibraries.hpp>

class User
{
protected:
    std::string username;
    std::string email;
    std::string password;

public:
    User(std::string &name, std::string &email, std::string &password);

    virtual bool getUser(std::string email) const = 0;
    virtual bool createNewUser() const = 0;
};

#endif
