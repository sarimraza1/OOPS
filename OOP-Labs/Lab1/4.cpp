#include <iostream>
using namespace std;

int main()
{
    int n;
    int e = 0;
    int od = 0;
    cout << "Enter Size of Array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            e++;
        }
        else
        {
            od++;
        }
    }
    cout << "Total even no: " << e << endl;
    cout << "Total odd no: " << od << endl;
}