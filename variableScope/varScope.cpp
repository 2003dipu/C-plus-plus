
#include <iostream>

// what is variable scope?
// Global variable = declared outside of all functions
// local variable = declared inside of a function or block{}

int myNum = 2003;

void printNum();

int main()
{
    int myNum = 1;
    printNum();
    std::cout << myNum;

    return 0;
}
void printNum()
{
    int myNum = 2;
    std::cout << "My number is " << ::myNum << "\n";
}