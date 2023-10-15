#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

string getPassword(int length)
{
    string Password = "";
    string characters = "asdfghjklqwertyuiopzxcvbnm!@#$%&*()|?ASDFGHJKLQWERTYUIOPZXCVBNM1234098765";
    int charSize = characters.size();
    srand(time(0));
    int randomIndex;
    for (int i = 0; i < length; i++)
    {
        randomIndex = rand() % charSize;
        Password = Password + characters[randomIndex];
    }
    return Password;
}

int main()
{
    cout << "\n\n==========================================================================================\n\n";

    cout << "Enter the length of the password you like:\t";
    int length;
    cin >> length;
    cout << "\n\n";
    string password = getPassword(length);

    cout << "Generated Password :\t" << password;

    cout << "\n\n==========================================================================================\n\n";
    return 0;
}