#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
public:
    string color;
    float borderThickness;

    Shape(string c, float bt)
    {
        color = c;
        borderThickness = bt;
    }

    void draw()
    {
        cout << "Drawing a shape." << endl;
    }

    void calculateArea()
    {
        cout << "Area: N/A" << endl;
    }

    void calculatePerimeter()
    {
        cout << "Perimeter: N/A" << endl;
    }
};

class Circle : public Shape
{
public:
    float radius;
    float centerX;
    float centerY;

    Circle(string c, float bt, float r, float cx, float cy) : Shape(c, bt)
    {
        radius = r;
        centerX = cx;
        centerY = cy;
    }

    void draw()
    {
        cout << "Drawing Circle at (" << centerX << ", " << centerY << ") with radius " << radius << endl;
    }

    void calculateArea()
    {
        float area = 3.14 * radius * radius;
        cout << "Circle Area: " << area << endl;
    }

    void calculatePerimeter()
    {
        float perimeter = 2 * 3.14 * radius;
        cout << "Circle Perimeter: " << perimeter << endl;
    }
};

class Rectangle : public Shape
{
public:
    float width;
    float height;
    float topLeftX;
    float topLeftY;

    Rectangle(string c, float bt, float w, float h, float x, float y) : Shape(c, bt)
    {
        width = w;
        height = h;
        topLeftX = x;
        topLeftY = y;
    }

    void draw()
    {
        cout << "Drawing Rectangle at (" << topLeftX << ", " << topLeftY << ") width=" << width << " height=" << height << endl;
    }

    void calculateArea()
    {
        cout << "Rectangle Area: " << width * height << endl;
    }

    void calculatePerimeter()
    {
        cout << "Rectangle Perimeter: " << 2 * (width + height) << endl;
    }
};

class Triangle : public Shape
{
public:
    float side1;
    float side2;
    float side3;

    Triangle(string c, float bt, float s1, float s2, float s3) : Shape(c, bt)
    {
        side1 = s1;
        side2 = s2;
        side3 = s3;
    }

    void draw()
    {
        cout << "Drawing Triangle with sides " << side1 << ", " << side2 << ", " << side3 << endl;
    }

    void calculateArea()
    {
        float s = (side1 + side2 + side3) / 2;
        float area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
        cout << "Triangle Area: " << area << endl;
    }

    void calculatePerimeter()
    {
        cout << "Triangle Perimeter: " << side1 + side2 + side3 << endl;
    }
};

class Polygon : public Shape
{
public:
    int sides;
    float sideLength;

    Polygon(string c, float bt, int n, float sl) : Shape(c, bt)
    {
        sides = n;
        sideLength = sl;
    }

    void draw()
    {
        cout << "Drawing Polygon with " << sides << " sides of length " << sideLength << endl;
    }

    void calculateArea()
    {
        float area = (sides * sideLength * sideLength) / (4 * tan(3.14159 / sides));
        cout << "Polygon Area: " << area << endl;
    }

    void calculatePerimeter()
    {
        cout << "Polygon Perimeter: " << sides * sideLength << endl;
    }
};

int main()
{
    Circle c("Red", 1.5, 7.0, 0, 0);
    c.draw();
    c.calculateArea();
    c.calculatePerimeter();

    cout << endl;

    Rectangle r("Blue", 2.0, 10, 5, 1, 1);
    r.draw();
    r.calculateArea();
    r.calculatePerimeter();

    cout << endl;

    Triangle t("Green", 1.0, 3, 4, 5);
    t.draw();
    t.calculateArea();
    t.calculatePerimeter();

    cout << endl;

    Polygon p("Yellow", 1.0, 6, 4);
    p.draw();
    p.calculateArea();
    p.calculatePerimeter();

    return 0;
}
