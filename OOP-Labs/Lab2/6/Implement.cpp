#include "Employee.h"

void Employee::get_data()
{
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter monthly salary: ";
    cin >> salary;
}

double Employee::Salary_after_tax()
{
    double tax = salary * (taxPercent / 100);
    double remaining = salary - tax;
    cout << "Salary after tax: " << remaining << endl;
    return remaining;
}

void Employee::update_tax_percentage(double newTax)
{
    taxPercent = newTax;
    cout << "Tax updated to " << taxPercent << "%" << endl;
    Salary_after_tax();
}
