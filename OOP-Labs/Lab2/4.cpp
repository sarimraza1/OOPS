#include <iostream>
using namespace std;

class StationeryShop
{
    string items[100];
    double prices[100];
    int count;

public:
    StationeryShop()
    {
        count = 0;
    }
    void addItem(string name, double price)
    {
        items[count] = name;
        prices[count] = price;
        count++;
        cout << "Item added!" << endl;
    }
    void displayItems()
    {
        cout << "\n--- All Items ---" << endl;
        for (int i = 0; i < count; i++)
        {
            cout << i + 1 << ". " << items[i] << " - Rs." << prices[i] << endl;
        }
    }
    void editPrice(int index, double newPrice)
    {
        if (index >= 0 && index < count)
        {
            prices[index] = newPrice;
            cout << "Price updated!" << endl;
        }
        else
        {
            cout << "Invalid item number!" << endl;
        }
    }
    void generateReceipt()
    {
        string purchasedItems[100];
        int quantities[100];
        int pCount = 0;
        double total = 0;
        char more;

        cout << "\n--- Enter Purchased Items ---" << endl;
        do
        {
            string itemName;
            int qty;
            cout << "Enter item name: ";
            cin.ignore();
            getline(cin, itemName);
            cout << "Enter quantity: ";
            cin >> qty;

            bool found = false;
            for (int i = 0; i < count; i++)
            {
                if (items[i] == itemName)
                {
                    purchasedItems[pCount] = itemName;
                    quantities[pCount] = qty;
                    total += prices[i] * qty;
                    pCount++;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Item not found!" << endl;
            }

            cout << "Add more items? (y/n): ";
            cin >> more;
        } while (more == 'y' || more == 'Y');

        cout << "\n========== RECEIPT ==========" << endl;
        for (int i = 0; i < pCount; i++)
        {
            for (int j = 0; j < count; j++)
            {
                if (items[j] == purchasedItems[i])
                {
                    cout << purchasedItems[i] << " x" << quantities[i] << " = Rs." << prices[j] * quantities[i] << endl;
                    break;
                }
            }
        }

        cout << "Total: Rs." << total << endl;
    }
};

int main()
{
    StationeryShop shop;
    int choice;

    while (true)
    {
        cout << "\n1. Add Item" << endl;
        cout << "2. View All Items" << endl;
        cout << "3. Edit Item Price" << endl;
        cout << "4. Generate Receipt" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1)
        {
            string name;
            double price;
            cin.ignore();
            cout << "Enter item name: ";
            getline(cin, name);
            cout << "Enter price: ";
            cin >> price;
            shop.addItem(name, price);
        }
        else if (choice == 2)
        {
            shop.displayItems();
        }
        else if (choice == 3)
        {
            shop.displayItems();
            int itemNo;
            double newPrice;
            cout << "Enter item number to edit: ";
            cin >> itemNo;
            cout << "Enter new price: ";
            cin >> newPrice;
            shop.editPrice(itemNo - 1, newPrice);
        }
        else if (choice == 4)
        {
            shop.generateReceipt();
        }
        else if (choice == 5)
        {
            break;
        }
    }
    return 0;
}
