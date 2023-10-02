// -----------------------Example 1
// iteration/reiteration/looping/while loops/for loop/foreach loop/do-while loop
// what are while loops? it checks for a condition, if true then it executes the block of codes
/*
#include <iostream>

int main()
{
    std::cout << "\n-------------------------------------------------------------------------\n";
    std::cout << "*************************   Welcome to our website  ********************\n";
    std::string name;
    while (name.empty())
    {
        std::cout << "Enter your name to secure 1 million dollars before anybody even know it : ";
        std::getline(std::cin, name);

    }
    std::cout << "Hello " << name << ". \n";
    std::cout << "Check your bank account to be surprised!.";

    std::cout << "\n-------------------------------------------------------------------------\n\n";
    return 0;
}
*/
// -----------------------Example 2
// what is a do{}while() loop?
//  do-while loop executes the do{} block of code once then it checks the condition inside of while(condition).
//  if the condition is found to be true, the do{} block of code is executed again and the while condion is checked
//  again. It continues until the condition is found to be false.
/*
#include <iostream>

int main()
{
    std::cout << "\n-------------------------------------------------------------------------\n";
    std::cout << "*************************   Welcome to our website  ********************\n";
    int number;
    do
    {
        std::cout << "Enter a positive number : ";
        std::cin >> number;
    }while (number < 0);
    std::cout << "The number is " << number << ". \n";

    std::cout << "\n-------------------------------------------------------------------------\n\n";
    return 0;
}
*/
// -----------------------Example 3
/*
// for loop = is a loop that execute a block of code a specified amount of times.
#include <iostream>

int main()
{
    std::cout << "\n-------------------------------------------------------------------------\n";
    std::cout << "*************************  Welcome to our website  ********************\n";

    for (int index = 10; index >= 1; index-=1)
    {
        //std::cout << "Yes! You can do it. \n\n";
        std::cout << index << " \n";
    }
    std::cout << "HAPPY NEW YEAR!\n";

    std::cout << "\n-------------------------------------------------------------------------\n\n";
    return 0;
}
*/
// -----------------------Example 4
/*
// continue and break keyword
// break keyword is used along with an condition statement or switch statements, if a condition is true, it breaks
// out of the while loop and block of codes stops executin or exits.
#include <iostream>

int main()
{
    std::cout << "\n-------------------------------------------------------------------------\n";
    std::cout << "*************************  Welcome to our website  ********************\n";

    for (int index = 1; index <= 20; index++)
    {
        std::cout << index << " \n";
        if ( index == 13)
        {
            break;
        }
    }
    std::cout << "\n-------------------------------------------------------------------------\n\n";
    return 0;
}
// -----------------------Example 5
*/

// used along with an condition statement, if a condition is true, it continues executing by avoiding the
// object, integer, sign or a string specified in the  condition. Simply put, It just skips something that you want.
/*
#include <iostream>

int main()
{
    std::cout << "\n-------------------------------------------------------------------------\n";
    std::cout << "*************************  Welcome to our website  ********************\n";

    for (int index = 1; index <= 20; index++)
    {
        std::cout << index << " \n";
        if ( index == 13)
        {
            continue;;
        }
    }
    std::cout << "\n-------------------------------------------------------------------------\n\n";
    return 0;
}
// -----------------------Example 6
*/

// what are nested loops? -> a loop inside of another loop is called a nested loop.
/*
#include <iostream>

int main()
{
    std::cout << "\n-------------------------------------------------------------------------\n";
    std::cout << "*************************  Welcome to our website  ********************\n";

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            std::cout << j << " ";
        }
        std::cout << "Executes \n";
    }

    std::cout << "\n-------------------------------------------------------------------------\n\n";
    return 0;
}
// -----------------------Useful use cases Example codes 7
*/

#include <iostream>

int main()
{
    std::cout << "\n-------------------------------------------------------------------------\n";
    std::cout << "*************************  Welcome to our website  ********************\n";

    std::cout << "How many rows? : ";
    int rows;
    std::cin >> rows;
    std::cout << "How many collumns? : ";
    int columns;
    std::cin >> columns;
    std::cout << "Enter a symbol to use: ";
    std::string symbol;
    std::cin >> symbol;
    std::cout << " \n";
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            std::cout << symbol ;
        }
        std::cout << " \n";
    }

    std::cout << "\n-------------------------------------------------------------------------\n\n";
    return 0;
}
