#include <iostream>
#include <string>
#include <random>
using namespace std;
std::string getPassword(int length)
{
    const string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%&*()|?1234567890";
    string password = "";
    mt19937 mt(random_device{}());
    uniform_int_distribution<int> dist(0, characters.size() - 1);

    for (int i = 0; i < length; i++)
    {
        password += characters[dist(mt)];
    }
    return password;
}

int main()
{
    cout << "\n\n==========================================================================================\n\n";

    cout << "Enter the length of the password you'd like: ";
    int length;
    cin >> length;
    cout << "\n\n";

    if (length <= 0)
    {
        cerr << "Invalid password length. Please enter a positive integer." << endl;
        return 1;
    }

    string password = getPassword(length);

    cout << "Generated Password: " << password;

    cout << "\n\n==========================================================================================\n\n";
    return 0;
}
