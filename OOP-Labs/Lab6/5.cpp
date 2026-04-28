#include <iostream>
using namespace std;

class Vehicle
{
public:
    string make;
    string model;
    int year;

    Vehicle(string mk, string md, int y)
    {
        make = mk;
        model = md;
        year = y;
    }
};

class Car : public Vehicle
{
public:
    int doors;
    float fuelEfficiency;

    Car(string mk, string md, int y, int d, float fe) : Vehicle(mk, md, y)
    {
        doors = d;
        fuelEfficiency = fe;
    }
};

class ElectricCar : public Car
{
public:
    float batteryLife;

    ElectricCar(string mk, string md, int y, int d, float fe, float bl) : Car(mk, md, y, d, fe)
    {
        batteryLife = bl;
    }

    void display()
    {
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Doors: " << doors << endl;
        cout << "Fuel Efficiency: " << fuelEfficiency << " km/l" << endl;
        cout << "Battery Life: " << batteryLife << " kWh" << endl;
    }
};

int main()
{
    ElectricCar ec("Tesla", "Model 3", 2023, 4, 0, 75.5);
    ec.display();
    return 0;
}
