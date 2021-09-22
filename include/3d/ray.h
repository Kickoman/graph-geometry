#ifndef GRAPHGEOMETRY_3D_RAY
#define GRAPHGEOMETRY_3D_RAY

#include "3d/point.h"
#include "3d/vector.h"

namespace GraphGeometry {
namespace D3 {

class Ray
{
public:
    Ray() = default;
    Ray(const Point &origin, const Vector &direction);

    const Point &origin() const;
    const Vector &direction() const;

private:
    Point _origin{};
    Vector _direction{};
};

} // D3
} // GraphGeometry

#endif // GRAPHGEOMETRY_3D_RAY