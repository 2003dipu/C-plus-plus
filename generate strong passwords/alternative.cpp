#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <random>

using namespace std;

string getPassword(int length)
{
    string Password = " ";
    string characters = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int charSize = characters.size();
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, charSize - 1);

    for (int i = 0; i < length; i++)
    {
        Password = Password + characters[dist(gen)];
    }
    return Password;
}

int main()
{
    cout << "\n\n==========================================================================================\n\n";

    cout << "Enter the length of the password you like:\t";
    int length;
    cin >> length;
    if (length <= 0)
    {
        cout << "Invalid length. Please enter a positive integer." << endl;
        return 1;
    }

    cout << "\n\n";
    string password = getPassword(length);

    cout << "Generated Password :\t" << password;

    cout << "\n\n==========================================================================================\n\n";
    return 0;
}
