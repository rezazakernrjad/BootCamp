#include<iostream>
#include<cmath>
using namespace std;
template<class T>
class Shape {
    public:
        Shape() = default;
        bool operator<(T* shape);
        bool operator>(T* shape);
        bool operator==(T* shape);
};
template<class T>
class Rectangle{//} : public Shape<T>{
private:
    int height_, width_;
public:
  Rectangle(int height, int width): height_{height}, width_{width} {};
  int Perimeter();
  int Area();
  bool operator==(T* shape);
  ~Rectangle() = default;
};
template<class T>
class Triangle{//: public Shape<T>{
    private:
        int side_;
    public:
        Triangle(int side): side_{side} {};
        int Area();
        int Perimeter();
        bool operator==(T* shape);
        ~Triangle()= default;
};
template<class T>
class Circle: public Shape<T>{
        int diameter_;
    public:
        Circle(int diameter): diameter_{diameter}{};
        int Area();
        int Perimeter();
        ~Circle()=default;
};
template<class T>
int Circle<T>::Area(){
    return (this->diameter_/2)* (this->diameter_/2) * 3;}
template<class T>
int Circle<T>::Perimeter(){
    return 3 * diameter_; }
template<class T>
int Rectangle<T>::Area(){
    return height_ * width_;}
template<class T>
int Rectangle<T>::Perimeter(){
     return 2* (height_ + width_);}
template<class T>
int Triangle<T>::Area(){
     return (sqrt(3)/2) * side_;}
template<class T>
int Triangle<T>::Perimeter(){ 
      return side_ *3;
  }