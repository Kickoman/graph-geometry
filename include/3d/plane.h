#ifndef GRAPHGEOMETRY_D3_PLANE_H
#define GRAPHGEOMETRY_D3_PLANE_H

#include "3d/point.h"
#include "3d/vector.h"

namespace GraphGeometry {
namespace D3 {

class Plane
{
public:
    Plane() = default;
    Plane(const Point &origin, const Vector &normal);

    const Point &origin() const;
    const Vector &normal() const;

private:
    Point _origin;
    Vector _normal;
};

} // namespace D3
} // namespace GraphGeometry

#endif // GRAPHGEOMETRY_D3_PLANE_H
