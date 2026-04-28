#include <iostream>
using namespace std;

class Media
{
public:
    string title;
    string publicationDate;
    int uniqueID;
    string publisher;
    bool checkedOut;

    Media(string t, string date, int id, string pub)
    {
        title = t;
        publicationDate = date;
        uniqueID = id;
        publisher = pub;
        checkedOut = false;
    }

    void displayInfo()
    {
        cout << "Title: " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "ID: " << uniqueID << endl;
        cout << "Publisher: " << publisher << endl;
    }

    void checkOut()
    {
        if (checkedOut)
        {
            cout << title << " is already checked out." << endl;
        }
        else
        {
            checkedOut = true;
            cout << title << " checked out successfully." << endl;
        }
    }

    void returnItem()
    {
        checkedOut = false;
        cout << title << " returned." << endl;
    }
};

class Book : public Media
{
public:
    string author;
    string ISBN;
    int numberOfPages;

    Book(string t, string date, int id, string pub, string auth, string isbn, int pages)
        : Media(t, date, id, pub)
    {
        author = auth;
        ISBN = isbn;
        numberOfPages = pages;
    }

    void displayInfo()
    {
        Media::displayInfo();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Pages: " << numberOfPages << endl;
    }
};

class DVD : public Media
{
public:
    string director;
    int duration;
    string rating;

    DVD(string t, string date, int id, string pub, string dir, int dur, string rate)
        : Media(t, date, id, pub)
    {
        director = dir;
        duration = dur;
        rating = rate;
    }

    void displayInfo()
    {
        Media::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " mins" << endl;
        cout << "Rating: " << rating << endl;
    }
};

class CD : public Media
{
public:
    string artist;
    int numberOfTracks;
    string genre;

    CD(string t, string date, int id, string pub, string art, int tracks, string gen)
        : Media(t, date, id, pub)
    {
        artist = art;
        numberOfTracks = tracks;
        genre = gen;
    }

    void displayInfo()
    {
        Media::displayInfo();
        cout << "Artist: " << artist << endl;
        cout << "Tracks: " << numberOfTracks << endl;
        cout << "Genre: " << genre << endl;
    }
};

// overloaded search functions
void search(Book arr[], int size, string title)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i].title == title)
        {
            cout << "Found by title:" << endl;
            arr[i].displayInfo();
            return;
        }
    }
    cout << "Not found by title." << endl;
}

void search(Book arr[], int size, string author, bool byAuthor)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i].author == author)
        {
            cout << "Found by author:" << endl;
            arr[i].displayInfo();
            return;
        }
    }
    cout << "Not found by author." << endl;
}

int main()
{
    Book b1("The Alchemist", "1988", 1, "HarperCollins", "Paulo Coelho", "978-0062316097", 208);
    Book b2("1984", "1949", 2, "Secker & Warburg", "George Orwell", "978-0451524935", 328);

    cout << "--- Book 1 ---" << endl;
    b1.displayInfo();
    b1.checkOut();
    b1.checkOut();
    b1.returnItem();

    cout << endl;

    DVD d("Inception", "2010", 3, "Warner Bros", "Christopher Nolan", 148, "PG-13");
    cout << "--- DVD ---" << endl;
    d.displayInfo();

    cout << endl;

    CD c("Thriller", "1982", 4, "Epic Records", "Michael Jackson", 9, "Pop");
    cout << "--- CD ---" << endl;
    c.displayInfo();

    cout << endl;

    Book books[2] = {b1, b2};
    cout << "--- Search by Title ---" << endl;
    search(books, 2, "1984");
    cout << endl;
    cout << "--- Search by Author ---" << endl;
    search(books, 2, "Paulo Coelho", true);

    return 0;
}
