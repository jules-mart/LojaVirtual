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
    User(const std::string &name, const std::string &email, const std::string &password);

    // virtual bool login(std::string loginEmail, std::string loginPassword) const = 0;
    // virtual bool getUser(std::string email) const = 0;
    // virtual bool createNewUser() const = 0;
};

#endif
