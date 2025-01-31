#include <CustomLibraries.hpp>

using namespace std;

Admin::Admin(const string &username, const string &email, const string &password) : User(username, email, password) {};

Admin::~Admin() {};

bool Admin::login(string loginEmail, string loginPassword)
{
    ifstream file("data/admin.txt");
    if (!file.is_open())
    {
        cerr << "Error: could not open file 'data/admin.txt'." << endl;
        return false;
    }

    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        string email, username, password;
        getline(iss, email, ';');
        getline(iss, username, ';');
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

bool Admin::createNewUser(const string &username, const string &email, const string &password)
{
    if (Admin::getUser(email).getEmail() == "")
    {
        return false;
    }

    ofstream file("data/admin.txt", ios::app);
    if (!file.is_open())
    {
        return false;
    }

    file << email << ";" << username << ";" << password << "\n";
    file.close();
    return true;
}

Admin Admin::getUser(const string &email)
{
    std::ifstream file("data/admin.txt");
    if (!file.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        // Retorna um Admin padrão indicando erro
        return Admin("", "", "");
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string usernameInFile, emailInFile, passwordInFile;

        // Extrai os campos separados por ';'
        if (std::getline(iss, emailInFile, ';') &&
            std::getline(iss, usernameInFile, ';') &&
            std::getline(iss, passwordInFile, ';'))
        {

            // Compara o email
            if (email == emailInFile)
            {
                return Admin(usernameInFile, emailInFile, passwordInFile);
            }
        }
    }

    // Retorna um Admin padrão indicando usuário não encontrado
    return Admin("", "", "");
}

std::string Admin::getName()
{
    return username;
}
std::string Admin::getEmail()
{
    return email;
}
void Admin::setEmail(const std::string &Email)
{
    email = Email;
}
void Admin::setName(const std::string &Name)
{
    username = Name;
}