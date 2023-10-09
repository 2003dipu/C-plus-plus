// dynamic memory = memory that is allocated after the program is already compiled and running
// use the 'new' operator to allocate meomory in the heap rather than the stack
// useful when we don't know how much memory we will need. Makes our program more flexible, especially when
// user input
// example -----------1
/*
#include <iostream>

int main()
{
    int* pNUM= NULL;
    pNUM = new int;
    *pNUM = 21;
    std::cout << "address: " << pNUM << "\n";
    std::cout << "value: " << *pNUM << "\n";

    delete pNUM;


    return 0;
}
*/
// example -----------2

#include <iostream>

int main()
{
    std::cout << "\n   \n";
    char *pGrades = NULL;
    int size;
    std::cout << "How many grades to enter in? :\t";
    std::cin >> size;
    pGrades = new char[size];
    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter in grades #" << i + 1 << ": ";
        std::cin >> pGrades[i];

    }

    for (int i = 0; i < size; i++)
    {
        std::cout << pGrades[i] << "\t";
    }
    delete[] pGrades;

    std::cout << "\n   \n";
    return 0;
}