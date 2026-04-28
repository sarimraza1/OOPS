#pragma once
#include <iostream>
#include <string>
using namespace std;

class BikeType
{
private:
    int engStrokes;
    int ccPower;
    string kickOrSelf;
    string usedOrNew;
    string style;

public:
    BikeType()
    {
        engStrokes = 4;
        ccPower = 70;
        kickOrSelf = "Kick";
        usedOrNew = "Used";
        style = "Standard";
    }

    BikeType(int s, int c, string k, string u, string st)
    {
        engStrokes = s;
        ccPower = c;
        kickOrSelf = k;
        usedOrNew = u;
        style = st;
    }

    BikeType(const BikeType &obj)
    {
        engStrokes = obj.engStrokes;
        ccPower = obj.ccPower;
        kickOrSelf = obj.kickOrSelf;
        usedOrNew = obj.usedOrNew;
        style = obj.style;
    }

    int getStrokes() { return engStrokes; }
    int getCC() { return ccPower; }
    string getKickType() { return kickOrSelf; }

    void setStrokes(int s) { engStrokes = s; }
    void setCC(int c) { ccPower = c; }

    void showType() const
    {
        cout << ccPower << " cc | " << engStrokes << " Stroke";
    }

    bool isSelfStart() const
    {
        return kickOrSelf == "Self";
    }

    bool isNew() const
    {
        return usedOrNew == "New";
    }

    void getInput()
    {
        int opt;
        cout << "Strokes:\n1. 4-Stroke  2. 2-Stroke\nEnter: ";
        cin >> opt;
        engStrokes = (opt == 2) ? 2 : 4;

        cout << "CC Power: ";
        cin >> ccPower;

        cout << "Start:\n1.Kick 2.Self\nEnter: ";
        cin >> opt;
        kickOrSelf = (opt == 2) ? "Self" : "Kick";

        cout << "Condition:\n1.New 2.Used\nEnter: ";
        cin >> opt;
        usedOrNew = (opt == 1) ? "New" : "Used";

        cout << "Style:\n1.Standard 2.Sports\nEnter: ";
        cin >> opt;
        style = (opt == 2) ? "Sports" : "Standard";
    }
};
