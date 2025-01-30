#include <CustomLibraries.hpp>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "To initialize the program, you must provide the store`s name:" << std::endl;
        std::cout << "'./store <STORE_NAME>'" << std::endl;
        return 1;
    }

    system("clear");
    StoreSystem store(argv[1]);

    std::string name = "João Silva";
    std::string email = "joao@gmail.com";
    std::string password = "senha123";

    Admin admin(name, email, password);

    if (admin.createNewUser())
    {
        std::cout << "Admin adicionado com sucesso!" << std::endl;
    }
    else
    {
        std::cout << "Erro: Admin já existe ou falha ao abrir o arquivo." << std::endl;
    }

    store.run();
}
