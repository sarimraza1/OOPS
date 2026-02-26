#include <iostream>
using namespace std;

class Engine
{
public:
    int horsepower;
};

class Car
{
public:
    string model;
    Engine eng;
};

int main()
{
    Car c;
    cout << "Enter model: ";
    cin >> c.model;
    cout << "Enter horsepower: ";
    cin >> c.eng.horsepower;
    cout << c.model << " " << c.eng.horsepower << endl;
    return 0;
}
