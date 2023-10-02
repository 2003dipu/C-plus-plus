
// to show you different variations of the code and how you can think out of the box as a computer programmer
// I tried different approaches to accomplish the same task. 8 Examples-------------. No big deal
// I first created two variations of the code example 1 and example 9 -> then i asked AI to create more variations of the code(2-8)
/*
// Example ---------------------1
// Banking program written in C++
#include <iostream>
#include <iomanip>

void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main()
{
    double balance = 0;
    int choice = 0;

    do{
        std::cout << "******************\n";
        std::cout << "Enter your choice:\n";
        std::cout << "******************\n";
        std::cout << "1. Show Balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Exit\n";
        std::cin >> choice;

        std::cin.clear();
        fflush(stdin);

        switch(choice){
            case 1: showBalance(balance);
                    break;
            case 2: balance += deposit();
                    showBalance(balance);
                    break;
            case 3: balance -= withdraw(balance);
                    showBalance(balance);
                    break;
            case 4: std::cout << "Thanks for visiting!\n";
                    break;
            default:std::cout << "Invalid choice\n";
        }
    }while(choice != 4);

    return 0;
}
void showBalance(double balance){

    std::cout << "Your balance is: $"<< std::setprecision(2) << std::fixed << balance << '\n';
}
double deposit(){

    double amount = 0;

    std::cout << "Enter amount to be deposited: ";
    std::cin >> amount;

    if(amount > 0){
        return amount;
    }
    else{
        std::cout << "That's not a valid amount:\n";
        return 0;
    }
}
double withdraw(double balance){

    double amount = 0;

    std::cout << "Enter amount to be withdrawn: ";
    std::cin >> amount;

    if(amount > balance){
        std::cout << "insufficient funds\n";
        return 0;
    }
    else if(amount < 0){
        std::cout << "That's not a valid amount\n";
        return 0;
    }
    else{
        return amount;
    }
}
*/
/*
// Example ---------------------2
// Alternative to the above code
#include <iostream>

double depositMoney(double depositMoney, double balance)
{
    std::cout << "Enter the amount to be deposited: \n->: ";
    std::cin >> depositMoney;
    depositMoney += balance;
    return depositMoney;
}

double withdrawMoney(double withdraw, double balance)
{
    std::cout << "Enter the amount to withdraw: -> : ";
    std::cin >> withdraw;
    balance -= withdraw;
    return balance;
}

int main()
{
    int Uchoice = 0;
    double balance = 0;
    double deposit = 0;
    double withdraw = 0;

    do
    {
        std::cout << "-----------------------------------------------------------------------------------\n";
        std::cout << "___________________________________________________________________________________\n";
        std::cout << "Welcome to Modern Bank!\nWhat do you want to do?\nEnter your choice from the list(1,2,3,4)\n";
        std::cout << "Your current balance is: $ " << balance << "\n";
        std::cout << "1. Show Balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Exit\n->: ";
        std::cin >> Uchoice;

        switch (Uchoice)
        {
        case 1:
            std::cout << "\nYour current balance is $ " << balance << "\n";
            break;
        case 2:
            deposit = depositMoney(deposit, balance);
            break;
        case 3:
            deposit = withdrawMoney(withdraw, balance);
            break;
        case 4:
            std::cout << "Thanks for visiting.\nCome back anytime you need to deposit or withdraw money.\n";
            break;
        default:
            std::cout << "Invalid choice\n";
        }

        if (Uchoice != 4)
        {
            balance = deposit;
        }
    } while (Uchoice != 4);

    std::cout << "----------------------------------------------------------------------------------\n";
    std::cout << "__________________________________________________________________________________\n";

    return 0;
}
*/
// Example ---------------------3
/*
#include <iostream>

double depositMoney(double currentBalance)
{
    double depositAmount = 0;
    std::cout << "\n----------------------------------------------------------------------------------\n";
    std::cout << "Enter the amount to be deposited: ->";
    std::cin >> depositAmount;
    std::cout << "\n----------------------------------------------------------------------------------\n";
    currentBalance += depositAmount;
    return currentBalance;
}
double withdrawMoney(double currentBalance)
{
    double withdrawAmount = 0;
    std::cout << "\n----------------------------------------------------------------------------------\n";
    std::cout << "Enter the withdraw amount: ->";
    std::cin >> withdrawAmount;
    std::cout << "\n----------------------------------------------------------------------------------\n";

    if (withdrawAmount <= currentBalance){
        currentBalance -= withdrawAmount;
    }
    else{
        std::cout << "insufficient funds!\n";
    }
    return currentBalance;
}

int main()
{
    std::cout << "\n----------------------------------------------------------------------------------\n";
    int choice = 0;
    double currentBalance = 0;
    std::cout << "                                    Welcome to our Modern Bank        \n\n";

    do
    {
        std::cout << "Enter your choice from the following list: \n";
        std::cout << "1. Show Current Balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Exit\n->";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "Your current balance is: $" << currentBalance << "\n";
            break;
        case 2:
            currentBalance = depositMoney(currentBalance);
            break;
        case 3:
            currentBalance = withdrawMoney(currentBalance);
            break;
        case 4:
            break;
        default:
            std::cout << "Please select from the above list(1,2,3,4)\n";
        }
    } while (choice != 4);

    std::cout << "----------------------------------------------------------------------------------\n";
    return 0;
}
*/
/*
// Example ---------------------4 (using class) --------> AI generated

#include <iostream>

class BankAccount {
private:
  double balance;

public:
  BankAccount(double balance = 0.0) : balance(balance) {}

  double getBalance() const { return balance; }
  void deposit(double amount) { balance += amount; }
  void withdraw(double amount) {
    if (amount <= balance) {
      balance -= amount;
    } else {
      std::cout << "Insufficient funds!\n";
    }
  }
};

int main() {
  std::cout << "\n----------------------------------------------------------------------------------\n";
  std::cout << "                                Welcome to our Modern Bank \n\n";

  BankAccount account;

  int choice = 0;

  do {
    std::cout << "Enter your choice from the following list: \n";
    std::cout << "1. Show Current Balance\n";
    std::cout << "2. Deposit Money\n";
    std::cout << "3. Withdraw Money\n";
    std::cout << "4. Exit\n->";
    std::cin >> choice;

    switch (choice) {
      case 1:
        std::cout << "Your current balance is: $" << account.getBalance() << "\n";
        break;
      case 2:
        double depositAmount;
        std::cout << "\n----------------------------------------------------------------------------------\n";
        std::cout << "Enter the amount to be deposited: ->";
        std::cin >> depositAmount;
        std::cout << "\n----------------------------------------------------------------------------------\n";
        account.deposit(depositAmount);
        break;
      case 3:
        double withdrawAmount;
        std::cout << "\n----------------------------------------------------------------------------------\n";
        std::cout << "Enter the withdraw amount: ->";
        std::cin >> withdrawAmount;
        std::cout << "\n----------------------------------------------------------------------------------\n";
        account.withdraw(withdrawAmount);
        break;
      case 4:
        break;
      default:
        std::cout << "Please select from the above list(1,2,3,4)\n";
    }
  } while (choice != 4);

  std::cout << "----------------------------------------------------------------------------------\n";
  return 0;
}
*/

