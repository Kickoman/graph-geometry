#include "2d/line.h"
#include "2d/vector.h"

#include "mathematics.h"

namespace GraphGeometry {
namespace D2 {

Line::Line() = default;
Line::Line(double a, double b, double c)
    : _a(a), _b(b), _c(c) {}
Line::Line(double k, double b)
{
    _a = k;
    _b = -1;
    _c = b;
    if (_a < 0)
    {
        _a *= -1;
        _b *= -1;
        _c *= -1;
    }
}
Line::Line(const Point &a, const Point &b)
{
    _a = b.y() - a.y();
    _b = a.x() - b.x();
    _c = b.x()*a.y()-a.x()*b.y();

    if (!fuzzyCompare(_b, 0))
    {
        _a /= abs(_b);
        _c /= abs(_b);
        _b /= abs(_b);
    }
}

Line::Line(const Point &a, const Vector &directionVector)
{
    _a = directionVector.y();
    _b = -directionVector.x();
    _c = directionVector.x() * a.y() - a.x() * directionVector.y();
    if (!fuzzyCompare(_b, 0))
    {
        _a /= abs(_b);
        _c /= abs(_b);
        _b /= abs(_b);
    }
}

double Line::A() const { return _a; }
double Line::B() const { return _b; }
double Line::C() const { return _c; }

double Line::k() const { return _b < 0 ? _a : -_a; }
double Line::b() const { return _b < 0 ? _c : -_c; }

bool Line::has(const Point &p) const { return fuzzyCompare(_a * p.x() + _b * p.y() + _c, 0); }

Point Line::intersection(const Line &other, bool *ok) const
{
    double x = 0;
    double y = 0;
    double det = this->A() * other.B() - other.A() * this->B();
    if (ok != nullptr) *ok = (!fuzzyCompare(_b, 0));
    if (!fuzzyCompare(_b, 0))
    {
        x = - (other.B()*this->C() - this->B()*other.C()) / det;
        y = - (this->A()*other.C() - other.A()*this->C()) / det;
    }
    return {x, y};
}

}   // D2
}   // GraphGeometry
