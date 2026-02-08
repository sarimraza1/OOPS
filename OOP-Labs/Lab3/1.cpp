#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string title;
    string author;
    double price;

public:
    Book()
    {
        title = "Untitled";
        author = "Anonymous";
        price = 0.0;
    }

    Book(const Book &b)
    {
        title = b.title;
        author = b.author;
        price = b.price;
    }

    Book(string t, string a = "Unknown", double p = 0.0)
    {
        title = t;
        author = a;
        price = p;
    }

    void display()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: $" << price << endl;
        cout << endl;
    }
};

int main()
{
    Book book1;
    cout << "Book 1 (Default Constructor):" << endl;
    book1.display();

    Book book2("The Alchemist", "Paulo Coelho", 15.99);
    cout << "Book 2 (Parameterized Constructor):" << endl;
    book2.display();

    Book book3(book2);
    cout << "Book 3 (Copy Constructor from Book 2):" << endl;
    book3.display();

    Book book4("Harry Potter");
    cout << "Book 4 (Constructor with default arguments - only title):" << endl;
    book4.display();

    Book book5("1984", "George Orwell");
    cout << "Book 5 (Constructor with default arguments - title and author):" << endl;
    book5.display();

    return 0;
}