// example --------------------5 -------------------------> AI generated
/*
#include <iostream>

// Define a class named BankAccount
class BankAccount {
    // Declare private data members: balance and interestRate
    private:
        double balance;
        double interestRate;

    // Declare public member functions: constructor, deposit, withdraw, showBalance
    public:
        // Define a constructor that takes an initial balance and interest rate as parameters
        BankAccount(double initialBalance, double rate) {
            balance = initialBalance;
            interestRate = rate;
        }

        // Define a function that deposits money into the account and returns the new balance
        double deposit(double amount) {
            balance += amount;
            return balance;
        }

        // Define a function that withdraws money from the account and returns the new balance
        double withdraw(double amount) {
            if (amount <= balance) {
                balance -= amount;
            }
            else {
                std::cout << "Insufficient funds!\n";
            }
            return balance;
        }

        // Define a function that shows the current balance of the account
        void showBalance() {
            std::cout << "Your current balance is: $" << balance << "\n";
        }
};

int main() {
    std::cout << "\n----------------------------------------------------------------------------------\n";
    int choice = 0;
    double amount = 0;
    // Create an object of BankAccount class with an initial balance of 0 and an interest rate of 0.01
    BankAccount myAccount(0, 0.01);
    std::cout << "                                    Welcome to our Modern Bank        \n\n";

    do {
        std::cout << "Enter your choice from the following list: \n";
        std::cout << "1. Show Current Balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Exit\n->";
        std::cin >> choice;
        switch (choice) {
            case 1:
                // Call the showBalance function of the object
                myAccount.showBalance();
                break;
            case 2:
                std::cout << "\n----------------------------------------------------------------------------------\n";
                std::cout << "Enter the amount to be deposited: ->";
                std::cin >> amount;
                std::cout << "\n----------------------------------------------------------------------------------\n";
                // Call the deposit function of the object with the amount as parameter
                myAccount.deposit(amount);
                break;
            case 3:
                std::cout << "\n----------------------------------------------------------------------------------\n";
                std::cout << "Enter the withdraw amount: ->";
                std::cin >> amount;
                std::cout << "\n----------------------------------------------------------------------------------\n";
                // Call the withdraw function of the object with the amount as parameter
                myAccount.withdraw(amount);
                break;
            case 4:
                break;
            default:
                std::cout << "Please select from the above list(1,2,3,4)\n";
        }
    } while (choice != 4);

    std::cout << "----------------------------------------------------------------------------------\n";
    return 0;
}
*/

