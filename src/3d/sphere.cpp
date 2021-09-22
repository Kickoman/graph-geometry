#include "3d/sphere.h"

namespace GraphGeometry {
namespace D3 {

Sphere::Sphere(const Point &center, double radius)
    : _center(center)
    , _radius(radius)
{}

const Point &Sphere::center() const { return _center; }

double Sphere::radius() const { return _radius; }

}
}