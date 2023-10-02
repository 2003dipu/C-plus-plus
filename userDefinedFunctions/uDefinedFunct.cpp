/*

// user defined functions
// functions = block of reusable code  *********** Example 1 *****************
#include <iostream>

void happyBirthday(std::string name, int age);
int main()
{
    std::string name = "Dipu Singha";

    int age = 21;
    happyBirthday(name, age);
    happyBirthday(name, age);

    return 0;
}

void happyBirthday(std::string BirthdayBoy, int age)
{
    std::cout << "Happy Birthday To " << BirthdayBoy << "\n";
    std::cout << "Happy Birthday To " << BirthdayBoy << "\n";
    std::cout << "Happy Birthday dear " << BirthdayBoy << "\n";
    std::cout << "Happy Birthday To " << BirthdayBoy << "\n\n";
    std::cout << "You are " << age << " years old!";
}
*/
/*
// Example of return keyword. What does the return keyword do? ------------------Example return 1
// return = return a value back to the spot where you called the encompassing function

#include<iostream>

double square(double length);
double cube(double length);
int main()
{
    double length = 5.0;
    double area = square(length);
    double volume = cube(length);
    std::cout << "Area: " << area << "cm^2 \n";
    std::cout << "Volume: " << volume << "cm^3 \n";
    
    return 0;
}

double square(double length)
{
    return length * length;
}
double cube(double length)
{
    return length * length * length;
}
*/
/*
// Example of return keyword. What does the return keyword do? ------------------Example return 2

#include <iostream>

std::string concatString(std::string string1, std::string string2);

int main()
{
    std::string firstName = "Dipu";
    std::string lastName = "Singha";
    std::string fullName = concatString(firstName, lastName);
    std::cout << fullName;

    return 0;
}

std::string concatString(std::string string1, std::string string2)
{
    return string1 + " " + string2;
}
*/

// functions = block of reusable code  *********** Example 2 *****************
// what are the overloaded function?
#include <iostream>

void bakePizza();
void bakePizza(std::string topping1);
void bakePizza(std::string topping1, std::string topping2);

int main()
{
    bakePizza("pepperoni", "mushroom");
    
    return 0;
}

void bakePizza()
{
    std::cout << "Here is your pizza";
}

void bakePizza(std::string topping1)
{
    std::cout << "Here is your  " << topping1 << " pizza! \n";
}
void bakePizza(std::string topping1, std::string topping2)
{
    std::cout << "Here is your  " << topping1 << " and " << topping2 << " pizza! \n";
    
}
