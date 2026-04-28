#pragma once
#include <iostream>
#include <string>
using namespace std;

class Buyer
{
private:
    string name;
    string phone;
    string email;
    string city;
    long maxBudget;
    int savedCars[10]; // aggregation
    int savedCount;

public:
    Buyer()
    {
        name = "N/A";
        phone = "N/A";
        email = "N/A";
        city = "N/A";
        maxBudget = 0;
        savedCount = 0;
    }

    Buyer(string n, string ph, string e, string c, long b)
    {
        name = n;
        phone = ph;
        email = e;
        city = c;
        maxBudget = b;
        savedCount = 0;
    }

    Buyer(const Buyer &obj)
    {
        name = obj.name;
        phone = obj.phone;
        email = obj.email;
        city = obj.city;
        maxBudget = obj.maxBudget;
        savedCount = obj.savedCount;
        for (int i = 0; i < savedCount; i++)
            savedCars[i] = obj.savedCars[i];
    }

    string getName() const { return name; }
    long getBudget() const { return maxBudget; }
    int getSavedCount() const { return savedCount; }
    int getSavedCar(int i) const { return savedCars[i]; }

    void saveFavorite(int idx)
    {
        if (savedCount < 10)
            savedCars[savedCount++] = idx;
    }

    void viewFavorites() const
    {
        cout << name << " - Saved Cars:" << endl;
        for (int i = 0; i < savedCount; i++)
            cout << "  Car #" << savedCars[i] << endl;
    }

    void showInfo() const
    {
        cout << "Name: " << name << " | Phone: " << phone << " | Budget: Rs. " << maxBudget << endl;
    }

    bool canAfford(long price) const
    {
        return price <= maxBudget;
    }

    void removeFavorite(int idx)
    {
        for (int i = 0; i < savedCount; i++)
        {
            if (savedCars[i] == idx)
            {
                for (int j = i; j < savedCount - 1; j++)
                    savedCars[j] = savedCars[j + 1];
                savedCount--;
                break;
            }
        }
    }
};
