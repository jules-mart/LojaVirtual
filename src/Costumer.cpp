#include <Costumer.hpp>
#include <User.hpp>

Costumer::Costumer(std::string &name, std::string &email, std::string &password) : User(name, email, password) {};

bool Costumer::createNewUser() const
{
    if (User::getUser(Email, "data/costumer.txt"))
    {
        return false; // Usuário já existe
    }

    std::ofstream file("data/costumer.txt", std::ios::app); // Abre o arquivo em modo de append
    if (!file.is_open())
    {
        return false; // Erro ao abrir o arquivo
    }

    file << Email << " " << Name << " " << Password << "\n"; // Escreve os dados no arquivo
    file.close();
    return true; // Usuário adicionado com sucesso
}