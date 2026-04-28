#include <iostream>
using namespace std;

class Person
{
public:
    string name;
    int id;
    string address;
    string phoneNumber;
    string email;

    Person(string n, int i, string addr, string phone, string mail)
    {
        name = n;
        id = i;
        address = addr;
        phoneNumber = phone;
        email = mail;
    }

    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }

    void updateInfo(string addr, string phone)
    {
        address = addr;
        phoneNumber = phone;
        cout << "Info updated." << endl;
    }
};

class Student : public Person
{
public:
    string coursesEnrolled;
    float GPA;
    int enrollmentYear;

    Student(string n, int i, string addr, string phone, string mail, string courses, float gpa, int year)
        : Person(n, i, addr, phone, mail)
    {
        coursesEnrolled = courses;
        GPA = gpa;
        enrollmentYear = year;
    }

    void displayInfo()
    {
        Person::displayInfo();
        cout << "Courses: " << coursesEnrolled << endl;
        cout << "GPA: " << GPA << endl;
        cout << "Enrollment Year: " << enrollmentYear << endl;
    }
};

class Professor : public Person
{
public:
    string department;
    string coursesTaught;
    float salary;

    Professor(string n, int i, string addr, string phone, string mail, string dept, string courses, float sal)
        : Person(n, i, addr, phone, mail)
    {
        department = dept;
        coursesTaught = courses;
        salary = sal;
    }

    void displayInfo()
    {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Courses Taught: " << coursesTaught << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Staff : public Person
{
public:
    string department;
    string position;
    float salary;

    Staff(string n, int i, string addr, string phone, string mail, string dept, string pos, float sal)
        : Person(n, i, addr, phone, mail)
    {
        department = dept;
        position = pos;
        salary = sal;
    }

    void displayInfo()
    {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Course
{
public:
    string courseId;
    string courseName;
    int credits;
    string instructor;
    string schedule;

    Course(string id, string name, int cr, string inst, string sched)
    {
        courseId = id;
        courseName = name;
        credits = cr;
        instructor = inst;
        schedule = sched;
    }

    void registerStudent(Student &s)
    {
        cout << s.name << " registered in " << courseName << endl;
    }

    void calculateGrades()
    {
        cout << "Grades calculated for course: " << courseName << endl;
    }

    void displayInfo()
    {
        cout << "Course ID: " << courseId << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Schedule: " << schedule << endl;
    }
};

int main()
{
    Student s("Ali", 101, "Karachi", "03001234567", "ali@uni.edu", "OOP, DSA", 3.8, 2022);
    cout << "--- Student ---" << endl;
    s.displayInfo();

    cout << endl;

    Professor p("Dr. Khan", 201, "Islamabad", "03119876543", "khan@uni.edu", "CS", "OOP, Algorithms", 150000);
    cout << "--- Professor ---" << endl;
    p.displayInfo();

    cout << endl;

    Staff st("Bilal", 301, "Lahore", "03211112222", "bilal@uni.edu", "Admin", "Registrar", 60000);
    cout << "--- Staff ---" << endl;
    st.displayInfo();

    cout << endl;

    Course c("CS301", "Object Oriented Programming", 3, "Dr. Khan", "Mon/Wed 10am");
    cout << "--- Course ---" << endl;
    c.displayInfo();
    c.registerStudent(s);
    c.calculateGrades();

    return 0;
}
