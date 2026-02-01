#include <iostream>
using namespace std;

class Circle
{
    double radius;
    double pi = 3.14159;

public:
    void setRadius(double r)
    {
        radius = r;
    }
    double getRadius()
    {
        return radius;
    }
    double getArea()
    {
        return pi * radius * radius;
    }
    double getDiameter()
    {
        return radius * 2;
    }
    double getCircumference()
    {
        return 2 * pi * radius;
    }
};

int main()
{
    Circle c;
    double r;
    cout << "Enter radius: ";
    cin >> r;
    c.setRadius(r);
    cout << "Radius: " << c.getRadius() << endl;
    cout << "Area: " << c.getArea() << endl;
    cout << "Diameter: " << c.getDiameter() << endl;
    cout << "Circumference: " << c.getCircumference() << endl;
    return 0;
}
