#include <User.hpp>
#include <Admin.hpp>
#include <Costumer.hpp>

User::User(std::string &name, std::string &email, std::string &password) : Name(name), Email(email), Password(password) {};

bool User::getUser(std::string email, const std::string &arquivo)
{
    std::ifstream file(arquivo); // Abre o arquivo para leitura
    std::string linha;

    while (std::getline(file, linha))
    { // Lê cada linha do arquivo
        std::istringstream iss(linha);
        std::string emailArquivo, nomeArquivo, passwordArquivo;

        // Extrai os dados da linha
        std::getline(iss, emailArquivo, ' ');
        std::getline(iss, nomeArquivo, ' ');
        std::getline(iss, passwordArquivo, ' ');

        if (emailArquivo == email)
        { // Verifica se o email já existe
            file.close();

            return true;

            // if (arquivo == "data/admins.txt")
            // {
            //     return new Admin(nomeArquivo, emailArquivo, passwordArquivo);
            // }
            // else if (arquivo == "data/costumer.txt")
            // {
            //     return new Costumer(nomeArquivo, emailArquivo, passwordArquivo);
            // }
        }
    }

    file.close();
    return false; // Usuário não existe
}