#include <iostream>
using namespace std;

class Car
{
private:
    int speed;

public:
    void setSpeed(int s)
    {
        speed = s;
    }
    void showSpeed() const
    {
        cout << "Speed: " << speed << endl;
    }
};

int main()
{
    Car c;
    c.setSpeed(50);
    c.showSpeed();
    return 0;
}
