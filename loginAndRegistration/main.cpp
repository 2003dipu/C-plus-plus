#include <iostream>
#include <fstream>

using namespace std;

class User
{
public:
    string username;
    string password;

    User(string username, string password)
    {
        this->username = username;
        this->password = password;
    }
};

void registerUser(string username, string password)
{
    ofstream outfile("users.txt", ios::app);
    outfile << username << "," << password << endl;
    outfile.close();
}

User *loginUser(string username, string password)
{
    ifstream infile("users.txt");
    string line;

    while (getline(infile, line))
    {
        size_t pos = line.find(",");
        string usernameFromFile = line.substr(0, pos);
        string passwordFromFile = line.substr(pos + 1);

        if (usernameFromFile == username && passwordFromFile == password)
        {
            return new User(usernameFromFile, passwordFromFile);
        }
    }

    return nullptr;
}

int main()
{
    string username;
    string password;
    cout << "Welcome to the login and registration system!" << endl;

    int choice = 0;
    while (choice != 3)
    {
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            cout << "Enter a username: ";
            cin >> username;

            cout << "Enter a password: ";
            cin >> password;

            registerUser(username, password);
            cout << "\n---------------------------------------------------------\n";
            cout << "You have been registered successfully!" << endl;
            cout << "\n---------------------------------------------------------\n";
            break;

        case 2:
            username = "";
            password = "";

            cout << "Enter your username: ";
            cin >> username;

            cout << "Enter your password: ";
            cin >> password;

            User *user = loginUser(username, password);

            if (user != nullptr)
            {
                cout << "Welcome, " << user->username << "!" << endl;

                // TODO: Grant the user access to the application here
            }
            else
            {
                cout << "Invalid username or password." << endl;
            }
            break;
        }
        break;
    }

    return 0;
}
