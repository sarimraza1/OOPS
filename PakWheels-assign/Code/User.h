#pragma once
#include <iostream>
#include <string>
using namespace std;

// Abstract base class - Seller, Buyer, Admin inherit from this
class User {
protected:
    string name;
    string email;
    string phone;
    string city;

public:
    User() {
        name = "N/A";
        email = "N/A";
        phone = "N/A";
        city = "N/A";
    }

    User(string n, string e, string ph, string c) {
        name = n;
        email = e;
        phone = ph;
        city = c;
    }

    User(const User& obj) {
        name = obj.name;
        email = obj.email;
        phone = obj.phone;
        city = obj.city;
    }

    virtual void showInfo() const = 0;
    virtual string getRole() const = 0;

    string getName() const { return name; }
    string getEmail() const { return email; }
    string getPhone() const { return phone; }
    string getCity() const { return city; }

    virtual ~User() {}
};
