#include <iostream>
using namespace std;

int main()
{
    int n1, n2;
    char opr;
    cout << "------Menu------" << endl;
    cout << "+ Addition\n- Subtraction\n* Multiplication\n/ Division\n Choose: ";
    cin >> opr;
    cout << "Enter Number 1 : ";
    cin >> n1;
    cout << "Enter Number 2 : ";
    cin >> n2;
    switch (opr)
    {
    case '+':
    {
        cout << "Result is : " << n1 - (-n2) << endl;
        break;
    }
    case '-':
    {
        cout << "Result is : " << n1 - n2 << endl;
        break;
    }
    case '*':
    {
        cout << "Result is : " << n1 * n2 << endl;
        break;
    }
    case '/':
    {
        cout << "Result is : " << n1 / n2 << endl;
        break;
    }
    default:
    {
        cout << "Invalid Operator";
    }
    }
}