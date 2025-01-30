#include <CustomLibraries.hpp>
using namespace std;

StoreSystem::StoreSystem(const string &name) : storeName(name)
{
    cout << "Initializing system..." << endl;
    cout << "The store '" << storeName << "' is now open." << endl;
    loadProducts();
}

StoreSystem::~StoreSystem()
{
    cout << "Desabling store '" << storeName << "'..." << endl;
}

void StoreSystem::clear()
{
    system("clear");
    cout << "Store '" << storeName << "'" << endl;
    cout << endl;
}

int StoreSystem::run(void)
{
    cout << endl;
    cout << "Welcome to the store '" << storeName << "'!" << endl;
    cout << endl;
    while (true)
    {
        int choice;
        cout << "To start, you must identify yourself:" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Customer" << endl;
        cout << "3. Create a new account" << endl;
        cout << "4. Exit" << endl;

        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        StoreSystem::clear();
        string email, password;
        switch (choice)
        {
        case 1:
            cout << "--- Admin menu ---" << endl;
            cout << "Enter your email: ";
            cin >> email;
            cout << "Enter your password: ";
            cin >> password;
            break;
        case 2:
            cout << "--- Customer menu ---" << endl;
            cout << "Enter your email: ";
            cin >> email;
            cout << "Enter your password: ";
            cin >> password;
            break;
        case 3:
            cout << "--- New customer menu ---" << endl;
            cout << "Enter your email: ";
            cin >> email;
            cout << "Enter your password: ";
            cin >> password;
            break;
        case 4:
            cout << "Exiting..." << endl;
            return 0;
        default:
            break;
        }
        cout << "Email: " << email << endl;
        cout << "Password: " << password << endl;
    }
}

void StoreSystem::loadProducts(void)
{
    ifstream file("data/product.txt");
    if (!file.is_open())
    {
        cerr << "Error: could not open file 'data/product.txt'." << endl;
        return;
    }

    products.clear();
    string line;
    while (getline(file, line))
    {

        istringstream iss(line);
        int id, quantity;
        string name;
        float price;

        if (iss >> id >> name >> price >> quantity)
        {
            Product product(id, name, price, quantity);
            products.push_back(product);
        }
        else
        {
            cerr << "Error: Invalid product format in file: " << line << endl;
        }
    }
    file.close();
}

void StoreSystem::listProducts(void)
{
    loadProducts();
    cout << "Products available:" << endl;
    for (Product product : products)
    {
        cout << product.getId() << " - " << product.getName() << " - R$" << product.getPrice() << " - " << product.getQuantity() << endl;
    }
}
