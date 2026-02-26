#include <iostream>
using namespace std;

class Player
{
public:
    string name;
    static int totalPlayers;
    Player(string n)
    {
        name = n;
        totalPlayers++;
    }
    ~Player()
    {
        totalPlayers--;
    }
    static void showPlayers()
    {
        cout << totalPlayers << endl;
    }
};

int Player::totalPlayers = 0;

int main()
{
    {
        Player p1("Sarim"), p2("Abbas");
        Player::showPlayers();
    }
    Player::showPlayers();
    return 0;
}
