#include <iostream>
using namespace std;

int main()
{
    int size = 5;
    int count = 0;
    int *arr = new int[size];
    int n;

    cout << "Enter numbers (-1 to stop): ";
    cin >> n;

    while (n != -1)
    {
        if (count == size)
        {
            size = size * 2;
            int *newArr = new int[size];

            for (int i = 0; i < count; i++)
            {
                newArr[i] = arr[i];
            }

            delete[] arr;
            arr = newArr;
            cout << "Array doubled! New size: " << size << endl;
        }

        arr[count] = n;
        count++;

        cin >> n;
    }

    cout << "\nShrinking array to size " << count << endl;
    int *finalArr = new int[count];
    for (int i = 0; i < count; i++)
    {
        finalArr[i] = arr[i];
    }
    delete[] arr;
    arr = finalArr;

    cout << "Final array: ";
    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
