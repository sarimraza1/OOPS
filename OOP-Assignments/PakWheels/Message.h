#pragma once
#include <iostream>
#include <string>
using namespace std;

class Message
{
private:
    string fromUser;
    string toUser;
    string subject;
    string content;
    bool readStatus;

public:
    Message()
    {
        fromUser = "N/A";
        toUser = "N/A";
        subject = "N/A";
        content = "N/A";
        readStatus = false;
    }

    Message(string s, string r, string sub, string c)
    {
        fromUser = s;
        toUser = r;
        subject = sub;
        content = c;
        readStatus = false;
    }

    Message(const Message &obj)
    {
        fromUser = obj.fromUser;
        toUser = obj.toUser;
        subject = obj.subject;
        content = obj.content;
        readStatus = obj.readStatus;
    }

    string getSender() const { return fromUser; }
    string getReceiver() const { return toUser; }

    void showMessage() const
    {
        cout << "Sender: " << fromUser << " | Receiver: " << toUser << endl;
        cout << "Title: " << subject << endl;
        cout << "  " << content << endl;
    }

    void getInput(string senderName)
    {
        fromUser = senderName;
        cout << "Send To: ";
        cin >> toUser;
        cout << "Title: ";
        cin >> subject;
        cout << "Content: ";
        cin >> content;
    }

    void markAsRead()
    {
        readStatus = true;
    }

    bool isRead() const
    {
        return readStatus;
    }
};
