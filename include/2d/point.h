#ifndef GEOMETRY_POINT_2D_H
#define GEOMETRY_POINT_2D_H

namespace GraphGeometry {
namespace TwoD {

class Point
{
public:
    Point();
    Point(double x, double y);

    double x() const;

    double y() const;

private:
    double _x{};
    double _y{};
};

}   // TwoD
}   // GraphGeometry
#endif // GEOMETRY_POINT_2D_H
