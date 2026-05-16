#pragma once
#include <iostream>
#include <string>
#include "User.h"
using namespace std;

// Inherits from User
class Buyer : public User {
private:
    long maxBudget;
    int savedCars[10];
    int savedCount;

public:
    Buyer() : User() {
        maxBudget = 0;
        savedCount = 0;
    }

    Buyer(string n, string ph, string e, string c, long b) : User(n, e, ph, c) {
        maxBudget = b;
        savedCount = 0;
    }

    Buyer(const Buyer& obj) : User(obj) {
        maxBudget = obj.maxBudget;
        savedCount = obj.savedCount;
        for (int i = 0; i < savedCount; i++)
            savedCars[i] = obj.savedCars[i];
    }

    string getRole() const override { return "Buyer"; }

    void showInfo() const override {
        cout << "Name: " << name << " | Phone: " << phone << " | Budget: Rs. " << maxBudget << endl;
    }

    long getBudget() const { return maxBudget; }
    int getSavedCount() const { return savedCount; }
    int getSavedCar(int i) const { return savedCars[i]; }

    void saveFavorite(int idx) {
        if (savedCount < 10)
            savedCars[savedCount++] = idx;
    }

    void viewFavorites() const {
        cout << name << " - Saved Cars:" << endl;
        for (int i = 0; i < savedCount; i++)
            cout << "  Car #" << savedCars[i] << endl;
    }

    bool canAfford(long carPrice) const {
        return carPrice <= maxBudget;
    }

    void removeFavorite(int idx) {
        for (int i = 0; i < savedCount; i++) {
            if (savedCars[i] == idx) {
                for (int j = i; j < savedCount - 1; j++)
                    savedCars[j] = savedCars[j + 1];
                savedCount--;
                break;
            }
        }
    }

    bool operator==(const Buyer& other) const {
        return name == other.name && phone == other.phone;
    }
};
