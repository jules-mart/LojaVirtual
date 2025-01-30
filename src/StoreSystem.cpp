#include <StoreSystem.hpp>
using namespace std;

StoreSystem::StoreSystem(const string &name) : storeName(name)
{
    cout << "Initializing system..." << endl;
    cout << "The store '" << storeName << "' is now open." << endl;
}

StoreSystem::~StoreSystem()
{
    cout << "Desabling store '" << storeName << "'..." << endl;
}

void StoreSystem::clear()
{
    system("clear");
    cout << "Store '" << storeName << "'" << endl;
    cout << endl;
}

int StoreSystem::run(void)
{
    cout << endl;
    cout << "Welcome to the store '" << storeName << "'!" << endl;
    cout << endl;
    while (true)
    {
        int choice;
        cout << "To start, you must identify yourself:" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Customer" << endl;
        cout << "3. Create a new account" << endl;
        cout << "4. Exit" << endl;

        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        StoreSystem::clear();
        string email, password;
        switch (choice)
        {
        case 1:
            cout << "--- Admin menu ---" << endl;
            cout << "Enter your email: ";
            cin >> email;
            cout << "Enter your password: ";
            cin >> password;
            break;
        case 2:
            cout << "--- Customer menu ---" << endl;
            cout << "Enter your email: ";
            cin >> email;
            cout << "Enter your password: ";
            cin >> password;
            break;
        case 3:
            cout << "--- New customer menu ---" << endl;
            cout << "Enter your email: ";
            cin >> email;
            cout << "Enter your password: ";
            cin >> password;
            break;
        case 4:
            cout << "Exiting..." << endl;
            return 0;
        default:
            break;
        }
        cout << "Email: " << email << endl;
        cout << "Password: " << password << endl;
    }
}