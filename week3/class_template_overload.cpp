/*
Write a function template which receives two of any shapes from last week’s assignment, compares them, and
prints out the result.
*/

#include "class_template_overload.hpp"

int Circle::Area(){
    return (this->diameter_/2)* (this->diameter_/2) * 3;}
int Circle::Perimeter(){
    return 3 * diameter_; }
int Rectangle::Area(){
    return height_ * width_;}
int Rectangle::Perimeter(){
     return 2* (height_ + width_);}
int Triangle::Area(){
     return (sqrt(3)/2) * side_;}
int Triangle::Perimeter(){ 
      return side_ *3;
  }

int main(){
    cout << "Shape...::::" << endl;

    Circle* cirk = new Circle(3);
    Rectangle* rect = new Rectangle(3,5);
    Triangle* tri = new Triangle(5);
    bool shape_comp = ShapeCompare<Circle, Triangle>(cirk, tri);
    if (shape_comp){
        cout << "Circle and Triangle are equals" << endl;    
    } else {cout << "Circle and Triangle are NOT equals" << endl;}

    shape_comp = ShapeCompare<Triangle, Rectangle>(tri, rect);
    if (shape_comp){
        cout << "Triangle and Rectangle are equals" << endl;    
    } else {cout << "Triangle and Rectangle are NOT equals" << endl;}
    return 0;
}