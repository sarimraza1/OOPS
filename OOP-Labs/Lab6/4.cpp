#include <iostream>
using namespace std;

class Person
{
public:
    string name;
    int age;

    Person(string n, int a)
    {
        name = n;
        age = a;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person
{
public:
    int studentID;
    int gradeLevel;

    Student(string n, int a, int id, int gl) : Person(n, a)
    {
        studentID = id;
        gradeLevel = gl;
    }

    void display()
    {
        Person::display();
        cout << "Student ID: " << studentID << endl;
        cout << "Grade Level: " << gradeLevel << endl;
    }
};

class Teacher : public Person
{
public:
    string subject;
    int roomNumber;

    Teacher(string n, int a, string sub, int room) : Person(n, a)
    {
        subject = sub;
        roomNumber = room;
    }

    void display()
    {
        Person::display();
        cout << "Subject: " << subject << endl;
        cout << "Room Number: " << roomNumber << endl;
    }
};

class GraduateStudent : public Student, public Teacher
{
public:
    GraduateStudent(string n, int a, int id, int gl, string sub, int room)
        : Student(n, a, id, gl), Teacher(n, a, sub, room)
    {
    }

    void display()
    {
        cout << "Name: " << Student::name << endl;
        cout << "Age: " << Student::age << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Grade Level: " << gradeLevel << endl;
        cout << "Subject: " << subject << endl;
        cout << "Room Number: " << roomNumber << endl;
    }
};

int main()
{
    GraduateStudent gs("Ali", 24, 1021, 4, "Math", 305);
    gs.display();
    return 0;
}
