#include <iostream>
using namespace std;

int calc()
{
    double avg, mrk, total;
    for (int i = 1; i < 5; i++)
    {
        cout << "Enter Marks for Subject " << i << " : ";
        cin >> mrk;
        total += mrk;
    }
    avg = total / 4.0;
    cout << "Total Marks : " << total << endl;
    cout << "Average Marks : " << avg << endl;
    if (avg >= 90.0)
    {
        cout << "Grade A" << endl;
    }
    else if (avg >= 80.0)
    {
        cout << "Grade B" << endl;
    }
    else if (avg >= 70.0)
    {
        cout << "Grade C" << endl;
    }
    else if (avg >= 60)
    {
        cout << "Grade D" << endl;
    }
    else
    {
        cout << "Grade F" << endl;
    }
    return 0;
}

int main()
{
    calc();
    return 0;
}