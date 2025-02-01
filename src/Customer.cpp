#include <CustomLibraries.hpp>

using namespace std;

Customer::Customer(const string &name, const string &email, const string &password) : User(name, email, password) {};
Customer::Customer(const string &email, const string &password) : User(email, password) {};

Customer::~Customer() {};

bool Customer::login(string loginEmail, string loginPassword)
{
    ifstream file("data/customer.txt");
    if (!file.is_open())
    {
        cerr << "Error: could not open file 'data/product.txt'." << endl;
        return false;
    }

    string line;
    while (getline(file, line))
    {

        istringstream iss(line);
        string email, name, password;
        getline(iss, email, ';');
        getline(iss, name, ';');
        getline(iss, password, ';');

        if (email == loginEmail && password == loginPassword)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

bool Customer::createNewUser(const std::string &name, const std::string &email, const std::string &password)
{
    if (getUser(email).getEmail() != "")
    {
        return false;
    }

    ofstream file("data/customer.txt", ios::app);
    if (!file.is_open())
    {
        return false;
    }

    file << email << ";" << name << ";" << password << "\n";
    file.close();
    return true;
}

Customer Customer::getUser(const std::string &Email)
{
    std::ifstream file("data/customer.txt");
    if (!file.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        return Customer("", "", "");
    }

    std::string line;
    while (getline(file, line))
    {
        std::istringstream iss(line);
        std::string usernameInFile, emailInFile, passwordInFile;

        // Extrai os campos separados por ';'
        if (std::getline(iss, emailInFile, ';') &&
            std::getline(iss, usernameInFile, ';') &&
            std::getline(iss, passwordInFile, ';'))
        {

            // Compara o email
            if (Email == emailInFile)
            {
                return Customer(usernameInFile, emailInFile, passwordInFile);
            }
        }
    }

    // Retorna um Admin padrão indicando usuário não encontrado
    return Customer("", "", "");
}

std::string Customer::getName()
{
    return username;
}
std::string Customer::getEmail()
{
    return email;
}

void Customer::addProductToCart(Product product, int quantity)
{
    if (product.getId() > 0)
    {
        cart.addProductToCart(product, quantity);
    }
}

void Customer::clearCart()
{
    cart.clear();
}