#include <iostream>
using namespace std;

int main()
{
    int units;
    float bill = 0;
    cout << "Enter Units Consumed: ";
    cin >> units;
    if (units <= 50)
    {
        bill = units * 0.50;
    }
    else if (units <= 150)
    {
        bill = 50 * 0.50;
        bill += (units - 50) * 0.75;
    }
    else if (units <= 250)
    {
        bill = 50 * 0.50;
        bill += 100 * 0.75;
        bill += (units - 150) * 1.20;
    }
    else
    {
        bill = 50 * 0.50;
        bill += 100 * 0.75;
        bill += 100 * 1.20;
        bill += (units - 250) * 1.50;
    }
    bill += bill * 0.20;
    cout << "Total Bill Rs " << bill << endl;
}
