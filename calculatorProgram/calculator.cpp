
// C++ console calculator program
#include<iostream>

int main()
{
    std::cout << " \n";
    std::cout << "-------------------------------------------------------------- \n\n";
    std::cout << "*********************  Calculator Program  ****************** \n";
    char op;
    double num1;
    double num2;
    double num3;
    double result;

    std::cout << "Enter #1: ";
    std::cin >> num1;
    std::cout << "Enter either (+ - * /): ";
    std::cin >> op;
    std::cout << "Enter #2: ";
    std::cin >> num2;

    switch(op)
    {
        case '+':
            result = num1 + num2;
            std::cout << num1 << " + " << num2 << " = "<< result;
            break;
        case '-':
            result = num1 - num2;
            std::cout << num1 << " - " << num2 << " = "<< result;
            break;
        case '*':
            result = num1 * num2;
            std::cout <<num1 << " multiplied by " << num2 << " = "<< result;
            break;
        case '/':
            result = num1 / num2;
            std::cout <<num1 << " divided by " << num2 << " = " << result;
            break;
        default:
            std::cout << "Please enter a valid operator(+ - * /)";
            break;
    }


    std::cout << " \n";
    std::cout << "-------------------------------------------------------------- \n\n";
    return 0;
}