// example --------------------6 ---------------> AI generated

/*
#include <iostream>

// Define a struct named BankAccount
struct BankAccount {
    // Declare public data members: accountNumber, name, and balance
    std::string accountNumber;
    std::string name;
    double balance;
};

// Define a function that takes a reference to a BankAccount object and an initial balance as parameters
void openAccount(BankAccount& account, double initialBalance) {
    // Initialize the data members of the object
    std::cout << "Enter account number: ";
    std::cin >> account.accountNumber;
    std::cout << "Enter name: ";
    std::cin >> account.name;
    account.balance = initialBalance;
}

// Define a function that takes a reference to a BankAccount object as a parameter and displays its information
void showAccount(const BankAccount& account) {
    // Print the data members of the object
    std::cout << "Account number: " << account.accountNumber << "\n";
    std::cout << "Name: " << account.name << "\n";
    std::cout << "Balance: " << account.balance << "\n";
}

// Define a function that takes a reference to a BankAccount object and an amount as parameters and deposits the amount into the object
void deposit(BankAccount& account, double amount) {
    // Add the amount to the balance of the object
    account.balance += amount;
    std::cout << "Deposit successful. Current balance: " << account.balance << "\n";
}

// Define a function that takes a reference to a BankAccount object and an amount as parameters and withdraws the amount from the object
void withdraw(BankAccount& account, double amount) {
    // Check if the amount is less than or equal to the balance of the object
    if (amount <= account.balance) {
        // Subtract the amount from the balance of the object
        account.balance -= amount;
        std::cout << "Withdrawal successful. Current balance: " << account.balance << "\n";
    }
    else {
        // Print an error message
        std::cout << "Insufficient funds. Cannot withdraw.\n";
    }
}

int main() {
    // Create an array of BankAccount objects with size 3
    BankAccount accounts[3];

    // Loop through the array and call the openAccount function for each element with an initial balance of 0
    for (int i = 0; i < 3; i++) {
        openAccount(accounts[i], 0);
    }

    // Declare variables for user input
    int choice, index;
    double amount;

    // Use a do-while loop to display options and perform operations until the user chooses to exit
    do {
        // Display options
        std::cout << "\n\n1: Display all\n";
        std::cout << "2: By account number\n";
        std::cout << "3: Deposit\n";
        std::cout << "4: Withdraw\n";
        std::cout << "5: Exit\n";

        // Get user input for choice
        std::cout << "Please input your choice: ";
        std::cin >> choice;

        // Use a switch statement to perform different operations based on the choice
        switch (choice) {
            case 1:
                // Loop through the array and call the showAccount function for each element
                for (int i = 0; i < 3; i++) {
                    showAccount(accounts[i]);
                }
                break;
            case 2:
                // Get user input for index
                std::cout << "Enter index of account (0-2): ";
                std::cin >> index;

                // Check if the index is valid
                if (index >= 0 && index <= 2) {
                    // Call the showAccount function for the element at the given index
                    showAccount(accounts[index]);
                }
                else {
                    // Print an error message
                    std::cout << "Invalid index.\n";
                }
                break;
            case 3:
                // Get user input for index and amount
                std::cout << "Enter index of account (0-2): ";
                std::cin >> index;
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;

                // Check if the index is valid
                if (index >= 0 && index <= 2) {
                    // Call the deposit function for the element at the given index with the given amount
                    deposit(accounts[index], amount);
                }
                else {
                    // Print an error message
                    std::cout << "Invalid index.\n";
                }
                break;
            case 4:
                // Get user input for index and amount
                std::cout << "Enter index of account (0-2): ";
                std::cin >> index;
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;

                // Check if the index is valid
                if (index >= 0 && index <= 2) {
                    // Call the withdraw function for the element at the given index with the given amount
                    withdraw(accounts[index], amount);
                }
                else {
                    // Print an error message
                    std::cout << "Invalid index.\n";
                }
                break;
            case 5:
                // Print a farewell message
                std::cout << "Have a nice day.\n";
                break;
            default:
                // Print an error message
                std::cout << "Wrong option.\n";
        }
    } while (choice != 5); // Repeat until the user chooses to exit

    return 0;
}
*/

