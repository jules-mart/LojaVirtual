#include <iostream>
#include <string>
using namespace std;

// Classe User (abstrata)
class User {
protected:
    string name;
    string email;

public:
    // Construtor
    User(const string& name, const string& email)
        : name(name), email(email) {}

    // M�todos para acessar os atributos
    string get_name() const {
        return name;
    }

    string get_email() const {
        return email;
    }

    // M�todos para modificar os atributos
    void set_name(const string& new_name) {
        name = new_name;
    }

    void set_email(const string& new_email) {
        email = new_email;
    }

    // M�todo virtual puro
    virtual void display_role() const = 0;  // M�todo abstrato
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
