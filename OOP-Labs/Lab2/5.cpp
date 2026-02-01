#include <iostream>
using namespace std;

class Employee
{
    string name;
    double salary;
    double taxPercent = 2;

public:
    void get_data()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter monthly salary: ";
        cin >> salary;
    }
    double Salary_after_tax()
    {
        double tax = salary * (taxPercent / 100);
        double remaining = salary - tax;
        cout << "Salary after tax: " << remaining << endl;
        return remaining;
    }
    void update_tax_percentage(double newTax)
    {
        taxPercent = newTax;
        cout << "Tax updated to " << taxPercent << "%" << endl;
        Salary_after_tax();
    }
};

int main()
{
    Employee e;
    e.get_data();
    e.Salary_after_tax();
    e.update_tax_percentage(3);
    return 0;
}
