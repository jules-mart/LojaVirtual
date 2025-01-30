#ifndef ADMIN_HPP
#define ADMIN_HPP

#include <ExternalLibraries.hpp>
#include <CustomLibraries.hpp>

class Admin : public User
{
public:
    Admin(std::string &name, std::string &email, std::string &password);
    ~Admin();

    static bool login(std::string loginEmail, std::string loginPassword);
    static bool getUser(std::string email);
    static bool createNewUser(std::string name, std::string email, std::string password);
};

#endif
