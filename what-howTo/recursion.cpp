// recursion = a programming technique where a function invokes itself from within. Break a complex concept into a repeatable single steps
// (iterative vs recursive) Recursion's = advantages -> less code and is cleaner. Useful for sorting and searching algorithms.
// disadvantages = uses more memory , slower
// example ---------1 (iterative approach)
/*
#include <iostream>

void walk(int steps)
{
    for (int i = 0; i < steps; i++)
    {
        std::cout << "You take a step! \n";
    }
}

int main()
{
    int steps = 100;
    walk(steps);


    return 0;
}
*/
/*
// example ---------2 (recursive approach)
#include <iostream>

void walk(int steps)
{
    if (steps > 0)
    {
        std::cout << "\t\tYou take a step!\n";
        walk(steps -1); //call or invoke the function within itself. subtract 1 otherwise it'd be an infinite loop
    }
}

int main()
{
    std::cout << "\n\t\n";

    int steps = 10;
    walk(steps);

    std::cout << "\n\t\n";
    return 0;
}
*/
/*
// example ---------1 (iterative  approach) factorial function

#include <iostream>

int factorial(int num)
{
    int result = 1;
    for (int i = 1; i <= num; i++)
    {
        result = result * i;
    }
    return result;
    
}

int main()
{
    std::cout << "\n\t\n";

    int num = 4;
    std::cout << factorial(num);

    std::cout << "\n\t\n";
    return 0;
}

*/

// example ---------2 (recursive  approach) factorial function

#include <iostream>

int factorial(int num)
{
    int result = 1;
    if ( num > 1)
    {
        return num * factorial(num - 1);
    }
    return 1;
    
}

int main()
{
    std::cout << "\n\t\n";
    std::cout << "Enter a number to factorial(recursive approach):\t";
    int num;
    std::cin >> num;

    std::cout << "Factorial function:\t\t" << num << "! = " << factorial(num);

    std::cout << "\n\t\n";
    return 0;
}