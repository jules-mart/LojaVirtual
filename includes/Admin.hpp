#ifndef ADMIN_HPP
#define ADMIN_HPP

#include <ExternalLibraries.hpp>
#include <CustomLibraries.hpp>

class Admin : public User
{
public:
    Admin(const std::string &name, const std::string &email, const std::string &password);
    ~Admin();

    static bool login(std::string loginEmail, std::string loginPassword);
    static bool createNewUser(const std::string &name, const std::string &email, const std::string &password);
    static Admin getUser(const std::string &email);

    std::string getName();
    std::string getEmail();
    void setName(const std::string &name);
    void setEmail(const std::string &email);
};

#endif
