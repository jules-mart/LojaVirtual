#include <Admin.hpp>
#include <User.hpp>

using namespace std;

Admin::Admin(string &name, string &email, string &password) : Admin(name, email, password) {};

Admin::~Admin() {};

bool Admin::getUser(string email) const
{
    ifstream file("data/admin.txt");
    string linha;

    while (getline(file, linha))
    {
        istringstream iss(linha);
        string emailArquivo, nomeArquivo, passwordArquivo;

        getline(iss, emailArquivo, ' ');
        getline(iss, nomeArquivo, ' ');
        getline(iss, passwordArquivo, ' ');

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

bool Admin::createNewUser() const
{
    if (getUser(this->email))
    {
        return false;
    }

    ofstream file("data/admin.txt", ios::app);
    if (!file.is_open())
    {
        return false;
    }

    file << email << " " << name << " " << password << "\n";
    file.close();
    return true;
}
