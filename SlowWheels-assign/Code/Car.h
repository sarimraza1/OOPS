#pragma once
#include <iostream>
#include <string>
#include "Vehicle.h"
#include "CarType.h"
using namespace std;

// Inherits from Vehicle
class Car : public Vehicle {
private:
    CarType specs;
    static int carsCount;

public:
    Car() : Vehicle(), specs() {}

    Car(string br, string md, int yr, long pr, int km, string lc, CarType sp, string sl)
        : Vehicle(br, md, yr, pr, km, lc, sl), specs(sp) {
        carsCount++;
    }

    Car(const Car& obj) : Vehicle(obj), specs(obj.specs) {}

    void showDetails() const override {
        cout << brand << " " << model << " " << year << " - Available" << endl;
        cout << "  Location: " << location << endl;
        cout << "  " << year << " | " << kmDriven << " km | ";
        specs.showType();
        cout << endl;
        cout << "  Rs. " << price << endl;
        cout << "  Posted by: " << soldBy << "\n" << endl;
    }

    void showDetails(bool fullSpecs) const {
        showDetails();
        if (fullSpecs) {
            cout << "  [Full Specs]" << endl;
            cout << "  Body Type  : " << specs.getBType() << endl;
            cout << "  Assembly   : " << (specs.isImported() ? "Imported" : "Local") << endl;
            cout << "  Automatic  : " << (specs.isAutomatic() ? "Yes" : "No") << endl;
            cout << "  Engine CC  : " << specs.getCCEngine() << endl;
        }
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
        cout << "KM Driven: "; cin >> kmDriven;
        cout << "Location: "; cin >> location;
        specs.getInput();
        carsCount++;
    }

    static int getTotalCars() { return carsCount; }

    bool operator==(const Car& other) const {
        return brand == other.brand && model == other.model && year == other.year;
    }

    bool operator<(const Car& other) const {
        return price < other.price;
    }

    friend void printCarInfo(const Car& c);
    friend bool comparePrices(const Car& c1, const Car& c2);
};
int Car::carsCount = 0;
