#include <iostream>
using namespace std;

class Project
{
public:
    string projectTitle;
    int duration;
    Project(string t = "", int d = 0)
    {
        projectTitle = t;
        duration = d;
    }
};

class Employee
{
public:
    string empName;
    float salary;
    Project *project;
    static float taxRate;
    Employee(string n, float s, Project *p)
    {
        empName = n;
        salary = s;
        project = p;
    }
    float calculateNetSalary() const
    {
        return salary - (salary * taxRate / 100);
    }
    static void changeTaxRate(float t)
    {
        taxRate = t;
    }
};

float Employee::taxRate = 10.0;

int main()
{
    Project p1("OOP", 12), p2("PF", 6);
    Employee arr[2] = {
        Employee("Sarim", 50000, &p1),
        Employee("Abbas", 60000, &p2)};
    for (int i = 0; i < 2; i++)
    {
        cout << arr[i].empName << " " << arr[i].salary << " " << arr[i].project->projectTitle << " " << arr[i].calculateNetSalary() << endl;
    }
    Employee::changeTaxRate(15);
    for (int i = 0; i < 2; i++)
    {
        cout << arr[i].empName << " " << arr[i].calculateNetSalary() << endl;
    }
    return 0;
}
