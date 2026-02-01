#include <iostream>
using namespace std;
#include <stdbool.h>

class BoardMarker
{
    string Company;
    string Color;
    bool Refillable;
    bool inkStatus;

public:
    // Setters
    void setComp(string name)
    {
        Company = name;
    }
    void setColor(string col)
    {
        Color = col;
    }
    void setRefill(bool t)
    {
        Refillable = t;
    }
    void setInk(bool t)
    {
        inkStatus = t;
    }
    // Getters
    void getComp()
    {
        cout << "Company: " << Company << endl;
    }
    void getColor()
    {
        cout << "Color: " << Color << endl;
    }
    void getRefill()
    {
        cout << "Refill Status: " << Refillable << endl;
    }
    void getInk()
    {
        cout << "Ink Status: " << inkStatus << endl;
    }
    void write()
    {
        if (inkStatus)
        {
            cout << "Proceed with Writing";
            return;
        }
        cout << "Ink Empty! Writing Not Possible..";
    }
    void refill()
    {
        if (Refillable)
        {
            inkStatus = true;
            cout << "Marker ink Refilled" << endl;
            return;
        }
        cout << "Marker is not Refillable" << endl;
    }
};

int main()
{
    BoardMarker b1, b2, b3;

    b1.setComp("Dollar");
    b1.setColor("Red");
    b1.setRefill(false);
    b1.setInk(true);

    b2.setComp("Orio");
    b2.setColor("Blue");
    b2.setRefill(false);
    b2.setInk(false);

    b3.setComp("Mercury");
    b3.setColor("Cyan");
    b3.setRefill(true);
    b3.setInk(false);

    b1.getComp();
    b1.getColor();
    b1.getRefill();
    b1.getInk();
    b1.write();
    cout << endl;
    b1.refill();

    b2.getComp();
    b2.getColor();
    b2.getRefill();
    b2.getInk();
    b2.write();
    cout << endl;
    b2.refill();

    b3.getColor();
    b3.getRefill();
    b3.getInk();
    b3.write();
    cout << endl;
    b3.refill();
    b3.write();
    cout << endl;

    return 0;
}