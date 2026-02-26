#include <iostream>
using namespace std;

class Weapon
{
public:
    string weaponName;
    int damage;
    Weapon(string n = "", int d = 0)
    {
        weaponName = n;
        damage = d;
    }
};

class Player
{
public:
    string playerName;
    int health;
    Weapon weapon;
    static int activePlayers;
    Player(string n, int h, string wName, int dmg) : weapon(wName, dmg)
    {
        playerName = n;
        health = h;
        activePlayers++;
    }
    ~Player()
    {
        activePlayers--;
    }
    void showStatus() const
    {
        cout << playerName << " " << health << " " << weapon.weaponName << " " << weapon.damage << " Active: " << activePlayers << endl;
    }
};

int Player::activePlayers = 0;

int main()
{
    Player *arr = new Player[2]{
        Player("Sarim", 100, "Rascals", 30),
        Player("Abbas", 90, "MegaKnight", 20)};
    arr[0].showStatus();
    arr[1].showStatus();
    delete[] arr;
    cout << Player::activePlayers << endl;
    return 0;
}
