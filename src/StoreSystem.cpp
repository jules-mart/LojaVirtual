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
        string name, email, password;
        bool canLogIn = false, userCreated = false;
        switch (choice)
        {
        case 1:
            cout << "--- Admin menu ---" << endl;
            cout << "Enter your email: ";
            cin >> email;
            cout << "Enter your password: ";
            cin >> password;
            canLogIn = Admin::login(email, password);
            if (canLogIn)
            {
                cout << "Credentials validated. Log in as admin..." << endl;
            }
            else
            {
                cout << "Invalid credentials. Try again." << endl;
            }
            break;
        case 2:
            cout << "--- Customer menu ---" << endl;
            cout << "Enter your email: ";
            cin >> email;
            cout << "Enter your password: ";
            cin >> password;
            canLogIn = Customer::login(email, password);
            if (canLogIn)
            {
                cout << "Credentials validated. Log in as customer..." << endl;

                customerMenuLoop(Customer(email, password));
            }
            else
            {
                cout << "Invalid credentials. Try again." << endl;
            }
            break;
        case 3:
            cout << "--- New customer menu ---" << endl;
            cout << "Enter your name: ";
            cin >> name;
            cout << "Enter your email: ";
            cin >> email;
            cout << "Enter your password: ";
            cin >> password;
            userCreated = Customer::createNewUser(name, email, password);
            if (userCreated)
            {
                cout << "Account created successfully. Now, you can log in as a customer" << endl;
            }
            else
            {
                cout << "Email already in use. Try again with another one." << endl;
            }
            break;
        case 4:
            cout << "Exiting..." << endl;
            return 0;
        default:
            break;
        }
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
        string id, quantity, name, price;

        getline(iss, id, ';');
        getline(iss, name, ';');
        getline(iss, price, ';');
        getline(iss, quantity, ';');

        if (!id.empty() && !name.empty() && !price.empty() && !quantity.empty())
        {
            Product product(stoi(id), name, stof(price), stoi(quantity));
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

void StoreSystem::customerMenuLoop(Customer customer)
{

    customer.clearCart(); // Reset cart for new session

    while (true)
    {
        int choice;
        cout << "\nCustomer Menu:" << endl;
        cout << "1. View Products" << endl;
        cout << "2. Add to Cart" << endl;
        cout << "3. View Cart" << endl;
        cout << "4. Checkout" << endl;
        cout << "5. Logout" << endl;

        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        StoreSystem::clear();

        switch (choice)
        {
        case 1:
            listProducts();
            break;
        case 2:
            int id;
            cout << "Which product do you want to add?" << endl;
            listProducts();
            cout << "(Type the id of the product)" << endl;
            cin >> id;
            customer.addProduct(StoreSystem::getProductById(id));
            break;
        case 3:
            customer.cart.displayCartProducts();
            break;
        case 4:
            // checkout();
            break;
        case 5:
            cout << "Logging out..." << endl;
            return; // Return to main menu
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }
}

Product StoreSystem::getProductById(int id)
{
    std::ifstream file("data/product.txt");
    if (!file.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        // Retorna um Admin padrão indicando erro
        return Product(0, "", 0, 0);
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string idInFile, nameInFile, priceInFile, quantityInFile;

        // Extrai os campos separados por ';'
        if (std::getline(iss, idInFile, ';') &&
            std::getline(iss, nameInFile, ';') &&
            std::getline(iss, priceInFile, ';') &&
            std::getline(iss, quantityInFile, ';'))
        {

            // Compara o email
            if (id == stoi(idInFile))
            {
                return Product(stoi(idInFile), nameInFile, stof(priceInFile), stoi(quantityInFile));
            }
        }
    }

    // Retorna um Admin padrão indicando usuário não encontrado
    return Product(0, "", 0, 0);
}