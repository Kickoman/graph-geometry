#ifndef GEOMETRY_POINT_3D_H
#define GEOMETRY_POINT_3D_H

namespace GraphGeometry {
namespace D3 {

class Point
{
public:
    Point();
    Point(double x, double y, double z);

    double x() const;
    double y() const;
    double z() const;

private:
    double _x{};
    double _y{};
    double _z{};
};

}
}

#endif // GEOMETRY_POINT_3D_H
