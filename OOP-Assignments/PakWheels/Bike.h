#pragma once
#include <iostream>
#include <string>
#include "BikeType.h"
using namespace std;

class Bike
{
private:
    string bikeBrand;
    string bikeModel;
    int bikeYear;
    long bikePrice;
    int kmRun;
    string loc;
    BikeType specs;
    bool approved;
    string soldBy;

    static int bikesCount;

public:
    Bike()
    {
        bikeBrand = "N/A";
        bikeModel = "N/A";
        bikeYear = 0;
        bikePrice = 0;
        kmRun = 0;
        loc = "N/A";
        approved = false;
        soldBy = "N/A";
    }

    Bike(string br, string md, int yr, long pr, int km, string lc, BikeType sp, string sl)
        : specs(sp)
    {
        bikeBrand = br;
        bikeModel = md;
        bikeYear = yr;
        bikePrice = pr;
        kmRun = km;
        loc = lc;
        approved = false;
        soldBy = sl;
        bikesCount++;
    }

    Bike(const Bike &obj) : specs(obj.specs)
    {
        bikeBrand = obj.bikeBrand;
        bikeModel = obj.bikeModel;
        bikeYear = obj.bikeYear;
        bikePrice = obj.bikePrice;
        kmRun = obj.kmRun;
        loc = obj.loc;
        approved = obj.approved;
        soldBy = obj.soldBy;
    }

    string getBrand() const { return bikeBrand; }
    string getModel() const { return bikeModel; }
    int getYear() const { return bikeYear; }
    long getPrice() const { return bikePrice; }
    bool getIsApproved() const { return approved; }
    string getSellerName() const { return soldBy; }

    void setPrice(long p) { bikePrice = p; }
    void setIsApproved(bool a) { approved = a; }

    void showDetails() const
    {
        cout << bikeBrand << " " << bikeModel << " " << bikeYear << " - Available" << endl;
        cout << "  Location: " << loc << endl;
        cout << "  " << bikeYear << " | " << kmRun << " km | ";
        specs.showType();
        cout << endl;
        cout << "  Rs. " << bikePrice << endl;
        cout << "  Posted by: " << soldBy << "\n"
             << endl;
    }

    bool checkFilter(long maxPr, int minYr, int maxKm) const
    {
        if (maxPr > 0 && bikePrice > maxPr)
            return false;
        if (minYr > 0 && bikeYear < minYr)
            return false;
        if (maxKm > 0 && kmRun > maxKm)
            return false;
        return true;
    }

    void updatePrice(long newPrice)
    {
        bikePrice = newPrice;
        cout << "Price updated to Rs. " << bikePrice << endl;
    }

    void getInput(string sl)
    {
        soldBy = sl;
        cout << "Brand Name: ";
        cin >> bikeBrand;
        cout << "Model Name: ";
        cin >> bikeModel;
        cout << "Model Year: ";
        cin >> bikeYear;
        cout << "Asking Price: ";
        cin >> bikePrice;
        cout << "KM Run: ";
        cin >> kmRun;
        cout << "Location: ";
        cin >> loc;
        specs.getInput();
        bikesCount++;
    }

    static int getTotalBikes() { return bikesCount; }
};
int Bike::bikesCount = 0;
