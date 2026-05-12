#pragma once
#include <iostream>
#include <string>
using namespace std;

class Blog
{
private:
    string title;
    string content;
    string author;
    string category;
    int views;

public:
    Blog()
    {
        title = "N/A";
        content = "N/A";
        author = "N/A";
        category = "N/A";
        views = 0;
    }

    Blog(string t, string c, string a, string cat)
    {
        title = t;
        content = c;
        author = a;
        category = cat;
        views = 0;
    }

    Blog(const Blog &obj)
    {
        title = obj.title;
        content = obj.content;
        author = obj.author;
        category = obj.category;
        views = obj.views;
    }

    string getTitle() const { return title; }

    void showBlog() const
    {
        cout << title << " | Writer: " << author << " | Read: " << views << " times" << endl;
        cout << "  " << content << endl;
    }

    void addView()
    {
        views++;
    }

    bool isPopular() const
    {
        return views > 100;
    }

    bool matchAuthor(string name) const
    {
        return author == name;
    }
};
