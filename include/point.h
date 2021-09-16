#ifndef POINT_H
#define POINT_H

#include "../graphgeometry_global.h"

namespace GraphGeometry {

class GRAPHGEOMETRY_EXPORT Point
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

}
#endif // POINT_H
