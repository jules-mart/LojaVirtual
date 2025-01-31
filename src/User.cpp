#include <CustomLibraries.hpp>

User::User(const std::string &username, const std::string &email, const std::string &password)
    : username(username), email(email), password(password) {};

User::User(const std::string &email, const std::string &password) : email(email), password(password) {};