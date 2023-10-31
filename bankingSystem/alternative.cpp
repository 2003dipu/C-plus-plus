#include <iostream>
#include <vector>
using namespace std;

class Account
{
public:
    Account(int accNumber, double initialBalance) : accountNumber(accNumber), balance(initialBalance) {}

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
            cout << "Deposited $" << amount << " into Account " << accountNumber << "\n";
            cout << "------------------------------------------------------------------------\n";
        }
        else
        {
            cerr << "\nInvalid deposit amount." << endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawn $" << amount << " from Account " << accountNumber << "\n";
            cout << "------------------------------------------------------------------------\n";
        }
        else
        {
            cerr << "Invalid withdrawal amount or insufficient balance." << endl;
        }
    }

    void showBalance()
    {
        cout << "Your Current Balance: $" << balance << "\n";
        cout << "------------------------------------------------------------------------\n";
    }

private:
    int accountNumber;
    double balance;
};

class Bank
{
public:
    int createAccount()
    {
        int accountNumber = accounts.size() + 1;
        Account newAccount(accountNumber, 0.0);
        accounts.push_back(newAccount);
        cout << "Account " << accountNumber << " created." << endl;
        return accountNumber;
    }

    Account* getAccount(int accNumber)
    {
        for (auto &account : accounts)
        {
            if (account.getAccountNumber() == accNumber)
            {
                return &account;
            }
        }
        cerr << "Account " << accNumber << " not found.\n" << endl;
        return nullptr;
    }

private:
    vector<Account> accounts;
};

int main()
{
    cout << "\n\n";
    Bank bank;

    while (true)
    {
        cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. Show Balance\n5. Exit\n";
        cout << "------------------------------------------------------------------------\n";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            int accountNumber = bank.createAccount();
        }
        else if (choice == 2)
        {
            int accNumber;
            double amount;
            cout << "------------------------------------------------------------------------\n";
            cout << "Enter Account Number: ";
            cin >> accNumber;
            Account *account = bank.getAccount(accNumber);
            if (account)
            {
                cout << "Enter Deposit Amount: $";
                cin >> amount;
                account->deposit(amount);
            }
        }
        else if (choice == 3)
        {
            int accNumber;
            double amount;
            cout << "Enter Account Number: ";
            cin >> accNumber;
            Account *account = bank.getAccount(accNumber);
            if (account)
            {
                cout << "Enter Withdrawal Amount: $";
                cin >> amount;
                account->withdraw(amount);
            }
        }
        else if (choice == 4)
        {
            int accNumber;
            cout << "\nEnter Account Number: ";
            cin >> accNumber;
            Account *account = bank.getAccount(accNumber);
            if (account)
            {
                account->showBalance();
            }
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cerr << "Invalid choice. Please try again." << endl;
        }
    }

    cout << "-------------------------------------------------------------------\n";
    cout << "\n\n";
    return 0;
}
