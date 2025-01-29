#include <iostream>
#include <string>
#include "User.h"  // Incluindo a classe User.h

int main() {
    // Criação de objetos das subclasses
    Administrator admin("Alice", "alice@example.com");
    Client client("Bob", "bob@example.com");

    // Teste dos métodos
    cout << "Admin Info:" << endl;
    cout << "Name: " << admin.get_name() << endl;
    cout << "Email: " << admin.get_email() << endl;
    admin.display_role();

    cout << endl;

    cout << "Client Info:" << endl;
    cout << "Name: " << client.get_name() << endl;
    cout << "Email: " << client.get_email() << endl;
    client.display_role();

    return 0;
}
