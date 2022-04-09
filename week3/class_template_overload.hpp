#include<iostream>
#include<cmath>
using namespace std;

class Rectangle{// : public Shape {
    int height_, width_;
public:
    Rectangle (int height, int width): height_{height}, width_{width}  {};
  int Perimeter();
  int Area();
  ~Rectangle() = default;
};
class Triangle{//: public Shape{
    private:
        int side_;
    public:
        Triangle (int side) : side_{side} {};
        int Area();
        int Perimeter();
        ~Triangle()= default;
};
class Circle{//: public Shape{
        int diameter_;
    public:
        Circle (int diameter): diameter_{diameter}{};
        int Area();
        int Perimeter();
        ~Circle()=default;
};
template<class T1, class T2>
bool ShapeCompare(T1* t1, T2* t2){
    if (t1->Area() == t2->Area()){
        if (t1->Perimeter() == t2->Perimeter()){
            return true;
        }else { return false;}
    } else { return false;}
}