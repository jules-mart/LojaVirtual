#ifndef USER_HPP
#define USER_HPP

#include <ExternalLibraries.hpp>

class User
{
protected:
    std::string name;
    std::string email;
    std::string password;

public:
    virtual bool getUser(std::string email) const = 0;
    virtual bool createNewUser() const = 0;
};

#endif
