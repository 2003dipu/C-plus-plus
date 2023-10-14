
// Fizz Buzz challenge
/*
Here are the FizzBuzz rules that you need to implement in your code project:

Output values from 1 to 100, one number per line, inside the code block of an iteration statement.
When the current value is divisible by 3, print the term Fizz next to the number.
When the current value is divisible by 5, print the term Buzz next to the number.
When the current value is divisible by both 3 and 5, print the term FizzBuzz next to the number.
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "\n\n============================================================================================\n\n";
    cout << "\t\t< project title: FizzBuzz\n\t\tIf a number divided by 3 has no remainder, then shows Fizz\n\t\tIf that number divided by 5 has no remainder show Buzz\n\t\tIf the number is divided by both 3 and 5 and has no remainder or 0, show FizzBuzz>\n\n";
    int countFizz;
    int countBuzz;
    int countFizzBuzz = 0;
    int lowerBound;
    cout << "To see the FizzBuzz between a range,\n Enter the lower bound:\t";
    cin >> lowerBound;

    int higherBound;
    cout << "Enter the higher bound:\t";
    cin >> higherBound;
    for (int i = lowerBound; i <= higherBound; i++)
    {
        if (i % 5 == 0 && i % 3 == 0)
        {
            cout << i << " \t FizzBuzz \n";
            countFizzBuzz ++;
        }
        else if (i % 3 == 0)
        {
            cout << i << " \t Fizz \n";
            countFizz ++;
        }
        else if (i % 5 == 0)
        {
            cout << i << " \t Buzz \n";
            countBuzz ++;
        }
        else
            cout << i << "\n";
    }
    cout << endl;
    cout << "\n\n=============================================================================================\n\n";
    cout << "There are total " << countFizz << " Fizz, " << countBuzz << " Buzz and " << countFizzBuzz << " FizzBuzz between the range " << lowerBound << " and " << higherBound << endl;
    cout << "\n\n=============================================================================================\n\n";

    cout << "--------------------------------Mi ahan Akkhulagoy Korlu------------------------";
    cout << "I can assert my credit here. I am Dipu Singha. I just saw the FizzBuzz problem or the quesion. I just figured out how to solve that problem completely on my own.This assertion proves I don't have imposter syndrome";
    cout << "----------------------------------Yeah. I did it in C++ as well. -------------------------";
    cout << "\n\n=============================================================================================\n\n";

    return 0;
}
