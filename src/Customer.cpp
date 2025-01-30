#include <CustomLibraries.hpp>

using namespace std;

Customer::Customer(string &name, string &email, string &password) : User(name, email, password) {};

Customer::~Customer() {};

bool Customer::getUser(string email) const
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

            // if (arquivo == "data/admins.txt")
            // {
            //     return new Admin(nomeArquivo, emailArquivo, passwordArquivo);
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

bool Customer::createNewUser() const
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

    file << email << ";" << username << ";" << password << "\n";
    file.close();
    return true;
}
