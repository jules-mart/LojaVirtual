#include <ExternalLibraries.hpp>

class Product {
    private:
        std::string id;
        std::string name;
        double price;
        int quantity;

    public:
        Product(std::string id, std::string name, double price, int quantity);
        ~Product();

        std::string getId();
        std::string getName();
        double getPrice();
        int getQuantity();

        void setId(std::string id);
        void setName(std::string name);
        void setPrice(double price);
        void setQuantity(int quantity);
};
