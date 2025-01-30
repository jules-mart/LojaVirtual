#ifndef ADMIN_HPP
#define ADMIN_HPP

#include <ExternalLibraries.hpp>
#include <CustomLibraries.hpp>

class Admin : public User
{
public:
    Admin(std::string &name, std::string &email, std::string &password);
    ~Admin();

    bool getUser(std::string email) const override;
    bool createNewUser() const override;
};

#endif
