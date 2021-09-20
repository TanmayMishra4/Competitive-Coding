#include <bits/stdc++.h>
using namespace std;

// Base class
class Shape{
    public:
        virtual float getArea() = 0;
        virtual float getPerimeter() = 0;
};
class Rectangle:public Shape{
    float length, breadth;
    public:
        Rectangle(float length, float breadth){
            this->length = length;
            this->breadth = breadth;
        }
        float getArea(){
            return length*breadth;
        }
        float getPerimeter(){
            return (length+breadth)*2;
        }
};
class Circle:public Shape{
    float radius;
    public:
        Circle(float radius){
            this->radius = radius;
        }
        float getArea(){
            return 3.14*radius*radius;
        }
        float getPerimeter(){
            return 2*3.14*radius;
        }
};
class Square:public Rectangle{
    float s;
    public:
        Square(float s):Rectangle(s, s){}
};

int
main (void)
{
    Rectangle rect (4, 5);
    Square squ (6);
    Circle c(7);

    // Print the area of the object.
    cout << "Rectangle area: " << rect.getArea () << endl;
    cout << "Rectangle Perimeter: " << rect.getPerimeter () << endl;
    // Print the area of the object.
    cout << "Square area: " << squ.getArea () << endl;
    cout << "Square Perimeter: " << squ.getPerimeter () << endl;
    // Print area and perimeter of Circle object
    cout << "Circle area: " << c.getArea() << endl;
    cout << "Circle permiter: " << c.getPerimeter() << endl;

    return 0;
}