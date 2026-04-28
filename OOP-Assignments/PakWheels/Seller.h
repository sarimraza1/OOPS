#pragma once
#include <iostream>
#include <string>
using namespace std;

class Seller
{
private:
    string name;
    string email;
    string phone;
    string city;
    string joinedOn;
    string postedAds[10]; // aggregation
    int adsCount;

public:
    Seller()
    {
        name = "N/A";
        email = "N/A";
        phone = "N/A";
        city = "N/A";
        joinedOn = "N/A";
        adsCount = 0;
    }

    Seller(string n, string e, string ph, string c, string ms)
    {
        name = n;
        email = e;
        phone = ph;
        city = c;
        joinedOn = ms;
        adsCount = 0;
    }

    Seller(const Seller &obj)
    {
        name = obj.name;
        email = obj.email;
        phone = obj.phone;
        city = obj.city;
        joinedOn = obj.joinedOn;
        adsCount = obj.adsCount;
        for (int i = 0; i < adsCount; i++)
            postedAds[i] = obj.postedAds[i];
    }

    string getName() const { return name; }
    string getPhone() const { return phone; }
    string getCity() const { return city; }

    void addListing(string ad)
    {
        if (adsCount < 10)
            postedAds[adsCount++] = ad;
    }

    void viewMyListings() const
    {
        cout << "Posted by: " << name << endl;
        cout << "Registered: " << joinedOn << endl;
        for (int i = 0; i < adsCount; i++)
            cout << "  " << i + 1 << ". " << postedAds[i] << endl;
    }

    void showInfo() const
    {
        cout << "Name: " << name << " | Contact: " << phone << " | City: " << city << endl;
    }

    int getListingCount() const
    {
        return adsCount;
    }

    void removeListing(int idx)
    {
        if (idx >= 0 && idx < adsCount)
        {
            for (int i = idx; i < adsCount - 1; i++)
                postedAds[i] = postedAds[i + 1];
            adsCount--;
        }
    }
};
