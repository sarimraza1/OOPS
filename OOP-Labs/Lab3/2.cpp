#include <iostream>
#include <string>
using namespace std;

class WeekDays
{
private:
    string Days[7];
    int CurrentDay;

public:
    WeekDays()
    {
        Days[0] = "Sunday";
        Days[1] = "Monday";
        Days[2] = "Tuesday";
        Days[3] = "Wednesday";
        Days[4] = "Thursday";
        Days[5] = "Friday";
        Days[6] = "Saturday";
        CurrentDay = 0;
    }

    WeekDays(int day)
    {
        Days[0] = "Sunday";
        Days[1] = "Monday";
        Days[2] = "Tuesday";
        Days[3] = "Wednesday";
        Days[4] = "Thursday";
        Days[5] = "Friday";
        Days[6] = "Saturday";

        if (day > 6)
        {
            CurrentDay = day % 7;
        }
        else
        {
            CurrentDay = day;
        }
    }

    string getCurrentDay()
    {
        return Days[CurrentDay];
    }

    string getNextDay()
    {
        int nextDay = (CurrentDay + 1) % 7;
        return Days[nextDay];
    }

    string getPreviousDay()
    {
        int prevDay = (CurrentDay - 1 + 7) % 7;
        return Days[prevDay];
    }

    string getNthDayFromToday(int N)
    {
        int nthDay = (CurrentDay + N) % 7;
        return Days[nthDay];
    }
};

int main()
{
    WeekDays week1;
    cout << "Using Default Constructor:" << endl;
    cout << "Current Day: " << week1.getCurrentDay() << endl;
    cout << "Next Day: " << week1.getNextDay() << endl;
    cout << "Previous Day: " << week1.getPreviousDay() << endl;
    cout << "20 days from today: " << week1.getNthDayFromToday(20) << endl;
    cout << endl;

    WeekDays week2(1);
    cout << "Using Parameterized Constructor (day = 1):" << endl;
    cout << "Current Day: " << week2.getCurrentDay() << endl;
    cout << "Next Day: " << week2.getNextDay() << endl;
    cout << "Previous Day: " << week2.getPreviousDay() << endl;
    cout << "20 days from today: " << week2.getNthDayFromToday(20) << endl;
    cout << endl;

    WeekDays week3(8);
    cout << "Using Parameterized Constructor (day = 8, should be Monday):" << endl;
    cout << "Current Day: " << week3.getCurrentDay() << endl;
    cout << "Next Day: " << week3.getNextDay() << endl;
    cout << "Previous Day: " << week3.getPreviousDay() << endl;
    cout << "5 days from today: " << week3.getNthDayFromToday(5) << endl;
    cout << endl;

    return 0;
}
