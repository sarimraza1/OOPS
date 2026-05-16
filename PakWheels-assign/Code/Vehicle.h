#pragma once
#include <iostream>
#include <string>
using namespace std;

// Abstract base class - Car and Bike inherit from this
class Vehicle {
protected:
    string brand;
    string model;
    int year;
    long price;
    int kmDriven;
    string location;
    bool approved;
    string soldBy;

public:
    Vehicle() {
        brand = "N/A";
        model = "N/A";
        year = 0;
        price = 0;
        kmDriven = 0;
        location = "N/A";
        approved = false;
        soldBy = "N/A";
    }

    Vehicle(string br, string md, int yr, long pr, int km, string loc, string sl) {
        brand = br;
        model = md;
        year = yr;
        price = pr;
        kmDriven = km;
        location = loc;
        approved = false;
        soldBy = sl;
    }

    Vehicle(const Vehicle& obj) {
        brand = obj.brand;
        model = obj.model;
        year = obj.year;
        price = obj.price;
        kmDriven = obj.kmDriven;
        location = obj.location;
        approved = obj.approved;
        soldBy = obj.soldBy;
    }

    virtual void showDetails() const = 0;
    virtual bool checkFilter(long maxPr, int minYr, int maxKm) const = 0;
    virtual void getInput(string sl) = 0;

    string getBrand() const { return brand; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    long getPrice() const { return price; }
    bool getIsApproved() const { return approved; }
    string getSellerName() const { return soldBy; }

    void setPrice(long p) { price = p; }
    void setIsApproved(bool a) { approved = a; }

    void updatePrice(long newPrice) {
        price = newPrice;
        cout << "Price updated to Rs. " << price << endl;
    }

    virtual ~Vehicle() {}
};
