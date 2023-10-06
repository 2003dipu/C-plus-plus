// Credit Card Validator program in C++
/*
Luhn Algorithm for validating credit card
1. Double every digit from right to left, if doubled number is 2 digits split them
2. Add all single digits from step 1
3. Add all odd numbered digits from right to left
4. Sum results form step 2 & 3
5. If step 4 is divisible by 4, # is valid
valid credit card number example: 6011000990139424
*/
/*
// Example ----------------1
#include <iostream>

int getDigit(const int number)
{

    return number % 10 + (number / 10 % 10);
}
int sumEvenDigits(const std::string cardNumber)
{
    int sum = 0;
    for(int i = cardNumber.size() - 2; i >= 0; i-=2)
    {
        sum += getDigit((cardNumber[i] - '0') * 2);
    }
    return sum;
}
int sumOddDigits(const std::string cardNumber)
{

    int sum = 0;
    for(int i = cardNumber.size() - 1; i >= 0; i-=2)
    {
        sum += cardNumber[i] - '0';
    }
    return sum;
}

int main()
{
    std::cout << "\n\n------------------------------------------------------------------------\n\n";
    std::string cardNumber;
    int result = 0;
    std::cout << "Enter a credit card number #: ";
    std::cin >> cardNumber;
    result = sumEvenDigits(cardNumber) + sumOddDigits(cardNumber);
    if(result % 10 == 0)
    {
        std::cout << cardNumber << " is valid.";
    }
    else
    {
        std::cout << cardNumber << " is not valid";
    }

    
    
    std::cout << "\n\n------------------------------------------------------------------------\n\n";
    return 0;
}
*/
// Example ----------------2
/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isNumericString(const string &str) {
    return all_of(str.begin(), str.end(), ::isdigit);
}

bool isCreditCardValid(const string &cardNumber) {
    if (!isNumericString(cardNumber)) {
        return false;
    }

    int sum = 0;
    bool doubleDigit = false;

    for (int i = cardNumber.length() - 1; i >= 0; i--) {
        int digit = cardNumber[i] - '0';

        if (doubleDigit) {
            digit *= 2;
            if (digit > 9) {
                digit -= 9;
            }
        }

        sum += digit;
        doubleDigit = !doubleDigit;
    }

    return (sum % 10 == 0);
}

int main() {
    string cardNumber;

    cout << "Enter a credit card number: ";
    cin >> cardNumber;

    if (isCreditCardValid(cardNumber)) {
        cout << "Valid credit card number." << endl;
    } else {
        cout << "Invalid credit card number." << endl;
    }

    return 0;
}
*/
// Example ----------------3
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isCreditCardValid(const string &cardNumber) {
    if (!all_of(cardNumber.begin(), cardNumber.end(), ::isdigit)) {
        return false;
    }

    int sum = 0;
    bool doubleDigit = false;

    for (int i = cardNumber.length() - 1; i >= 0; i--) {
        int digit = cardNumber[i] - '0';
        if (doubleDigit) digit *= 2;
        sum += digit / 10 + digit % 10;
        doubleDigit = !doubleDigit;
    }

    return (sum % 10 == 0);
}

int main() {
    string cardNumber;

    cout << "Enter a credit card number: ";
    cin >> cardNumber;

    if (isCreditCardValid(cardNumber)) {
        cout << "Valid credit card number." << endl;
    } else {
        cout << "Invalid credit card number." << endl;
    }

    return 0;
}
