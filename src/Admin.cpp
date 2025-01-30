#include <Admin.hpp>
#include <User.hpp>

Admin::Admin(std::string &name, std::string &email, std::string &password) : User(name, email, password) {};

bool Admin::createNewUser() const
{
    if (User::getUser(Email, "data/admins.txt"))
    {
        return false; // Usuário já existe
    }

    std::ofstream file("data/admin.txt", std::ios::app); // Abre o arquivo em modo de append
    if (!file.is_open())
    {
        return false; // Erro ao abrir o arquivo
    }

    file << Email << " " << Name << " " << Password << "\n"; // Escreve os dados no arquivo
    file.close();
    return true; // Usuário adicionado com sucesso
}