#include <iostream>
using namespace std;

int prime(int a)
{
    int c = 0;
    for (int i = 2; i < a; i++)
    {
        if (a % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int b;
    cout << "Enter Number: ";
    cin >> b;
    if (prime(b))
    {
        cout << b << " is a Prime Number";
    }
    else
    {
        cout << b << " is not a Prime Number";
    }
}