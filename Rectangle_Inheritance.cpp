#include <bits/stdc++.h>
using namespace std;

class Rectangle{
    private:
    int length, width;
    public:
    Rectangle(int a, int b){
        length = a;
        width = b;
    }
    int getArea(){
        return width*length;
    }
};

class Square:public Rectangle{
    public:
    Square(int s):Rectangle(s, s){}

};

int main(){
    int l = 4, b = 5;
    Rectangle rt (l, b);
    int s = 10;
    Square sq (s);
    cout << "Area of rectangle is : " << rt.getArea() << endl;
    cout << "Area of Square is : " << sq.getArea() << endl;
}