// simplify the credit card validator program using a class

#include <iostream>
#include <string>

class CreditCardValidator {
public:
    CreditCardValidator(const std::string& cardNumber) : cardNumber(cardNumber) {};

    bool isValid() {
        int evenSum = 0;
        int oddSum = 0;

        for (int i = cardNumber.size() - 1; i >= 0; i--) {
            int digit = cardNumber[i] - '0';

            if (i % 2 == cardNumber.size() % 2) {
                evenSum += getDigit(digit * 2);
            } else {
                oddSum += digit;
            }
        }

        int totalSum = evenSum + oddSum;
        return (totalSum % 10 == 0);
    }

private:
    const std::string cardNumber;

    int getDigit(const int number) {
        return number % 10 + (number / 10 % 10);
    }
};

int main() {
    std::cout << "\n\n------------------------------------------------------------------------\n\n";
    std::string cardNumber;
    std::cout << "Enter a credit card number #: ";
    std::cin >> cardNumber;

    CreditCardValidator validator(cardNumber);

    if (validator.isValid()) {
        std::cout << cardNumber << " is valid." << std::endl;
    } else {
        std::cout << cardNumber << " is not valid." << std::endl;
    }

    std::cout << "\n\n------------------------------------------------------------------------\n\n";
    return 0;
}
