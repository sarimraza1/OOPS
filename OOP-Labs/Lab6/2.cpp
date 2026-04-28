#include <iostream>
using namespace std;

class Character
{
public:
    int health;
    int damage;

    Character(int h, int d)
    {
        health = h;
        damage = d;
    }

    void display()
    {
        cout << "Health: " << health << endl;
        cout << "Damage: " << damage << endl;
    }
};

class Enemy : public Character
{
public:
    Enemy(int h, int d) : Character(h, d)
    {
    }

    void display()
    {
        cout << "--- Enemy ---" << endl;
        Character::display();
    }
};

class Player : public Character
{
public:
    Player(int h, int d) : Character(h, d)
    {
    }

    void display()
    {
        cout << "--- Player ---" << endl;
        Character::display();
    }
};

class Wizard : public Player
{
public:
    int magicPower;
    string spells;

    Wizard(int h, int d, int mp, string s) : Player(h, d)
    {
        magicPower = mp;
        spells = s;
    }

    void display()
    {
        cout << "--- Wizard ---" << endl;
        Character::display();
        cout << "Magic Power: " << magicPower << endl;
        cout << "Spells: " << spells << endl;
    }
};

int main()
{
    Wizard w(200, 50, 150, "Fireball");
    w.display();
    return 0;
}
