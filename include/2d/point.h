#ifndef GEOMETRY_POINT_2D_H
#define GEOMETRY_POINT_2D_H

namespace GraphGeometry {
namespace D2 {

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

}   // D2
}   // GraphGeometry
#endif // GEOMETRY_POINT_2D_H
