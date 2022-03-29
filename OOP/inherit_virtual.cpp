/*
In this challenge, you are required to compute the area of a rectangle using classes.

Create two classes:

Rectangle
The Rectangle class should have two data fields-width and height of int types. 
The class should have display() method, to print the width and height of the rectangle separated by space.

RectangleArea
The RectangleArea class is derived from Rectangle class, i.e., it is the sub-class of Rectangle class. 
The class should have read_input() method, to read the values of width and height of the rectangle. 
The RectangleArea class should also overload the display() method to print the area of the rectangle.

Input Format
The first and only line of input contains two space separated integers denoting the width and height of the rectangle.

Constraints

Output Format
The output should consist of exactly two lines:
In the first line, print the width and height of the rectangle separated by space.
In the second line, print the area of the rectangle.
*/
#include <iostream>
using namespace std;

class Rectangle{
    protected:
        int width;
        int height;
        friend class RectangleArea; 
        // since ReactangleArea is friend of Rectangle, object from Rectangle has access to members of object from RectangleArea
    public:
        void display();
};

class RectangleArea: public Rectangle {
    public:
        void read_input();
        void display();
};

Rectangle r;
RectangleArea ra;

void RectangleArea::read_input(){
    cout << "Enter Width: ";
    cin >> r.width;
    cout << "Enter height: ";
    cin >> r.height;
}
void Rectangle::display(){
    if (1 <= r.height && r.height <=100 && 1 <= r.width && r.width <=100 ){
        cout << "width is: " << r.width << "  " "Height: " << r.height << endl;
    } else {
        cout << "Width or Height are out of range" << endl;
    }
}
void RectangleArea::display(){
    if (1 <= r.height && r.height <=100 && 1 <= r.width && r.width <=100 ){
        cout << "Area: " << r.height * r.width << endl;
    } else {
        cout << "Width or Height are out of range" << endl;
    }
}
int main(){
    ra.read_input();
    r.display();
    ra.display();
    return 0;
}