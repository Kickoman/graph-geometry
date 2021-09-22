#ifndef GRAPHGEOMETRY_3D_SPHERE
#define GRAPHGEOMETRY_3D_SPHERE

#include "3d/point.h"

namespace GraphGeometry {
namespace D3 {

class Sphere
{
public:
    Sphere() = default;
    Sphere(const Point &center, double radius);

    const Point &center() const;
    double radius() const;

private:
    Point _center{};
    double _radius{};
};

} // D3
} // GraphGeometry

#endif // GRAPHGEOMETRY_3D_SPHERE