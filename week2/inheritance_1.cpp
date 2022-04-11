#include<iostream>
using namespace std;

class Polygon {
    protected:
        int width, height;
    public:
        void set_values(int a, int b)
            {width = a; height = b;}
};
class Rectangle: public Polygon{
    public:
    int area()
    {return width * height;}
};
class Triangle: public Polygon{
    public:
    int area(){
        return width * height /2;}
};

int main(){
    Polygon* p;
    Rectangle rect;
    p = &rect;
    p->set_values(10, 10);
    cout << "Rectangle area: " << rect.area() << endl;
    Triangle tri;
    p = &tri;
    p->set_values(10, 10);
    cout << "triangle area: " << tri.area() << endl;
}