#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Structure to represent a user
struct User
{
    string username;
    string password;
};

// Function to register a new user
void registerUser(vector<User> &users)
{
    User newUser;
    cout << "Enter a username: ";
    cin >> newUser.username;

    // Check if the username already exists
    for (const User &user : users)
    {
        if (user.username == newUser.username)
        {
            cout << "Username already exists. Try a different one." << endl;
            return;
        }
    }

    cout << "Enter a password: ";
    cin >> newUser.password;

    users.push_back(newUser);

    // Store the user data in a text file (you can use a more secure method)
    ofstream userFile("users.txt", ios::app);
    userFile << newUser.username << " " << newUser.password << endl;
    userFile.close();

    cout << "Registration successful!" << endl;
}

// Function to log in a user
bool loginUser(const vector<User> &users)
{
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    for (const User &user : users)
    {
        if (user.username == username && user.password == password)
        {
            cout << "Login successful! Welcome, " << username << "!" << endl;
            return true;
        }
    }

    cout << "Invalid username or password. Please try again." << endl;
    return false;
}

// Load user data from the text file into a vector
void loadUsers(vector<User> &users)
{
    ifstream userFile("users.txt");
    if (userFile.is_open())
    {
        string username, password;
        while (userFile >> username >> password)
        {
            users.push_back({username, password});
        }
        userFile.close();
    }
}

int main()
{
    vector<User> users;
    loadUsers(users);

    int choice;
    bool loggedIn = false;

    while (true)
    {
        cout << "1. Register\n2. Login\n3. Quit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            registerUser(users);
            break;
        case 2:
            if (!loggedIn)
            {
                loggedIn = loginUser(users);
            }
            else
            {
                cout << "You are already logged in." << endl;
            }
            break;
        case 3:
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        break;
    }

    return 0;
}
