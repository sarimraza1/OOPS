#pragma once
#include <iostream>
#include <string>
using namespace std;

class Accessory
{
private:
    string name;
    double price;
    string category;
    string brand;
    int stock;

public:
    Accessory()
    {
        name = "N/A";
        price = 0;
        category = "N/A";
        brand = "N/A";
        stock = 0;
    }

    Accessory(string n, double p, string c, string b, int s)
    {
        name = n;
        price = p;
        category = c;
        brand = b;
        stock = s;
    }

    Accessory(const Accessory &obj)
    {
        name = obj.name;
        price = obj.price;
        category = obj.category;
        brand = obj.brand;
        stock = obj.stock;
    }

    string getName() const { return name; }
    double getPrice() const { return price; }

    void showAccessory() const
    {
        cout << name << " | Rs. " << price << " | " << category << " | In Stock: " << stock << endl;
    }

    void updateStock(int qty)
    {
        stock += qty;
    }

    bool isAvailable() const
    {
        return stock > 0;
    }

    bool matchCategory(string cat) const
    {
        return category == cat;
    }
};
