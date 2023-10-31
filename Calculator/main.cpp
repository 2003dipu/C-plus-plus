#include <iostream>
using namespace std;

bool is_valid(double num1, double num2, char operatorSign)
{
    // Basic validation to check for division by zero
    if (operatorSign == '/' && num2 == 0) {
        cout << "Error: Division by zero is not allowed." << endl;
        return false;
    }
    return true;
}

void determine()
{
    char operatorsSign;
    double num1, num2;

    do
    {
        cout << "Number1 \t";
        cin >> num1;
        cout << "Operator\t";
        cin >> operatorsSign;
        cout << "Number2 \t";
        cin >> num2;
    } while (!is_valid(num1, num2, operatorsSign));

    switch (operatorsSign)
    {
    case '+':
        cout << num1 << " + " << num2 << " = " << num1 + num2 << "\n\n";
        break;
    case '-':
        cout << num1 << " - " << num2 << " = " << num1 - num2 << "\n\n";
        break;
    case '*':
        cout << num1 << " * " << num2 << " = " << num1 * num2 << "\n\n";
        break;
    case '/':
        cout << num1 << " / " << num2 << " = " << num1 / num2 << "\n\n";
        break;

    default:
        cout << "Error";
        break;
    }
}

int main()
{
    cout << "\n\n";

    determine();

    cout << "\n\n";

    return 0;
}