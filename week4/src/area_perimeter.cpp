#include "comp_shape_cmake.hpp"

int CompShapes::Circle::Area()
{
    return (this->diameter_ / 2) * (this->diameter_ / 2) * 3;
}
int CompShapes::Circle::Perimeter()
{
    return 3 * diameter_;
}
int CompShapes::Rectangle::Area()
{
    return height_ * width_;
}
int CompShapes::Rectangle::Perimeter()
{
    return 2 * (height_ + width_);
}
int CompShapes::Triangle::Area()
{
    return (sqrt(3) / 2) * side_;
}
int CompShapes::Triangle::Perimeter()
{
    return side_ * 3;}
