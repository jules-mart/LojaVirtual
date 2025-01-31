#ifndef STORE_SYSTEM_HPP
#define STORE_SYSTEM_HPP

#include <ExternalLibraries.hpp>
#include <CustomLibraries.hpp>
#include <Customer.hpp>

class StoreSystem
{
private:
    std::string storeName;
    std::vector<Product> products;

public:
    StoreSystem(const std::string &name);
    ~StoreSystem();

    int run(void);
    void clear();

    void loadProducts(void);
    void listProducts(void);
    void customerMenuLoop(Customer customer);

    static Product getProductById(int id);
};

#endif
