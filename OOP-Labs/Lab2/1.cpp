#include <iostream>
#include <string>
using namespace std;

struct Book
{
    string title;
    string author;
    int year;
    string genre;
};

void displayBook(Book b)
{
    cout << "Title: " << b.title << endl;
    cout << "Author: " << b.author << endl;
    cout << "Year: " << b.year << endl;
    cout << "Genre: " << b.genre << endl;
}

void searchBook(Book books[], int count)
{
    int choice;
    string searchTerm;
    cout << "1. Search by Title" << endl;
    cout << "2. Search by Author" << endl;
    cout << "Choose: ";
    cin >> choice;
    cin.ignore();
    cout << "Enter search term: ";
    getline(cin, searchTerm);

    for (int i = 0; i < count; i++)
    {
        if (choice == 1 && books[i].title == searchTerm)
        {
            cout << "Book Found:" << endl;
            displayBook(books[i]);
            return;
        }
        if (choice == 2 && books[i].author == searchTerm)
        {
            cout << "Book Found:" << endl;
            displayBook(books[i]);
            return;
        }
    }
    cout << "Book not found!" << endl;
}

int main()
{
    Book library[100];
    int count = 0;
    int choice;

    while (true)
    {
        cout << "\n1. Add Book" << endl;
        cout << "2. Display All Books" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Update Book" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1)
        {
            cin.ignore();
            cout << "Enter Title: ";
            getline(cin, library[count].title);
            cout << "Enter Author: ";
            getline(cin, library[count].author);
            cout << "Enter Year: ";
            cin >> library[count].year;
            cin.ignore();
            cout << "Enter Genre: ";
            getline(cin, library[count].genre);
            count++;
        }
        else if (choice == 2)
        {
            for (int i = 0; i < count; i++)
            {
                cout << "\nBook " << i + 1 << ":" << endl;
                displayBook(library[i]);
            }
        }
        else if (choice == 3)
        {
            searchBook(library, count);
        }
        else if (choice == 4)
        {
            int bookNo;
            cout << "Enter book number to update: ";
            cin >> bookNo;
            bookNo--;
            if (bookNo >= 0 && bookNo < count)
            {
                cin.ignore();
                cout << "Enter Title: ";
                getline(cin, library[bookNo].title);
                cout << "Enter Author: ";
                getline(cin, library[bookNo].author);
                cout << "Enter Year: ";
                cin >> library[bookNo].year;
                cin.ignore();
                cout << "Enter Genre: ";
                getline(cin, library[bookNo].genre);
            }
        }
        else if (choice == 5)
        {
            break;
        }
    }
    return 0;
}
