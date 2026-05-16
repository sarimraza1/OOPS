#pragma once
#include <iostream>
#include <string>
#include "User.h"
using namespace std;

// Inherits from User
class Seller : public User {
private:
    string joinedOn;
    string postedAds[10];
    int adsCount;

public:
    Seller() : User() {
        joinedOn = "N/A";
        adsCount = 0;
    }

    Seller(string n, string e, string ph, string c, string jo) : User(n, e, ph, c) {
        joinedOn = jo;
        adsCount = 0;
    }

    Seller(const Seller& obj) : User(obj) {
        joinedOn = obj.joinedOn;
        adsCount = obj.adsCount;
        for (int i = 0; i < adsCount; i++)
            postedAds[i] = obj.postedAds[i];
    }

    string getRole() const override { return "Seller"; }

    void showInfo() const override {
        cout << "Name: " << name << " | Contact: " << phone << " | City: " << city << endl;
    }

    void addListing(string ad) {
        if (adsCount < 10)
            postedAds[adsCount++] = ad;
    }

    void viewMyListings() const {
        cout << "Posted by: " << name << endl;
        cout << "Registered: " << joinedOn << endl;
        for (int i = 0; i < adsCount; i++)
            cout << "  " << i + 1 << ". " << postedAds[i] << endl;
    }

    int getListingCount() const { return adsCount; }

    void removeListing(int idx) {
        if (idx >= 0 && idx < adsCount) {
            for (int i = idx; i < adsCount - 1; i++)
                postedAds[i] = postedAds[i + 1];
            adsCount--;
        }
    }
};
