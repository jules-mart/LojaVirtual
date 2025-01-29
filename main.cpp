#include <iostream>
#include <string>
#include "User.h"  // Incluindo a classe User.h

int main() {
    // Criando um administrador e um cliente
    Administrator admin("Alice", "alice@example.com");
    Client client("Bob", "bob@example.com");

    // Exibindo os dados iniciais
    cout << "Info do Administrador:" << endl;
    cout << "Nome: " << admin.get_name() << endl;
    cout << "Email: " << admin.get_email() << endl;
    admin.display_role();

    cout << endl;

    cout << "Info do Cliente:" << endl;
    cout << "Nome: " << client.get_name() << endl;
    cout << "Email: " << client.get_email() << endl;
    client.display_role();

    cout << "\n--- Modificando os dados do Cliente ---\n";
    client.set_name("Robert");
    client.set_email("robert@example.com");

    // Exibindo os novos dados do cliente
    cout << "Info sobre updtade de dados do Cliente:" << endl;
    cout << "Nome: " << client.get_name() << endl;
    cout << "Email: " << client.get_email() << endl;
    client.display_role();

    return 0;
}