// example ---------------------7(AI generated)
/*
#include <iostream>
#include <iomanip> // For setprecision

double depositMoney(double currentBalance)
{
    double depositAmount;
    std::cout << "Enter the amount to be deposited: $";
    std::cin >> depositAmount;

    if (depositAmount <= 0)
    {
        std::cout << "Invalid deposit amount. Please enter a positive value.\n";
    }
    else
    {
        currentBalance += depositAmount;
        std::cout << "Deposit successful.\n";
    }

    return currentBalance;
}

double withdrawMoney(double currentBalance)
{
    double withdrawAmount;
    std::cout << "Enter the withdrawal amount: $";
    std::cin >> withdrawAmount;

    if (withdrawAmount <= 0)
    {
        std::cout << "Invalid withdrawal amount. Please enter a positive value.\n";
    }
    else if (withdrawAmount > currentBalance)
    {
        std::cout << "Insufficient funds. Withdrawal canceled.\n";
    }
    else
    {
        currentBalance -= withdrawAmount;
        std::cout << "Withdrawal successful.\n";
    }

    return currentBalance;
}

void displayBalance(double currentBalance)
{
    std::cout << "Your current balance is: $" << std::fixed << std::setprecision(2) << currentBalance << "\n";
}

int main()
{
    int choice = 0;
    double currentBalance = 0;

    std::cout << "Welcome to our Modern Bank\n";

    do
    {
        std::cout << "\nEnter your choice from the following options:\n";
        std::cout << "1. Show Current Balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Exit\n->";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            displayBalance(currentBalance);
            break;
        case 2:
            currentBalance = depositMoney(currentBalance);
            break;
        case 3:
            currentBalance = withdrawMoney(currentBalance);
            break;
        case 4:
            std::cout << "Thank you for using our banking system. Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice. Please select from the provided options (1, 2, 3, 4).\n";
        }
    } while (choice != 4);

    return 0;
}
*/
// example ---------------------8 (96 lines)
/*
#include <iostream>
#include <iomanip>

class BankAccount
{
private:
    double balance;

public:
    BankAccount() : balance(0.0) {}

    double getBalance() const
    {
        return balance;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            std::cout << "Deposit successful.\n";
        }
        else
        {
            std::cout << "Invalid deposit amount. Please enter a positive value.\n";
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0)
        {
            if (amount <= balance)
            {
                balance -= amount;
                std::cout << "Withdrawal successful.\n";
            }
            else
            {
                std::cout << "Insufficient funds. Withdrawal canceled.\n";
            }
        }
        else
        {
            std::cout << "Invalid withdrawal amount. Please enter a positive value.\n";
        }
    }
};

int main()
{
    int choice = 0;
    BankAccount account;

    std::cout << "Welcome to our Modern Bank\n";

    do
    {
        std::cout << "\nEnter your choice from the following options:\n";
        std::cout << "1. Show Current Balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Exit\n->";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Your current balance is: $" << std::fixed << std::setprecision(2) << account.getBalance() << "\n";
            break;
        case 2:
        {
            double depositAmount;
            std::cout << "Enter the amount to be deposited: $";
            std::cin >> depositAmount;
            account.deposit(depositAmount);
            break;
        }
        case 3:
        {
            double withdrawAmount;
            std::cout << "Enter the withdrawal amount: $";
            std::cin >> withdrawAmount;
            account.withdraw(withdrawAmount);
            break;
        }
        case 4:
            std::cout << "Thank you for using our banking system. Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice. Please select from the provided options (1, 2, 3, 4).\n";
        }
    } while (choice != 4);

    return 0;
}
*/
// alternative to example -----------8(this is more abbreviated into 70 lines)

