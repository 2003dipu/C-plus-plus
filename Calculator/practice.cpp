#include <iostream>
#include <cmath>
using namespace std;

bool is_valid(double num1, double num2, char operatorSign) {
    if (operatorSign == '/' && num2 == 0) {
        cout << "Error: Division by zero is not allowed." << endl;
        return false;
    }
    return true;
}

double perform_calculation(double num1, double num2, char operatorSign) {
    switch (operatorSign) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 != 0) {
                return num1 / num2;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
                return NAN;  // Use NAN to represent an invalid result
            }
        default:
            cout << "Error: Invalid operator" << endl;
            return NAN;
    }
}

int main() {
    cout << "Simple Calculator" << endl;

    char choice;
    do {
        double num1, num2;
        char operatorsSign;

        cout << "Enter Number1: ";
        cin >> num1;

        cout << "Enter Operator (+, -, *, /): ";
        cin >> operatorsSign;

        cout << "Enter Number2: ";
        cin >> num2;

        if (is_valid(num1, num2, operatorsSign)) {
            double result = perform_calculation(num1, num2, operatorsSign);
            if (!isnan(result)) {
                cout << "Result: " << num1 << " " << operatorsSign << " " << num2 << " = " << result << "\n\n";
            }
        }

        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using the calculator!" << endl;

    return 0;
}
