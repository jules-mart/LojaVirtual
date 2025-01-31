#include <CustomLibraries.hpp>
using namespace std;

Cart::Cart() {};

void Cart::displayCartProducts(void)
{
    cout << "Products in the cart: " << endl;

    for (Product product : products)
    {
        cout << product.getId() << " - " << product.getName() << " - R$" << product.getPrice() << " - " << product.getQuantity() << endl;
    }
}

void Cart::addProductToCart(Product product)
{
    products.push_back(product);
}

void Cart::clear()
{
    products.clear();
}
