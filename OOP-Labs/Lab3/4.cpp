#include <iostream>
#include <string>
using namespace std;

class CricketPlayer
{
private:
    string name;
    int jerseyNumber;
    double battingAverage;

public:
    CricketPlayer(string name, int jerseyNumber, double battingAverage)
    {
        this->name = name;
        this->jerseyNumber = jerseyNumber;
        this->battingAverage = battingAverage;
    }

    CricketPlayer &improveAverage(int runs)
    {
        this->battingAverage += runs;
        cout << this->name << "'s batting average improved by " << runs << " points!" << endl;
        return *this;
    }

    CricketPlayer &playMatch(int runsScored)
    {
        this->battingAverage += runsScored;

        if (runsScored >= 100)
        {
            cout << this->name << " scored a CENTURY! " << runsScored << " runs!" << endl;
        }
        else if (runsScored == 0)
        {
            cout << this->name << " got a GOLDEN DUCK! Better luck next time!" << endl;
        }
        else
        {
            cout << this->name << " scored " << runsScored << " runs in the match." << endl;
        }
        return *this;
    }

    void displayPlayerStats()
    {
        cout << "\n====== Player Stats ======" << endl;
        cout << "Name: " << this->name << endl;
        cout << "Jersey Number: " << this->jerseyNumber << endl;
        cout << "Batting Average: " << this->battingAverage << endl;

        if (this->battingAverage > 50)
        {
            cout << "This batting average is more consistent than Karachi's weather!" << endl;
        }
        cout << "==========================\n"
             << endl;
    }
};

int main()
{
    cout << "=== Creating Pakistan Cricket Dream Squad ===" << endl
         << endl;

    CricketPlayer babar("Babar Azam", 56, 0);
    CricketPlayer rizwan("Muhammad Rizwan", 51, 0);
    CricketPlayer saim("Saim Ayub", 28, 0);

    cout << "\n=== Playing Matches ===" << endl
         << endl;

    babar.playMatch(120)
        .playMatch(85)
        .playMatch(56);
    babar.improveAverage(5).improveAverage(3);
    babar.displayPlayerStats();

    rizwan.playMatch(78)
        .playMatch(0)
        .playMatch(104);
    rizwan.improveAverage(10);
    rizwan.displayPlayerStats();

    saim.playMatch(65)
        .playMatch(43)
        .playMatch(150);
    saim.improveAverage(8).improveAverage(5).improveAverage(2);
    saim.displayPlayerStats();

    cout << "=== Dream Squad Stats Complete ===" << endl;

    return 0;
}
