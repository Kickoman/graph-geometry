#include "3d/plane.h"

namespace GraphGeometry {
namespace D3 {

Plane::Plane(const Point &origin, const Vector &normal)
    : _origin(origin)
    , _normal(normal.normalized())
{}

const Point &Plane::origin() const
{
    return _origin;
}

const Vector &Plane::normal() const
{
    return _normal;
}

} // namespace D3
} // namespace GraphGeometry
