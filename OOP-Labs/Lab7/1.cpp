#include <iostream>
using namespace std;

class Account
{
public:
    int accountNumber;
    float balance;
    string accountHolderName;
    string accountType;

    Account(int num, float bal, string name, string type)
    {
        accountNumber = num;
        balance = bal;
        accountHolderName = name;
        accountType = type;
    }

    void deposit(float amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(float amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient balance." << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }

    void calculateInterest()
    {
        cout << "No interest for base account." << endl;
    }

    void printStatement()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder: " << accountHolderName << endl;
        cout << "Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
    }

    void getAccountInfo()
    {
        cout << "Account: " << accountNumber << " | Holder: " << accountHolderName << endl;
    }
};

class SavingsAccount : public Account
{
public:
    float interestRate;
    float minimumBalance;

    SavingsAccount(int num, float bal, string name, float rate, float minBal)
        : Account(num, bal, name, "Savings")
    {
        interestRate = rate;
        minimumBalance = minBal;
    }

    void calculateInterest()
    {
        float interest = balance * interestRate / 100;
        cout << "Interest earned: " << interest << endl;
    }

    void withdraw(float amount)
    {
        if (balance - amount < minimumBalance)
        {
            cout << "Cannot withdraw. Minimum balance must be maintained." << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }

    void printStatement()
    {
        Account::printStatement();
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Minimum Balance: " << minimumBalance << endl;
    }
};

class CheckingAccount : public Account
{
public:
    float overdraftLimit;

    CheckingAccount(int num, float bal, string name, float limit)
        : Account(num, bal, name, "Checking")
    {
        overdraftLimit = limit;
    }

    void withdraw(float amount)
    {
        if (amount > balance + overdraftLimit)
        {
            cout << "Overdraft limit exceeded." << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }

    void printStatement()
    {
        Account::printStatement();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

class FixedDepositAccount : public Account
{
public:
    string maturityDate;
    float fixedInterestRate;

    FixedDepositAccount(int num, float bal, string name, string date, float rate)
        : Account(num, bal, name, "Fixed Deposit")
    {
        maturityDate = date;
        fixedInterestRate = rate;
    }

    void calculateInterest()
    {
        float interest = balance * fixedInterestRate / 100;
        cout << "Fixed interest earned: " << interest << endl;
    }

    void withdraw(float amount)
    {
        cout << "Cannot withdraw from a Fixed Deposit account before maturity." << endl;
    }

    void printStatement()
    {
        Account::printStatement();
        cout << "Maturity Date: " << maturityDate << endl;
        cout << "Fixed Interest Rate: " << fixedInterestRate << "%" << endl;
    }
};

int main()
{
    SavingsAccount sa(1001, 5000, "Ali", 5.0, 1000);
    sa.deposit(2000);
    sa.withdraw(500);
    sa.calculateInterest();
    sa.printStatement();

    cout << endl;

    CheckingAccount ca(1002, 3000, "Sara", 500);
    ca.withdraw(3400);
    ca.printStatement();

    cout << endl;

    FixedDepositAccount fd(1003, 10000, "Ahmed", "2025-12-31", 8.5);
    fd.withdraw(1000);
    fd.calculateInterest();
    fd.printStatement();

    return 0;
}
