#include <iostream>
using namespace std;

int main()
{
    int strt, end, c = 0;
    cout << "Enter Start of Range: ";
    cin >> strt;
    cout << "Enter End of Range: ";
    cin >> end;
    if (strt % 2 != 0)
    {
        strt += 1;
    }
    for (int i = 0; i + strt < end; i += 2)
    {
        cout << strt + i << endl;
        c += 1;
        if (c == 5)
        {
            cout << strt + i + 1 << endl;
            c = 0;
        }
    }
}
