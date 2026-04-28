#pragma once
#include <iostream>
#include <string>
#include "CarType.h"
using namespace std;

class Car
{
private:
    string carBrand;
    string carModel;
    int carYear;
    long carPrice;
    int kmDriven;
    string loc;
    CarType specs;
    bool approved;
    string soldBy;

    static int carsCount;

public:
    Car()
    {
        carBrand = "N/A";
        carModel = "N/A";
        carYear = 0;
        carPrice = 0;
        kmDriven = 0;
        loc = "N/A";
        approved = false;
        soldBy = "N/A";
    }

    Car(string br, string md, int yr, long pr, int km, string lc, CarType sp, string sl)
        : specs(sp)
    {
        carBrand = br;
        carModel = md;
        carYear = yr;
        carPrice = pr;
        kmDriven = km;
        loc = lc;
        approved = false;
        soldBy = sl;
        carsCount++;
    }

    Car(const Car &obj) : specs(obj.specs)
    {
        carBrand = obj.carBrand;
        carModel = obj.carModel;
        carYear = obj.carYear;
        carPrice = obj.carPrice;
        kmDriven = obj.kmDriven;
        loc = obj.loc;
        approved = obj.approved;
        soldBy = obj.soldBy;
    }

    string getBrand() const { return carBrand; }
    string getModel() const { return carModel; }
    int getYear() const { return carYear; }
    long getPrice() const { return carPrice; }
    bool getIsApproved() const { return approved; }
    string getSellerName() const { return soldBy; }

    void setPrice(long p) { carPrice = p; }
    void setIsApproved(bool a) { approved = a; }

    void showDetails() const
    {
        cout << carBrand << " " << carModel << " " << carYear << " - Available" << endl;
        cout << "  Location: " << loc << endl;
        cout << "  " << carYear << " | " << kmDriven << " km | ";
        specs.showType();
        cout << endl;
        cout << "  Rs. " << carPrice << endl;
        cout << "  Posted by: " << soldBy << "\n"
             << endl;
    }

    bool checkFilter(long maxPr, int minYr, int maxKm) const
    {
        if (maxPr > 0 && carPrice > maxPr)
            return false;
        if (minYr > 0 && carYear < minYr)
            return false;
        if (maxKm > 0 && kmDriven > maxKm)
            return false;
        return true;
    }

    void updatePrice(long newPrice)
    {
        carPrice = newPrice;
        cout << "Price updated to Rs. " << carPrice << endl;
    }

    void getInput(string sl)
    {
        soldBy = sl;
        cout << "Brand Name: ";
        cin >> carBrand;
        cout << "Model Name: ";
        cin >> carModel;
        cout << "Model Year: ";
        cin >> carYear;
        cout << "Asking Price: ";
        cin >> carPrice;
        cout << "KM Driven: ";
        cin >> kmDriven;
        cout << "Location: ";
        cin >> loc;
        specs.getInput();
        carsCount++;
    }

    static int getTotalCars() { return carsCount; }
};
int Car::carsCount = 0;
