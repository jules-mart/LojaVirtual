#include <iostream>
#include <string>
using namespace std;

// Classe User
class User {
protected:
    string name;
    string email;

public:
    // Construtor
    User(const string& name, const string& email)
        : name(name), email(email) {}

    // Métodos para acessar os atributos
    string get_name() const {
        return name;
    }

    string get_email() const {
        return email;
    }

    // Método virtual puro
    virtual void display_role() const = 0;  // Método abstrato
};

// Subclasse Administrator
class Administrator : public User {
public:
    Administrator(const string& name, const string& email)
        : User(name, email) {}

    void display_role() const override {
        cout << "Administrator: " << get_name() << endl;
    }
};

// Subclasse Client
class Client : public User {
public:
    Client(const string& name, const string& email)
        : User(name, email) {}

    void display_role() const override {
        cout << "Client: " << get_name() << endl;
    }
};
