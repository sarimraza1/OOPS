#include <iostream>
using namespace std;

class Account
{
public:
    string accountHolder;
    float balance;
    static string bankName;
    static float interestRate;
    Account(string n, float b)
    {
        accountHolder = n;
        balance = b;
    }
    void deposit(float amt)
    {
        balance += amt;
    }
    void showBalance() const
    {
        cout << accountHolder << " " << balance << " " << bankName << " " << interestRate << endl;
    }
};

string Account::bankName = "Slow Bank";
float Account::interestRate = 2.5;

int main()
{
    Account a1("Sarim", 1000), a2("Abbas", 2000), a3("Taher", 1500);
    a1.deposit(2300);
    a2.deposit(1600);
    a3.deposit(1200);
    a1.showBalance();
    a2.showBalance();
    a3.showBalance();
    Account::interestRate = 4.5;
    a1.showBalance();
    a2.showBalance();
    a3.showBalance();
    return 0;
}
