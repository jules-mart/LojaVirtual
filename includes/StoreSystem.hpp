#ifndef STORE_SYSTEM_HPP
#define STORE_SYSTEM_HPP

#include <ExternalLibraries.hpp>

class StoreSystem
{
private:
    std::string storeName;

public:
    StoreSystem(const std::string &name) : storeName(name) {
        std::cout << "Initializing system..." << std::endl;
        std::cout << "The store '" << storeName << "' is now open." << std::endl;
    }
};

#endif
