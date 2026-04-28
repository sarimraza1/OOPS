#pragma once
#include <iostream>
#include <string>
using namespace std;

class CarType
{
private:
    string bType;
    string fType;
    string gearBox;
    int ccEngine;
    string assembly;

public:
    CarType()
    {
        bType = "Sedan";
        fType = "Petrol";
        gearBox = "Manual";
        ccEngine = 1000;
        assembly = "Local";
    }

    CarType(string b, string f, string g, int c, string m)
    {
        bType = b;
        fType = f;
        gearBox = g;
        ccEngine = c;
        assembly = m;
    }

    CarType(const CarType &obj)
    {
        bType = obj.bType;
        fType = obj.fType;
        gearBox = obj.gearBox;
        ccEngine = obj.ccEngine;
        assembly = obj.assembly;
    }

    string getBType() { return bType; }
    string getFType() { return fType; }
    string getGearBox() { return gearBox; }
    int getCCEngine() { return ccEngine; }

    void setBType(string b) { bType = b; }
    void setFType(string f) { fType = f; }

    void showType() const
    {
        cout << fType << " | " << ccEngine << " cc | " << gearBox;
    }

    bool isAutomatic() const
    {
        return gearBox == "Automatic";
    }

    bool isImported() const
    {
        return assembly == "Imported";
    }

    void getInput()
    {
        int opt;
        cout << "Select Body:\n1.Sedan 2.Hatchback 3.SUV\nEnter: ";
        cin >> opt;
        if (opt == 1)
            bType = "Sedan";
        else if (opt == 2)
            bType = "Hatchback";
        else
            bType = "SUV";

        cout << "Select Fuel:\n1.Petrol 2.Diesel 3.Hybrid\nEnter: ";
        cin >> opt;
        if (opt == 1)
            fType = "Petrol";
        else if (opt == 2)
            fType = "Diesel";
        else
            fType = "Hybrid";

        cout << "Gear Type:\n1.Manual 2.Auto\nEnter: ";
        cin >> opt;
        gearBox = (opt == 2) ? "Automatic" : "Manual";

        cout << "CC: ";
        cin >> ccEngine;

        cout << "Made:\n1.Local 2.Import\nEnter: ";
        cin >> opt;
        assembly = (opt == 2) ? "Imported" : "Local";
    }
};
