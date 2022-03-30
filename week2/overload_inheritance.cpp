/*
Implement an interface for shape, and derive circle, triangle, rectangle, square as children. Overload all three
comparison operators to compare the shapes based on their area if equal then their perimeter should be
considered. Only, and if only both area and perimeter are equal then the objects should be considered equal
*/

class Shape {
    Shape(int a, int b, int r): a_{a}, b_{b}, r_{r} {}
    protected:
        int a_;
        int b_;
        int r_;
    public:
        virtual void Area() = 0;
        virtual void Perimeter() = 0;
};

class Circle: public Shape {
    float circle_area;
    float circle_perimeter;
    public:
    void Area(){
        circle_area = r_ * r_ * 3;
    }
    void Perimeter(){
        circle_perimeter = 2 * r_ * 3;
    }
    float getCircleArea(){
        return circle_area;
    }
    float getCirclePerimeter(){
        return circle_perimeter;
    }
};
class Trianglr: public Shape {
    float triangle_area;
    float triangle_perimeter;
    public:
    void Area(){
        triangle_area = a_ * b_;
    }
    void Perimeter(){
        triangle_perimeter = 2 * (a_ * b_);
    }
    float getCircleArea(){
        return triangle_area;
    }
    float getCirclePerimeter(){
        return triangle_perimeter;
    }
};

class Rectangle: public Shape {
    float rectangle_area;
    float rectangle_perimeter;
    public:
    void Area(){
        rectangle_area = a_ * b_;
    }
    void Perimeter(){
        rectangle_perimeter = 2 * (a_ + b_);
    }
    float getCircleArea(){
        return rectangle_area;
    }
    float getCirclePerimeter(){
        return rectangle_perimeter;
    }
};
class Square: public Shape {
    float square_area;
    float square_perimeter;
    public:
    void Area(){
        square_area = a_ * a_;
    }
    void Perimeter(){
        square_perimeter = 4 * a_;
    }
    float getCircleArea(){
        return square_area;
    }
    float getCirclePerimeter(){
        return square_perimeter;
    }
};

int main(){
    Shape* square();
    square = new Square;


    return 0;
}