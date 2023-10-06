
// what are memory addresses? = a location in memory where data is stored.(represented in hexadecimal)
// a memory address can be accessed with & (address-of operator)
#include <iostream>

int main()
{
    std::string name = "Bro Code";
    const double i = 3.1416;
    int age = 21;
    bool programmer = true;
    std::string programmerNames[]{"Bro Code", "Tim Russica", "Mosh Hamedani", "Patrick Wyman", "Mike Dane"};
    std::cout << "double const memory address: " << &i << '\n';
    std::cout << "Name variable memory address: " << &name << '\n';
    std::cout << "int variable memory address: " << &age << '\n';
    std::cout << "bool variable memory address: " << &programmer << '\n';
    std::cout << "array variable memory address: " << &programmerNames << '\n';
}
