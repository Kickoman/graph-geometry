#include "3d/vector.h"
#include "2d/vector.h"  // TODO: remove dependency

#include <cassert>
#include <stdexcept>

namespace GraphGeometry {
namespace D3 {

Vector::Vector(double x, double y, double z) : _x(x), _y(y), _z(z) {}

Vector::Vector(const Point &from, const Point &to)
    : _x(to.x() - from.x())
    , _y(to.y() - from.y())
    , _z(to.z() - from.z())
{}

double Vector::x() const { return _x; }
double Vector::y() const { return _y; }
double Vector::z() const { return _z; }

double &Vector::operator[](size_t index)
{
    switch (index)
    {
    case 0: return _x;
    case 1: return _y;
    case 2: return _z;
    default: throw std::out_of_range("Index of vector is out of range");
    }
}

const double &Vector::operator[](size_t index) const
{
    switch (index)
    {
    case 0: return _x;
    case 1: return _y;
    case 2: return _z;
    default: throw std::out_of_range("Index of vector is out of range");
    }
}

Vector &Vector::operator+=(const Vector &other)
{
    _x += other._x;
    _y += other._y;
    _z += other._z;
    return *this;
}

Vector Vector::operator+(const Vector &other) const
{
    return {
        _x + other._x,
        _y + other._y,
        _z + other._z
    };
}

double Vector::dotProduct(const Vector &other) const
{
    return _x * other._x + _y * other._y + _z * other._z;
}

double Vector::magnitude() const
{
    return sqrt(_x*_x + _y*_y + _z*_z);
}

Vector Vector::normalized() const
{
    return divide(magnitude());
}

Vector Vector::rotateDeg(double degrees, Axis axis) const
{
    return rotateRad(deg_to_rad(degrees), axis);
}

Vector Vector::rotateRad(double radians, Axis axis) const
{
    D2::Vector v;
    switch (axis)
    {
    case Axis::X:
        v = D2::Vector(_y, _z);
        v.rotateRad(radians);
        return Vector(_x, v.x(), v.y());
    case Axis::Y:
        v = D2::Vector(_x, _z);
        v.rotateRad(radians);
        return Vector(v.x(), _y, v.y());
    case Axis::Z:
        v = D2::Vector(_x, _y);
        v.rotateRad(radians);
        return Vector(v.x(), v.y(), _z);
    }
    assert(false);
    return {};// Should never happen
}

Vector Vector::multiply(double number) const
{
    return {
        _x * number,
        _y * number,
        _z * number
    };
}

Vector Vector::divide(double number) const
{
    return {
        _x / number,
        _y / number,
        _z / number
    };
}

Vector Vector::crossProduct(const Vector &other) const
{
    return {
        _y * other._z - _z * other._y,
        _z * other._x - _x * other._z,
        _x * other._y - _y * other._x
    };
}

Vector operator*(const Vector &v, double number)
{
    return v.multiply(number);
}

Vector operator/(const Vector &v, double number)
{
    return v.divide(number);
}

Point operator+(const Point &point, const Vector &vector)
{
    return {
        point.x() + vector.x(),
        point.y() + vector.y(),
        point.z() + vector.z()
    };
}

}
}
