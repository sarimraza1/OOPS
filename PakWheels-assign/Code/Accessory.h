#pragma once
#include <iostream>
#include <string>
#include "Product.h"
using namespace std;

// Inherits from Product
class Accessory : public Product {
private:
    string name;
    double price;
    string category;
    string brand;
    int stock;

public:
    Accessory() {
        name = "N/A";
        price = 0;
        category = "N/A";
        brand = "N/A";
        stock = 0;
    }

    Accessory(string n, double p, string c, string b, int s) {
        name = n;
        price = p;
        category = c;
        brand = b;
        stock = s;
    }

    Accessory(const Accessory& obj) {
        name = obj.name;
        price = obj.price;
        category = obj.category;
        brand = obj.brand;
        stock = obj.stock;
    }

    string getName() const { return name; }

    void display() const override {
        cout << name << " | Rs. " << price << " | " << category << " | In Stock: " << stock << endl;
    }

    double getPrice() const override { return price; }
    bool isAvailable() const override { return stock > 0; }

    void updateStock(int qty) { stock += qty; }

    bool matchCategory(string cat) const {
        return category == cat;
    }

    Accessory operator+(const Accessory& other) const {
        Accessory bundle;
        bundle.name = name + " + " + other.name;
        bundle.price = price + other.price;
        bundle.category = "Bundle";
        bundle.brand = brand;
        bundle.stock = (stock < other.stock) ? stock : other.stock;
        return bundle;
    }
};
