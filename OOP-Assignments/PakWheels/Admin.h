#pragma once
#include <iostream>
#include <string>
#include "Car.h"
#include "Bike.h"
using namespace std;

class Admin
{
private:
    string name;
    string email;
    string phone;
    int approvedCount;
    const char *const platformName; // const pointer to const

public:
    Admin() : platformName("PakWheels")
    {
        name = "N/A";
        email = "N/A";
        phone = "N/A";
        approvedCount = 0;
    }

    Admin(string n, string e, string ph) : platformName("PakWheels")
    {
        name = n;
        email = e;
        phone = ph;
        approvedCount = 0;
    }

    Admin(const Admin &obj) : platformName(obj.platformName)
    {
        name = obj.name;
        email = obj.email;
        phone = obj.phone;
        approvedCount = obj.approvedCount;
    }

    string getName() const { return name; }
    const char *getPlatform() const { return platformName; }

    bool login(string pw, string correctPass) const
    {
        return pw == correctPass;
    }

    void approveCar(Car &car)
    {
        car.setIsApproved(true);
        approvedCount++;
    }

    void approveBike(Bike &bike)
    {
        bike.setIsApproved(true);
        approvedCount++;
    }

    void removeCar(Car &car)
    {
        car.setIsApproved(false);
        cout << "Listing removed by admin" << endl;
    }

    void showInfo() const
    {
        cout << "Admin Name: " << name << " | Ads Approved: " << approvedCount << endl;
    }
};
