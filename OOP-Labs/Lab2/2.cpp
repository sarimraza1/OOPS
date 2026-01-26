#include <iostream>
#include <string>
using namespace std;

struct Product
{
    int id;
    string name;
    double price;
    int quantity;
};

Product products[100];
int count = 0;

// a) Add new product
void addProduct(string name, double price, int quantity)
{
    products[count].id = count + 1;
    products[count].name = name;
    products[count].price = price;
    products[count].quantity = quantity;
    count++;
}

// b) Display product by ID
void displayProduct(int id)
{
    for (int i = 0; i < count; i++)
    {
        if (products[i].id == id)
        {
            cout << "ID: " << products[i].id << endl;
            cout << "Name: " << products[i].name << endl;
            cout << "Price: " << products[i].price << endl;
            cout << "Quantity: " << products[i].quantity << endl;
            return;
        }
    }
    cout << "Product not found!" << endl;
}

// c) Update product by ID
void updateProduct(int id, string name, double price, int quantity)
{
    for (int i = 0; i < count; i++)
    {
        if (products[i].id == id)
        {
            products[i].name = name;
            products[i].price = price;
            products[i].quantity = quantity;
            return;
        }
    }
}

// d) Remove product by ID
void removeProduct(int id)
{
    for (int i = 0; i < count; i++)
    {
        if (products[i].id == id)
        {
            for (int j = i; j < count - 1; j++)
            {
                products[j] = products[j + 1];
            }
            count--;
            return;
        }
    }
}

int main()
{
    addProduct("Laptop", 50000, 10);
    addProduct("Phone", 25000, 20);

    displayProduct(1);

    updateProduct(1, "Laptop Pro", 60000, 5);
    displayProduct(1);

    removeProduct(2);

    return 0;
}
