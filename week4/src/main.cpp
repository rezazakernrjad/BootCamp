/*
Write a function template which receives two of any shapes from last week’s assignment, compares them, and
prints out the result.
*/

#include "comp_shape_cmake.hpp"

// template <class T1, class T2>
// bool CompShapes::ShapeCompare(T1 *t1, T2 *t2)
// {
//     if (t1->Area() == t2->Area())
//     {
//         if (t1->Perimeter() == t2->Perimeter())
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
//     else
//     {
//         return false;
//     }
// } 

int main()
{
    cout << "Shape...::::" << endl;

    CompShapes::Circle *cirk = new CompShapes::Circle(3);
    CompShapes::Rectangle *rect = new CompShapes::Rectangle(3, 5);
    CompShapes::Triangle *tri = new CompShapes::Triangle(5);
    bool shape_comp = CompShapes::ShapeCompare<CompShapes::Circle, CompShapes::Triangle>(cirk, tri);
    if (shape_comp)
    {
        cout << "Circle and Triangle are equals" << endl;
    }
    else
    {
        cout << "Circle and Triangle are NOT equals" << endl;
    }

    shape_comp = CompShapes::ShapeCompare<CompShapes::Triangle, CompShapes::Rectangle>(tri, rect);
    if (shape_comp)
    {
        cout << "Triangle and Rectangle are equals" << endl;
    }
    else
    {
        cout << "Triangle and Rectangle are NOT equals" << endl;
    }
    return 0;
}
