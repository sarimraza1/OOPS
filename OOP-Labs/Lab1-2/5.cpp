#include <iostream>
using namespace std;

int main()
{
    int r1, c1, r2, c2;

    cout << "Enter rows and cols for Matrix 1: ";
    cin >> r1 >> c1;
    cout << "Enter rows and cols for Matrix 2: ";
    cin >> r2 >> c2;

    int **m1 = new int *[r1];
    for (int i = 0; i < r1; i++)
        m1[i] = new int[c1];

    int **m2 = new int *[r2];
    for (int i = 0; i < r2; i++)
        m2[i] = new int[c2];

    cout << "Enter Matrix 1:" << endl;
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> m1[i][j];

    cout << "Enter Matrix 2:" << endl;
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> m2[i][j];

    if (r1 == r2 && c1 == c2)
    {
        int **add = new int *[r1];
        int **sub = new int *[r1];
        for (int i = 0; i < r1; i++)
        {
            add[i] = new int[c1];
            sub[i] = new int[c1];
        }

        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                add[i][j] = m1[i][j] + m2[i][j];
                sub[i][j] = m1[i][j] - m2[i][j];
            }
        }

        cout << "Addition:" << endl;
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
                cout << add[i][j] << " ";
            cout << endl;
        }

        cout << "Subtraction:" << endl;
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
                cout << sub[i][j] << " ";
            cout << endl;
        }

        for (int i = 0; i < r1; i++)
        {
            delete[] add[i];
            delete[] sub[i];
        }
        delete[] add;
        delete[] sub;
    }

    if (c1 == r2)
    {
        int **mul = new int *[r1];
        for (int i = 0; i < r1; i++)
            mul[i] = new int[c2];

        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                mul[i][j] = 0;
                for (int k = 0; k < c1; k++)
                    mul[i][j] += m1[i][k] * m2[k][j];
            }
        }

        cout << "Multiplication:" << endl;
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
                cout << mul[i][j] << " ";
            cout << endl;
        }

        for (int i = 0; i < r1; i++)
            delete[] mul[i];
        delete[] mul;
    }

    for (int i = 0; i < r1; i++)
        delete[] m1[i];
    delete[] m1;

    for (int i = 0; i < r2; i++)
        delete[] m2[i];
    delete[] m2;

    return 0;
}
