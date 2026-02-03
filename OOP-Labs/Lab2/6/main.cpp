#include "Employee.h"

int main()
{
    Employee e1, e2, e3;

    e1.get_data();
    e1.Salary_after_tax();
    e1.update_tax_percentage(3);

    e2.get_data();
    e2.Salary_after_tax();
    e2.update_tax_percentage(5);

    e3.get_data();
    e3.Salary_after_tax();
    e3.update_tax_percentage(4);

    return 0;
}
