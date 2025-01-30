#include <CustomLibraries.hpp>

using namespace std;

Customer::Customer(string &name, string &email, string &password) : User(name, email, password) {};

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

bool Customer::getUser(string email)
{
    ifstream file("data/customer.txt");
    string linha;

    while (getline(file, linha))
    {
        istringstream iss(linha);
        string emailArquivo, nomeArquivo, passwordArquivo;

        getline(iss, emailArquivo, ';');
        getline(iss, nomeArquivo, ';');
        getline(iss, passwordArquivo, ';');

        if (emailArquivo == email)
        {
            file.close();

            return true;

            // if (arquivo == "data/customers.txt")
            // {
            //     return new customer(nomeArquivo, emailArquivo, passwordArquivo);
            // }
            // else if (arquivo == "data/customer.txt")
            // {
            //     return new Customer(nomeArquivo, emailArquivo, passwordArquivo);
            // }
        }
    }

    file.close();
    return false;
}

bool Customer::createNewUser(std::string name, std::string email, std::string password)
{
    if (getUser(email))
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
