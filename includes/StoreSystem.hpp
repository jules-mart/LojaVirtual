#ifndef STORE_SYSTEM_HPP
#define STORE_SYSTEM_HPP

#include <ExternalLibraries.hpp>

class StoreSystem
{
private:
    std::string storeName;

public:
    StoreSystem(const std::string &name);
    ~StoreSystem();

    int run(void);
    void clear();
};

#endif
