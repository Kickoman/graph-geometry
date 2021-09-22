#include "3d/ray.h"

namespace GraphGeometry {
namespace D3 {

Ray::Ray(const Point &origin, const Vector &direction)
    : _origin(origin)
    , _direction(direction / direction.magnitude())
{}

const Point &Ray::origin() const { return _origin; }

const Vector &Ray::direction() const { return _direction; }

}
}