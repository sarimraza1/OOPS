#include <iostream>
#include <string>
using namespace std;

class FootballPlayer
{
private:
    string playerName;
    string position;
    int goalCount;

public:
    FootballPlayer()
    {
        playerName = "Unknown Player";
        position = "Benchwarmer";
        goalCount = 0;
    }

    FootballPlayer(const FootballPlayer &player)
    {
        playerName = player.playerName;
        position = player.position;
        goalCount = player.goalCount;
    }

    FootballPlayer(string name, string pos = "Midfielder", int goals = 10)
    {
        playerName = name;
        position = pos;
        goalCount = goals;
    }

    void boostGoals(int goals)
    {
        goalCount += goals;
        cout << playerName << " scored " << goals << " more goals! Total: " << goalCount << endl;
    }

    void display()
    {
        cout << "\n====== Player Profile ======" << endl;
        cout << "Name: " << playerName << endl;
        cout << "Position: " << position << endl;
        cout << "Goals: " << goalCount << endl;

        if (goalCount > 50)
        {
            cout << "Ballon d'Or contender! Legendary status!" << endl;
        }
        else if (goalCount > 20)
        {
            cout << "Star player in the making!" << endl;
        }
        else
        {
            cout << "Keep working hard, champion!" << endl;
        }
        cout << "============================\n"
             << endl;
    }
};

int main()
{
    FootballPlayer player1;
    cout << "Player 1 (Default Constructor):" << endl;
    player1.display();

    FootballPlayer player2("Lionel Messi", "Forward", 800);
    cout << "Player 2 (Parameterized Constructor):" << endl;
    player2.display();

    FootballPlayer player3(player2);
    cout << "Player 3 (Copy Constructor - Clone of Messi):" << endl;
    player3.display();

    FootballPlayer player4("Cristiano Ronaldo");
    cout << "Player 4 (Default arguments - only name):" << endl;
    player4.display();

    FootballPlayer player5("Neymar Jr", "Winger");
    cout << "Player 5 (Default arguments - name and position):" << endl;
    player5.display();

    // Boosting goal counts
    cout << "=== Boosting Goals ===" << endl;
    player4.boostGoals(850);
    player4.display();

    player5.boostGoals(45);
    player5.display();

    cout << "=== All Players Created Successfully! ===" << endl;

    return 0;
}
