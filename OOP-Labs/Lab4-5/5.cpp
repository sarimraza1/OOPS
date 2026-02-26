#include <iostream>
using namespace std;

class Department
{
public:
    string name;
    int code;
};

class Student
{
public:
    string name;
    int age;
    Department dept;
};

int main()
{
    Student s[3];
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter name: ";
        cin >> s[i].name;
        cout << "Enter age: ";
        cin >> s[i].age;
        cout << "Enter dept name: ";
        cin >> s[i].dept.name;
        cout << "Enter dept code: ";
        cin >> s[i].dept.code;
    }
    for (int i = 0; i < 3; i++)
    {
        cout << s[i].name << " " << s[i].age << " " << s[i].dept.name << " " << s[i].dept.code << endl;
    }
    return 0;
}
