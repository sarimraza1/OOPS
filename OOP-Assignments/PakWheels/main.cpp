#include <iostream>
#include <string>
#include "CarType.h"
#include "BikeType.h"
#include "Car.h"
#include "Bike.h"
#include "Seller.h"
#include "Buyer.h"
#include "Admin.h"
#include "Accessory.h"
#include "Blog.h"
#include "Message.h"

using namespace std;

const int MAX_CARS = 50;
const int MAX_BIKES = 50;
const string APP_NAME = "SlowWheels";
const int MAX_MSG = 20;
const string admpass = "admin123";

Car carList[MAX_CARS];
int carsTotal = 0;
Bike bikeList[MAX_BIKES];
int bikesTotal = 0;
Accessory accList[10];
int accTotal = 0;
Message msgList[MAX_MSG];
int msgTotal = 0;

Seller seller1("Sarim", "sarim@gmail.com", "067-1234567", "Karachi", "Lol");
Buyer buyer1("Taher", "0123-456789", "taher@gmail.com", "Islamabad", 550);
Admin admin1("Admin", "admin@pakwheels.com", "0333-3333333");

void addSampleData()
{
    CarType sedanCar("Sedan", "Petrol", "Automatic", 1800, "Local");
    CarType suvCar("SUV", "Diesel", "Automatic", 2800, "Imported");
    BikeType hondaBike(4, 70, "Kick", "Used", "Standard");

    carList[carsTotal++] = Car("Toyota", "Corolla", 2022, 500, 12345, "Lahore", sedanCar, "Sarim");
    carList[carsTotal++] = Car("Honda", "Civic", 2020, 550, 12345, "Karachi", suvCar, "Abbas");
    carList[0].setIsApproved(true);
    carList[1].setIsApproved(true);

    bikeList[bikesTotal++] = Bike("Honda", "CD70", 2022, 150, 6767, "Lahore", hondaBike, "Sarim");
    bikeList[0].setIsApproved(true);

    accList[accTotal++] = Accessory("Car Shiner", 50, "Cleaning", "00", 50);
}

