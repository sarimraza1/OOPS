#include <iostream>
using namespace std;

class BankAccount
{
public:
    static float interestRate;
    static void changeRate(float r)
    {
        interestRate = r;
    }
    void showRate()
    {
        cout << interestRate << endl;
    }
};

float BankAccount::interestRate = 3.0;

int main()
{
    BankAccount a, b;
    a.showRate();
    b.showRate();
    BankAccount::changeRate(7.5);
    a.showRate();
    b.showRate();
    return 0;
}
