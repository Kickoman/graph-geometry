#include "2d/point.h"

namespace GraphGeometry {
namespace D2 {

Point::Point()
    = default;

Point::Point(double x, double y) : _x(x), _y(y)
{}

double Point::x() const
{
    return _x;
}

double Point::y() const
{
    return _y;
}

}   // D2
}   // GraphGeometry
