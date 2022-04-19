#include "comp_shape_cmake.hpp"

template <class T1, class T2>
bool CompShapes::ShapeCompare(T1 *t1, T2 *t2)
{
    if (t1->Area() == t2->Area())
    {
        if (t1->Perimeter() == t2->Perimeter())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}