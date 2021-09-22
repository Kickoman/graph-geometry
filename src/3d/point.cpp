#include "3d/point.h"

namespace GraphGeometry {
namespace D3 {

Point::Point() = default;
Point::Point(double x, double y, double z) : _x(x), _y(y), _z(z) {}

double Point::x() const { return _x; }
double Point::y() const { return _y; }
double Point::z() const { return _z; }

}
}
