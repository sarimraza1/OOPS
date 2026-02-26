#include <iostream>
using namespace std;

class Branch
{
public:
    string branchName;
    string city;
    Branch(string n = "", string c = "")
    {
        branchName = n;
        city = c;
    }
};

class Account
{
public:
    string accountHolder;
    float balance;
    Branch *branch;
    static string bankName;
    static float interestRate;
    Account(string n, float b, Branch *br)
    {
        accountHolder = n;
        balance = b;
        branch = br;
    }
    void showBalance() const
    {
        cout << accountHolder << " " << balance << " " << branch->branchName << " " << branch->city << " " << bankName << " " << interestRate << endl;
    }
    static void updateInterestRate(float r)
    {
        interestRate = r;
    }
};

string Account::bankName = "HBL PSL";
float Account::interestRate = 3.5;

int main()
{
    Branch b1("Saddar", "Karachi"), b2("i8", "Islamabad");
    Account arr[2] = {
        Account("Sarim", 10000, &b1),
        Account("Bobzy", 20000, &b2)};
    for (int i = 0; i < 2; i++)
    {
        arr[i].showBalance();
    }
    Account::updateInterestRate(6.0);
    for (int i = 0; i < 2; i++)
    {
        arr[i].showBalance();
    }
    return 0;
}
