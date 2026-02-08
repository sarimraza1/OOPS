#include <iostream>
#include <string>
using namespace std;

class SmartDevice
{
private:
    string deviceName;
    string type;
    bool status;

public:
    SmartDevice(string name, string t, bool s)
    {
        deviceName = name;
        type = t;
        status = s;
        cout << deviceName << " (" << type << ") has been powered ON!" << endl;
    }

    ~SmartDevice()
    {
        cout << deviceName << " (" << type << ") is powering down... Goodbye, dear human! I served you well." << endl;
    }

    void display()
    {
        cout << "Device: " << deviceName << endl;
        cout << "Type: " << type << endl;
        cout << "Status: " << (status ? "ON" : "OFF") << endl;
        cout << endl;
    }
};

int main()
{
    cout << "=== Creating Smart Devices ===" << endl
         << endl;

    SmartDevice light("Living Room Light", "Smart Light", true);
    light.display();

    SmartDevice vacuum("RoboVac 3000", "Robo-Vacuum", false);
    vacuum.display();

    SmartDevice coffee("CoffeeMaster", "Coffee Overlord", true);
    coffee.display();

    cout << "=== Creating device with dynamic allocation ===" << endl
         << endl;
    SmartDevice *fan = new SmartDevice("Ceiling Fan", "Smart Fan", true);
    fan->display();

    cout << "=== Deleting dynamically allocated device ===" << endl;
    delete fan;

    cout << endl
         << "=== Program ending, local objects will be destroyed ===" << endl
         << endl;

    return 0;
}
