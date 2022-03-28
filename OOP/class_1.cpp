#include<iostream>

using namespace std;

class Box {
    public:
    Box(double breath, double height, double lenghth, double val): breath_{breath}, height_{height}, lenght_{lenghth}, val_{val}  {}
    double getVal(){
        return breath_ * height_ * lenght_;
//        cout << "val: " << val_ << endl;
    }

private:
    double breath_;
    double height_;
    double lenght_;
    double val_;
    
};

int main(){
    Box box_1(1.2, 2.3, 3.4, 0);
    Box box_2(3, 4, 5, 0);

    cout << "valume obj_1: "<<  box_1.getVal() << endl;
    cout << "valume obj_2: "<<  box_2.getVal() << endl;
}