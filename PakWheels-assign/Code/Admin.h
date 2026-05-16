#pragma once
#include <iostream>
#include <string>
#include "User.h"
#include "Car.h"
#include "Bike.h"
using namespace std;

// Inherits from User
class Admin : public User {
private:
    int approvedCount;
    const char* const platformName;

public:
    Admin() : User(), platformName("Slow-Wheels") {
        approvedCount = 0;
    }

    Admin(string n, string e, string ph) : User(n, e, ph, "N/A"), platformName("Slow-Wheels") {
        approvedCount = 0;
    }

    Admin(const Admin& obj) : User(obj), platformName(obj.platformName) {
        approvedCount = obj.approvedCount;
    }

    string getRole() const override { return "Admin"; }

    void showInfo() const override {
        cout << "Admin Name: " << name << " | Ads Approved: " << approvedCount << endl;
    }

    const char* getPlatform() const { return platformName; }

    bool login(string pw, string correctPass) const {
        return pw == correctPass;
    }

    void approveCar(Car& car) {
        car.setIsApproved(true);
        approvedCount++;
    }

    void approveBike(Bike& bike) {
        bike.setIsApproved(true);
        approvedCount++;
    }

    void removeCar(Car& car) {
        car.setIsApproved(false);
        cout << "Listing removed by admin" << endl;
    }
};
