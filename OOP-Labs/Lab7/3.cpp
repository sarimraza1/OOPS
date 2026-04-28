#include <iostream>
using namespace std;

class Currency
{
public:
    float amount;
    string currencyCode;
    string currencySymbol;
    float exchangeRate;

    Currency(float amt, string code, string symbol, float rate)
    {
        amount = amt;
        currencyCode = code;
        currencySymbol = symbol;
        exchangeRate = rate;
    }

    void convertToBase()
    {
        cout << "Base value: " << amount * exchangeRate << " USD" << endl;
    }

    void convertTo(Currency &target)
    {
        float baseValue = amount * exchangeRate;
        float converted = baseValue / target.exchangeRate;
        cout << amount << " " << currencyCode << " = " << converted << " " << target.currencyCode << endl;
    }

    void displayCurrency()
    {
        cout << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }
};

class Dollar : public Currency
{
public:
    Dollar(float amt) : Currency(amt, "USD", "$", 1.0)
    {
    }

    void convertToBase()
    {
        cout << "Base value: " << amount << " USD (already base)" << endl;
    }

    void displayCurrency()
    {
        cout << "Dollar: $" << amount << endl;
    }
};

class Euro : public Currency
{
public:
    Euro(float amt) : Currency(amt, "EUR", "E", 1.08)
    {
    }

    void convertToBase()
    {
        cout << "Base value: " << amount * exchangeRate << " USD" << endl;
    }

    void displayCurrency()
    {
        cout << "Euro: E" << amount << " (Rate: " << exchangeRate << ")" << endl;
    }
};

class Rupee : public Currency
{
public:
    Rupee(float amt) : Currency(amt, "PKR", "Rs", 0.0036)
    {
    }

    void convertToBase()
    {
        cout << "Base value: " << amount * exchangeRate << " USD" << endl;
    }

    void displayCurrency()
    {
        cout << "Rupee: Rs" << amount << " (Rate: " << exchangeRate << ")" << endl;
    }
};

int main()
{
    Dollar d(100);
    d.displayCurrency();
    d.convertToBase();

    cout << endl;

    Euro e(50);
    e.displayCurrency();
    e.convertToBase();

    cout << endl;

    Rupee r(10000);
    r.displayCurrency();
    r.convertToBase();

    cout << endl;

    e.convertTo(d);

    return 0;
}