#include <iostream>
#include <iomanip>

class BankAccount {
private:
    double balance = 0.0;

public:
    double getBalance() const { return balance; }
    
    void deposit(double amount) {
        if (amount <= 0) {
            std::cout << "Invalid deposit amount. Please enter a positive value.\n";
        } else {
            balance += amount;
            std::cout << "Deposit successful.\n";
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Invalid withdrawal amount. Please enter a positive value.\n";
        } else if (amount > balance) {
            std::cout << "Insufficient funds. Withdrawal canceled.\n";
        } else {
            balance -= amount;
            std::cout << "Withdrawal successful.\n";
        }
    }
};

int main() {
    int choice = 0;
    BankAccount account;

    std::cout << "Welcome to our Modern Bank\n";

    do {
        std::cout << "\nEnter your choice from the following options:\n"
                  << "1. Show Current Balance\n"
                  << "2. Deposit Money\n"
                  << "3. Withdraw Money\n"
                  << "4. Exit\n->";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Your current balance is: $" << std::fixed << std::setprecision(2) << account.getBalance() << "\n";
                break;
            case 2:
                double depositAmount;
                std::cout << "Enter the amount to be deposited: $";
                std::cin >> depositAmount;
                account.deposit(depositAmount);
                break;
            case 3:
                double withdrawAmount;
                std::cout << "Enter the withdrawal amount: $";
                std::cin >> withdrawAmount;
                account.withdraw(withdrawAmount);
                break;
            case 4:
                std::cout << "Thank you for using our banking system. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please select from the provided options (1, 2, 3, 4).\n";
        }
    } while (choice != 4);

    return 0;
}

// Example ---------------------9(very lean and simply written without decoration) (Creatd by me Dipu Singha)

/*
#include <iostream>
double depositMoney(double currentBalance)
{
    std::cout << "Enter deposit amount: ";
    double depositAmoulnt;
    std::cin >> depositAmoulnt;
    currentBalance += depositAmoulnt;
    return currentBalance;
}
double withdrawMoney(double currentBalance)
{
    std::cout << "Enter withdraw amount: ";
    double withdrawAmoulnt;
    std::cin >> withdrawAmoulnt;
    currentBalance -= withdrawAmoulnt;
    return currentBalance;
}
int main()
{
    double currentBalance = 0;
    int choice = 0;
    do
    {
        std::cout << "Select from the following list. \n";
        std::cout << "1. Show Balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Exit\n";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "Your current balance is: $" << currentBalance << "\n";
            break;
        case 2:
            currentBalance = depositMoney(currentBalance);
            break;
        case 3:
            currentBalance = withdrawMoney(currentBalance);
            break;
        case 4:
            break;
        default:
            std::cout << "Please enter your selection from the above list.";
            break;
        }
    } while (choice != 4);
    return 0;
}
*/