#include <CustomLibraries.hpp>
using namespace std;

Cart::Cart() : total(0) {};

void Cart::displayCartProducts(void)
{
    cout << "Products in the cart: " << endl;

    if (products.empty())
    {
        cout << "   <Empty>\n" << endl;
    }
    else
    {
        for (Product product : products)
        {
            product.printProduct();
        }
    }

    cout << "Total: R$" << getTotal() << endl;
}

void Cart::addProductToCart(Product product, int quantity)
{
    for (Product &p : products)
    {
        if (p.getId() == product.getId())
        {
            p.setQuantity(p.getQuantity() + quantity);
            sumTotal(p.getPrice() * quantity);
            return;
        }
    }
    sumTotal(product.getPrice() * quantity);
    product.setQuantity(quantity);
    products.push_back(product);
}

bool Cart::removeProductFromCart(int productId, int quantity)
{
    auto it = std::find_if(products.begin(), products.end(),
                           [productId](Product &p)
                           { return p.getId() == productId; });

    if (it != products.end())
    {
        int newQuantity = it->getQuantity() - quantity;

        if (newQuantity <= 0)
        {
            products.erase(it);
        }
        else
        {
            it->setQuantity(newQuantity);
        }
        return true;
    }
    return false;
}

void Cart::checkout()
{
    displayCartProducts();
}

void Cart::clear()
{
    products.clear();
}

void Cart::sumTotal(float price)
{
    total += price;
}

int Cart::getProductQuantity(int productId)
{
    for (Product &product : products)
    {
        if (product.getId() == productId)
        {
            return product.getQuantity();
        }
    }
    return 0; // Retorna 0 se não encontrado
}

std::vector<Product> Cart::getProducts()
{
    return products;
}

float Cart::getTotal()
{
    return total;
}
