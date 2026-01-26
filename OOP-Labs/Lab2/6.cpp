#include <iostream>
using namespace std;

int main()
{
    int size = 5;
    int count = 0;
    int *arr = new int[size];
    int num;

    cout << "Enter numbers (-1 to stop):" << endl;
    while (true)
    {
        cin >> num;
        if (num == -1)
            break;

        if (count == size)
        {
            size = size * 2;
            int *temp = new int[size];
            for (int i = 0; i < count; i++)
                temp[i] = arr[i];
            delete[] arr;
            arr = temp;
        }

        arr[count] = num;
        count++;
    }

    int *final = new int[count];
    for (int i = 0; i < count; i++)
        final[i] = arr[i];
    delete[] arr;
    arr = final;

    cout << "Array elements:" << endl;
    for (int i = 0; i < count; i++)
        cout << arr[i] << " ";

    delete[] arr;
    return 0;
}
