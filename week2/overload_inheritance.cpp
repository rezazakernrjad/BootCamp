/*
Implement an interface for shape, and derive circle, triangle, rectangle, square as children. Overload all three
comparison operators to compare the shapes based on their area if equal then their perimeter should be
considered. Only, and if only both area and perimeter are equal then the objects should be considered equal
*/
#include<iostream>
#include<cmath>
using namespace std;
class Shape {
    
    protected:
        int height_, width_;
    public:
        Shape() = default;
        Shape(int height, int width){}
        virtual int Area() = 0;
        virtual int Perimeter() = 0;
        bool operator<(Shape* shape);
        bool operator>(Shape* shape);
        bool operator==(Shape* shape);
};
class Rectangle : public Shape {
public:
  Rectangle(int height, int width) {
      height_ = height;
      width_ = width;
  };
  int Perimeter() override;
  int Area() override;
  ~Rectangle() = default;
};
class Triangle: public Shape{
    private:
        int side_;
    public:
        Triangle(int side): side_{side} {};
        int Area() override;
        int Perimeter() override;
        ~Triangle()= default;
};
class Circle: public Shape{
        int diameter_;
    public:
        Circle(int diameter): diameter_{diameter}{};
        int Area() override;
        int Perimeter()override;
        ~Circle()=default;
};
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

 bool Shape::operator<(Shape* shape){
     return this->Area() < shape->Area();
 }
bool Shape::operator>(Shape* shape){
    return this->Area() > shape->Area();
}
bool Shape::operator==(Shape* shape){
    if (this->Area() == shape->Area()){
        if (this->Perimeter() == shape->Perimeter()){
            return true;
        }
    }
    return false;
}
int main(){
    cout << "Shape...::::" << endl;
    int diam = 3;
    int h{3};
    int w{5};
    Shape* cirk = new Circle(3);
    Shape* rect = new Rectangle(3,5);
    Shape* tri = new Triangle(5);
    if (cirk < rect){
        cout << "cirk < rect" << endl;
    } else {
        cout << "rect < cirk" << endl;
    }
    if (tri == rect){
        cout << "Rectangle is eaual to Triangle" << endl;
    }else{
        cout << "Rectangle is NOT eaual to Triangle" << endl;
    }

    cout << "circle area: " << cirk->Area() << endl;
    cout << "Circle perimeter: " << cirk->Perimeter() << endl;
    cout << "Rectangle area: " << rect->Area() << endl;
    cout << "Rectangle perimeter: " << rect->Perimeter() << endl;
    cout << "Triangle area: " << tri->Area() << endl;
    cout << "Triangle perimeter: " << tri->Perimeter() << endl;
return 0;
}