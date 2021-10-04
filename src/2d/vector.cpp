#include "2d/vector.h"
#include "mathematics.h"

namespace GraphGeometry {
namespace D2 {

Vector::Vector() = default;
Vector::Vector(double x, double y) : _x(x), _y(y) {}
Vector::Vector(const Point &from, const Point &to)
    : _x(to.x() - from.x()), _y(to.y() - from.y()) {}

double Vector::x() const { return _x; }
double Vector::y() const { return _y; }

Vector &Vector::operator+=(const Vector &other)
{
    _x += other._x;
    _y += other._y;
    return *this;
}
Vector Vector::operator+(const Vector &other) const
{
    Vector v;
    v._x = this->_x + other._x;
    v._y = this->_y + other._y;
    return v;
}

double Vector::dotProduct(const Vector &other) const
{
    return this->_x * other._x + this->_y * other._y;
}

double Vector::magnitude() const
{
    return sqrt(_x * _x + _y * _y);
}

Vector Vector::rotateDeg(double degrees) const
{
    double radians = deg_to_rad(degrees);
    return this->rotateRad(radians);
}
Vector Vector::rotateRad(double radians) const
{
    double x2 = cos(radians) * _x - sin(radians) * _y;
    double y2 = sin(radians) * _x + cos(radians) * _y;
    return {x2, y2};
}

Vector Vector::multiply(double number) const
{
    double x2 = _x * number;
    double y2 = _y * number;
    return {x2, y2};
}

Vector Vector::divide(double number) const
{
    double x2 = _x / number;
    double y2 = _y / number;
    return {x2, y2};
}

double Vector::angleToRadians(const Vector &other) const
{
    const double dot = dotProduct(other);
    const double det = _x * other._y - _y * other._x;
    return atan2(det, dot);
}

double Vector::angleToDegrees(const Vector &other) const
{
    return rad_to_deg(angleToRadians(other));
}

Vector operator*(const Vector &v, double number)
{
    return v.multiply(number);
}

Vector operator/(const Vector &v, double number)
{
    return v.divide(number);
}

}   // D2
}   // GraphGeometry
