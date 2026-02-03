#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
using namespace std;

class Employee
{
    string name;
    double salary;
    double taxPercent = 2;

public:
    void get_data();
    double Salary_after_tax();
    void update_tax_percentage(double newTax);
};

#endif
