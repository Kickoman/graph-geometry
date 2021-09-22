#ifndef GRAPHGEOMETRY_3D_VECTOR
#define GRAPHGEOMETRY_3D_VECTOR

#include "mathematics.h"
#include "3d/point.h"

namespace GraphGeometry {
namespace D3 {

class Vector
{
public:
    Vector() = default;
    Vector(double x, double y, double z);
    Vector(const Point &from, const Point &to);

    double x() const;
    double y() const;
    double z() const;

    double &operator[](size_t index);
    const double &operator[](size_t index) const;

    Vector &operator+=(const Vector &other);
    Vector operator+(const Vector &other) const;

    double dotProduct(const Vector &other) const;
    double magnitude() const;
    Vector normalized() const;

    Vector rotateDeg(double degrees, Axis axis) const;
    Vector rotateRad(double radians, Axis axis) const;
    Vector multiply(double number) const;
    Vector divide(double number) const;

    Vector crossProduct(const Vector &other) const;

private:
    double _x{};
    double _y{};
    double _z{};
};

Vector operator*(const Vector &v, double number);
Vector operator/(const Vector &v, double number);
Point operator+(const Point &point, const Vector &vector);

} // D3
} // GraphGeometry

#endif // GRAPHGEOMETRY_3D_VECTOR
