#include <iostream>
using namespace std;

int *allocateArray(int n)
{
    int *arr = new int[n];
    return arr;
}

int main()
{
    int n = 5;
    int *arr = allocateArray(n);
    delete[] arr;
    return 0;
}
