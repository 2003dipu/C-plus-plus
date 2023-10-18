#include <iostream>
using namespace std;
/*
This example shows the use of class templates and also demonstrates the difference between pass-by value and
pass-by reference semantics for C++ parameters and return values.
*/
template<typename T, typename DipuSingha> // you can name it anything like: template <typename myName>
void Print(T value, DipuSingha input)
{
    cout << value << endl;
    cout << input << endl;
}

int main()
{
    cout << "\n\n\n";
    cout << "Enter something:\t\n";
    Print(5, '-');
    Print("Hello World", "I Love you");
    Print('T', "2023,10,18");
    Print(5.87f, 100);
    

    cout << "\n\n\n";

    return 0;
}