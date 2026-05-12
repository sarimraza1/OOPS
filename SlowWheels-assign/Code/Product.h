#pragma once
#include <iostream>
#include <string>
using namespace std;

// Abstract base class - Accessory inherits from this
class Product {
public:
    virtual void display() const = 0;
    virtual double getPrice() const = 0;
    virtual bool isAvailable() const = 0;
    virtual ~Product() {}
};
