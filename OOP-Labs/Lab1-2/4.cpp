#include <iostream>
using namespace std;

void add(int *a, int *b, int *result)
{
    *result = *a + *b;
}

void subtract(int *a, int *b, int *result)
{
    *result = *a - *b;
}

void multiply(int *a, int *b, int *result)
{
    *result = *a * *b;
}

void divide(int *a, int *b, int *result)
{
    *result = *a / *b;
}

int main()
{
    int n1, n2, result;
    char opr;

    cout << "Enter Number 1: ";
    cin >> n1;
    cout << "Enter Number 2: ";
    cin >> n2;

    cout << "+ - * / Choose: ";
    cin >> opr;

    switch (opr)
    {
    case '+':
        add(&n1, &n2, &result);
        break;
    case '-':
        subtract(&n1, &n2, &result);
        break;
    case '*':
        multiply(&n1, &n2, &result);
        break;
    case '/':
        divide(&n1, &n2, &result);
        break;
    }

    cout << "Result: " << result << endl;
    return 0;
}
