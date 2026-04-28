#include <iostream>
using namespace std;

class Book
{
public:
    string title;
    string author;
    string publisher;

    Book(string t, string a, string p)
    {
        title = t;
        author = a;
        publisher = p;
    }

    void display()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
    }
};

class FictionBook : public Book
{
public:
    string genre;
    string protagonist;

    FictionBook(string t, string a, string p, string g, string pr) : Book(t, a, p)
    {
        genre = g;
        protagonist = pr;
    }

    void display()
    {
        Book::display();
        cout << "Genre: " << genre << endl;
        cout << "Protagonist: " << protagonist << endl;
    }
};

int main()
{
    FictionBook fb("The Hobbit", "Alex Rider", "Hardy Bois", "Fantasy", "Bilbo Baggins");
    fb.display();
    return 0;
}


