#include "2d/vector.h"

namespace GraphGeometry {
namespace TwoD {

Vector::Vector() = default;
Vector::Vector(double x, double y) : _x(x), _y(y) {}
Vector::Vector(Point from, Point to)
    : _x(to.x() - from.x()), _y(to.y() - from.y()) {}

double Vector::x() const { return _x; }
double Vector::y() const { return _y; }

Vector &Vector::operator+=(Vector other)
{
    _x += other._x;
    _y += other._y;
    return *this;
}
Vector Vector::operator+(Vector other) const
{
    Vector v;
    v._x = this->_x + other._x;
    v._y = this->_y + other._y;
    return v;
}

double Vector::dotProduct(Vector other) const
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

Vector operator*(Vector v, double number)
{
    return v.multiply(number);
}

Vector operator/(Vector v, double number)
{
    return v.divide(number);
}

}   // TwoD
}   // GraphGeometry
