#pragma once
#include <iostream>
#include <string>
#include "Vehicle.h"
#include "BikeType.h"
using namespace std;

// Inherits from Vehicle
class Bike : public Vehicle {
private:
    BikeType specs;
    static int bikesCount;

public:
    Bike() : Vehicle(), specs() {}

    Bike(string br, string md, int yr, long pr, int km, string lc, BikeType sp, string sl)
        : Vehicle(br, md, yr, pr, km, lc, sl), specs(sp) {
        bikesCount++;
    }

    Bike(const Bike& obj) : Vehicle(obj), specs(obj.specs) {}

    void showDetails() const override {
        cout << brand << " " << model << " " << year << " - Available" << endl;
        cout << "  Location: " << location << endl;
        cout << "  " << year << " | " << kmDriven << " km | ";
        specs.showType();
        cout << endl;
        cout << "  Start: " << (specs.isSelfStart() ? "Self" : "Kick") << endl;
        cout << "  Rs. " << price << endl;
        cout << "  Posted by: " << soldBy << "\n" << endl;
    }

    bool checkFilter(long maxPr, int minYr, int maxKm) const override {
        if (maxPr > 0 && price > maxPr) return false;
        if (minYr > 0 && year < minYr) return false;
        if (maxKm > 0 && kmDriven > maxKm) return false;
        return true;
    }

    void getInput(string sl) override {
        soldBy = sl;
        cout << "Brand Name: "; cin >> brand;
        cout << "Model Name: "; cin >> model;
        cout << "Model Year: "; cin >> year;
        cout << "Asking Price: "; cin >> price;
        cout << "KM Run: "; cin >> kmDriven;
        cout << "Location: "; cin >> location;
        specs.getInput();
        bikesCount++;
    }

    static int getTotalBikes() { return bikesCount; }

    friend void printBikeInfo(const Bike& b);
};
int Bike::bikesCount = 0;
