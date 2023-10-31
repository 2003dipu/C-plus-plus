/*
Implementing a complete banking system in C++ is a substantial project that requires careful planning, design,
and coding. In this response, I'll provide you with a simplified C++ example that includes the basic
functionalities of creating accounts, depositing, and withdrawing funds. This is a minimalistic demonstration
and does not cover all the features of a real banking system

This simple C++ program demonstrates the creation of bank accounts, depositing funds, and withdrawing funds.
It's important to note that this is a basic illustration and lacks critical security and transaction history
features. A real banking system would require robust security mechanisms, database integration, and compliance
with financial regulations, among other complex functionalities.
*/

#include <iostream>
#include <vector>

using namespace std;

class Account
{
private:
    int accountNumber;
    double balance;

public:
    Account(int accNumber, double initialBalance) : accountNumber(accNumber), balance(initialBalance){};

    int getAccountNumber() const
    {
        return accountNumber;
    }

    double getBalance() const
    {
        return balance;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited $ " << amount << " into Account " << accountNumber << "\n";
            cout << "------------------------------------------------------------------------\n";
        }
        else
        {
            cerr << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawn $ " << amount << " from Account " << accountNumber << "\n";
            cout << "------------------------------------------------------------------------\n";
        }
        else
        {
            cerr << "Invalid withdrawl amount or insufficient balance.\n";
        }
    }

    void showBalance()
    {
        cout << "Your Current Balance: $ " << balance << "\n";
        cout << "------------------------------------------------------------------------\n";
    }
};

class Bank
{
private:
    vector<Account> accounts;

public:
    int createAccount()
    {
        int accountNumber = accounts.size() + 1;
        Account newAccount(accountNumber, 0.0);
        accounts.push_back(newAccount);
        cout << "Account " << accountNumber << " created.\n";
        cout << "------------------------------------------------------------------------\n";
        return accountNumber;
    }

    Account &getAccount(int accNumber)
    {
        for (Account &account : accounts)
        {
            if (account.getAccountNumber() == accNumber)
            {
                return account;
            }
        }
        cerr << "Account " << accNumber << " not found.\n\n";
        return accounts[0];
    }
};

int main()
{
    Bank bank;
    cout << "\n\nProject Name:\t Simple Bank System\n";

    int accNumber, accNumber1, accNumber2;
    double amount, amount1;

    while (true)
    {
        cout << "1. Create Bank Account\n2. Deposit Money\n3. Withdraw Money\n4. Show Current Balance\n5. Exit\n";
        cout << "------------------------------------------------------------------------\n";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            bank.createAccount();
            break;
        case 2:
            cout << "------------------------------------------------------------------------\n";
            cout << "Enter Account Number: ";
            cin >> accNumber;
            cout << "Enter Deposit Amount: $ ";
            cin >> amount;
            {
                Account& account = bank.getAccount(accNumber);
                account.deposit(amount);
            }
            break;
        case 3:
            cout << "------------------------------------------------------------------------\n";
            cout << "Enter Account Number: ";
            cin >> accNumber1;
            cout << "Enter withdrawal Amount: $ ";
            cin >> amount1;
            {
                Account& account1 = bank.getAccount(accNumber1);
                account1.withdraw(amount1);
            }
            break;
        case 4:
            cout << "------------------------------------------------------------------------\n";
            cout << "Enter Account Number: ";
            cin >> accNumber2;
            {
                Account& account2 = bank.getAccount(accNumber2);
                account2.showBalance();
            }
            break;
        case 5:
            cout << "Exiting the program.\n";
            return 0; // Terminate the program.
        default:
            cerr << "Invalid choice. Please try again.\n";
        }
    }

    cout << "------------------------------------------------------------------------\n";
    cout << "\n\n";

    return 0;
}