int main()
{
    addSampleData();
    cout << "Welcome to " << APP_NAME << endl;

    int opt;
    do
    {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Browse Cars\n";
        cout << "2. Browse Bikes\n";
        cout << "3. Post Car Ad (Seller)\n";
        cout << "4. Filter Cars\n";
        cout << "5. Update Listing Price\n";
        cout << "6. Remove My Listing\n";
        cout << "7. Save to Favorites\n";
        cout << "8. View Favorites\n";
        cout << "9. Send Message\n";
        cout << "10. View Profiles\n";
        cout << "11. Admin Panel\n";
        cout << "12. Accessories\n";
        cout << "13. Blog Posts\n";
        cout << "0. Quit\n";
        cout << "Enter: ";
        cin >> opt;

        switch (opt)
        {
        case 1:
            cout << "\n--- Approved Cars ---\n";
            for (int i = 0; i < carsTotal; i++)
                if (carList[i].getIsApproved())
                    carList[i].showDetails();
            break;

        case 2:
            cout << "\n--- Approved Bikes ---\n";
            for (int i = 0; i < bikesTotal; i++)
                if (bikeList[i].getIsApproved())
                    bikeList[i].showDetails();
            break;

        case 3:
            carList[carsTotal].getInput("Sarim");
            seller1.addListing(carList[carsTotal].getBrand() + " " + carList[carsTotal].getModel());
            carsTotal++;
            cout << "Car added! Waiting for admin approval.\n";
            break;

        case 4:
        {
            long maxPr;
            int minYr, maxKm;
            cout << "Max Price (0 to skip): ";
            cin >> maxPr;
            cout << "Min Year (0 to skip): ";
            cin >> minYr;
            cout << "Max Mileage (0 to skip): ";
            cin >> maxKm;
            cout << "\nMatching Cars:\n";
            for (int i = 0; i < carsTotal; i++)
                if (carList[i].getIsApproved() && carList[i].checkFilter(maxPr, minYr, maxKm))
                    carList[i].showDetails();
            break;
        }

        case 5:
        {
            cout << "Your Listings:\n";
            for (int i = 0; i < carsTotal; i++)
                cout << i << ". " << carList[i].getBrand() << " " << carList[i].getModel() << endl;
            int idx;
            long newPrice;
            cout << "Enter listing number: ";
            cin >> idx;
            if (idx >= 0 && idx < carsTotal)
            {
                cout << "Enter new price: ";
                cin >> newPrice;
                carList[idx].updatePrice(newPrice);
            }
            break;
        }

        case 6:
        {
            cout << "Your Listings:\n";
            for (int i = 0; i < carsTotal; i++)
                cout << i << ". " << carList[i].getBrand() << " " << carList[i].getModel() << endl;
            int idx;
            cout << "Enter listing number to remove: ";
            cin >> idx;
            if (idx >= 0 && idx < carsTotal)
            {
                for (int i = idx; i < carsTotal - 1; i++)
                    carList[i] = carList[i + 1];
                carsTotal--;
                cout << "Listing removed!\n";
            }
            break;
        }

        case 7:
        {
            cout << "Available Cars:\n";
            for (int i = 0; i < carsTotal; i++)
                if (carList[i].getIsApproved())
                    cout << i << ". " << carList[i].getBrand() << " " << carList[i].getModel() << endl;
            int num;
            cout << "Enter car number to save: ";
            cin >> num;
            if (num >= 0 && num < carsTotal)
            {
                buyer1.saveFavorite(num);
                cout << "Saved to favorites!\n";
            }
            break;
        }

        case 8:
        {
            cout << "\n--- Your Favorites ---\n";
            if (buyer1.getSavedCount() == 0)
            {
                cout << "No saved cars yet.\n";
            }
            else
            {
                for (int i = 0; i < buyer1.getSavedCount(); i++)
                {
                    int carIdx = buyer1.getSavedCar(i);
                    cout << i + 1 << ". " << carList[carIdx].getBrand() << " " << carList[carIdx].getModel() << endl;
                }
            }
            break;
        }

        case 9:
            msgList[msgTotal].getInput("Taher");
            msgTotal++;
            cout << "Message sent!\n";
            msgList[msgTotal - 1].showMessage();
            break;

        case 10:
        {
            int choice;
            cout << "1. Seller Profile\n2. Buyer Profile\n3. Admin Profile\nEnter: ";
            cin >> choice;
            if (choice == 1)
            {
                cout << "\n--- Seller Profile ---\n";
                seller1.showInfo();
                cout << "Posted Ads: " << seller1.getListingCount() << endl;
            }
            else if (choice == 2)
            {
                cout << "\n--- Buyer Profile ---\n";
                buyer1.showInfo();
            }
            else if (choice == 3)
            {
                cout << "\n--- Admin Profile ---\n";
                admin1.showInfo();
            }
            break;
        }

        case 11:
        {
            string pw;
            cout << "Enter admin password: ";
            cin >> pw;
            if (!admin1.login(pw, admpass))
            {
                cout << "Wrong password!\n";
                break;
            }
            cout << "Login successful!\n";
            int adminOpt;
            do
            {
                cout << "\n--- Admin Panel ---\n";
                cout << "1. Approve Listing\n";
                cout << "2. Remove Listing\n";
                cout << "3. View All Listings\n";
                cout << "0. Back to Main Menu\n";
                cout << "Enter: ";
                cin >> adminOpt;

                if (adminOpt == 1)
                {
                    int choice;
                    cout << "1. Approve Car\n2. Approve Bike\nEnter: ";
                    cin >> choice;
                    if (choice == 1)
                    {
                        cout << "Pending Cars:\n";
                        bool found = false;
                        for (int i = 0; i < carsTotal; i++)
                            if (!carList[i].getIsApproved())
                            {
                                cout << i << ". " << carList[i].getBrand() << " " << carList[i].getModel() << endl;
                                found = true;
                            }
                        if (!found)
                        {
                            cout << "No pending cars.\n";
                            break;
                        }
                        int idx;
                        cout << "Enter car number to approve: ";
                        cin >> idx;
                        if (idx >= 0 && idx < carsTotal)
                            admin1.approveCar(carList[idx]);
                    }
                    else if (choice == 2)
                    {
                        cout << "Pending Bikes:\n";
                        bool found = false;
                        for (int i = 0; i < bikesTotal; i++)
                            if (!bikeList[i].getIsApproved())
                            {
                                cout << i << ". " << bikeList[i].getBrand() << " " << bikeList[i].getModel() << endl;
                                found = true;
                            }
                        if (!found)
                        {
                            cout << "No pending bikes.\n";
                            break;
                        }
                        int idx;
                        cout << "Enter bike number to approve: ";
                        cin >> idx;
                        if (idx >= 0 && idx < bikesTotal)
                            admin1.approveBike(bikeList[idx]);
                    }
                }
                else if (adminOpt == 2)
                {
                    cout << "All Cars:\n";
                    for (int i = 0; i < carsTotal; i++)
                        cout << i << ". " << carList[i].getBrand() << " " << carList[i].getModel()
                             << (carList[i].getIsApproved() ? " [Approved]" : " [Pending]") << endl;
                    int idx;
                    cout << "Enter car number to remove: ";
                    cin >> idx;
                    if (idx >= 0 && idx < carsTotal)
                    {
                        admin1.removeCar(carList[idx]);
                    }
                }
                else if (adminOpt == 3)
                {
                    cout << "\n--- All Cars ---\n";
                    for (int i = 0; i < carsTotal; i++)
                    {
                        cout << i << ". " << carList[i].getBrand() << " " << carList[i].getModel()
                             << (carList[i].getIsApproved() ? " [Approved]" : " [Pending]") << endl;
                    }
                    cout << "\n--- All Bikes ---\n";
                    for (int i = 0; i < bikesTotal; i++)
                    {
                        cout << i << ". " << bikeList[i].getBrand() << " " << bikeList[i].getModel()
                             << (bikeList[i].getIsApproved() ? " [Approved]" : " [Pending]") << endl;
                    }
                    cout << "\nTotal Cars: " << Car::getTotalCars() << endl;
                    cout << "Total Bikes: " << Bike::getTotalBikes() << endl;
                }
            } while (adminOpt != 0);
            break;
        }

        case 12:
            cout << "\n--- Accessories ---\n";
            for (int i = 0; i < accTotal; i++)
                accList[i].showAccessory();
            break;

        case 13:
        {
            Blog post("Best Cars 2024", "Toyota leads the market", "Sarim", "Review");
            post.addView();
            post.showBlog();
            break;
        }

        case 0:
            cout << "Thanks for using " << APP_NAME << "!\n";
            break;
        }
    } while (opt != 0);

    return 0;
}
