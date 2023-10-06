/*
// what is pass by VALUE vs pass by REFERENCE? reference = memory address
#include <iostream>

void swap(std::string &x, std::string &y)
{
    //std::string temp;

    //temp = x;
    //x = y;
    //y = temp;
    std::cout << "X: " << &x << '\n';
    std::cout << "Y: " << &y << '\n';
}

int main()
{
    std::string x = "Kool-aid";
    std::string y = "Water";

    swap(x, y);
    std::cout << "X: " << &x << '\n';
    std::cout << "Y: " << &y << '\n';

    return 0;
}
*/
// another example to understand it-----For example, the following function takes an argument by value:
#include <iostream>
/*
void increment(int value)
{
    value++;
    std::cout << value << std::endl;
}

int main()
{
    int value = 5;
    increment(value);
    std::cout << value << std::endl;
    return 0;
}
*/
/*
//The following function takes an argument by reference:

void increment(int& value) {
  ++value;
}
//If we call this function with the same code as before:
int main() {
  int count = 5;
  increment(count);
  std::cout << count << std::endl;
  return 0;
}
*/
/*
void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

int main() {
  int count1 = 5;
  int count2 = 6;
  swap(count1, count2);
  std::cout << "Count1: 5 >" << count1 << std::endl;
  std::cout << "Count2: 6 >" << count2 << std::endl;
  return 0;
}
*/
/*
// example of pass by value
void modify_string(std::string s)
{
    s += " World";
}

int main()
{
    std::string greeting = " Hello";
    modify_string(greeting);
    std::cout << greeting;

    return 0;
}
// # Output: Hello (original string remains unchanged)
*/
// example of pass by reference
void modify_string(std::string &s)
{
    s += " World";
}

int main()
{
    std::string greeting = "Hello ";
    modify_string(greeting);
    std::cout << greeting;

    return 0;
}
// # Output: Hello World (original string changed)