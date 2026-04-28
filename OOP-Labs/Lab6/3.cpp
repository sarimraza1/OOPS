#include <iostream>
using namespace std;

class Position
{
public:
    int x;
    int y;
    int z;

    void setPosition(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
    }

    void showPosition()
    {
        cout << "Position: (" << x << ", " << y << ", " << z << ")" << endl;
    }
};

class Health
{
public:
    int health;

    void setHealth(int h)
    {
        health = h;
    }

    void showHealth()
    {
        cout << "Health: " << health << endl;
    }
};

class Character : public Position, public Health
{
public:
    void display()
    {
        showPosition();
        showHealth();
    }
};

int main()
{
    Character c;
    c.setPosition(10, 20, 5);
    c.setHealth(100);
    c.display();
    return 0;
}
