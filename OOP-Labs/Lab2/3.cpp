#include <iostream>
using namespace std;

class WaterBottle
{
    string company;
    string color;
    double liters;
    double milliliters;

public:
    void setCompany(string c)
    {
        company = c;
    }
    void setColor(string c)
    {
        color = c;
    }
    void setCapacity(double ml)
    {
        milliliters = ml;
        liters = ml / 1000;
    }
    string getCompany()
    {
        return company;
    }
    string getColor()
    {
        return color;
    }
    double getLiters()
    {
        return liters;
    }
    double getMilliliters()
    {
        return milliliters;
    }
    void drinkWater()
    {
        double amt;
        cout << "Enter amount of water drank (ml): ";
        cin >> amt;
        if (amt > milliliters)
        {
            cout << "Not enough water in bottle!" << endl;
            return;
        }
        milliliters = milliliters - amt;
        liters = milliliters / 1000;
        cout << "Water consumed: " << amt << " ml" << endl;
    }
};

int main()
{
    WaterBottle b;
    b.setCompany("Nestle");
    b.setColor("Blue");
    b.setCapacity(1500);

    cout << "Company: " << b.getCompany() << endl;
    cout << "Color: " << b.getColor() << endl;
    cout << "Capacity (L): " << b.getLiters() << endl;
    cout << "Capacity (ml): " << b.getMilliliters() << endl;

    b.drinkWater();

    cout << "Remaining (L): " << b.getLiters() << endl;
    cout << "Remaining (ml): " << b.getMilliliters() << endl;

    return 0;
}
