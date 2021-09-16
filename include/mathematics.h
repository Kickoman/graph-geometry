#ifndef MATHEMATICS_H
#define MATHEMATICS_H

#include <cmath>
#include <cstdlib>

namespace GraphGeometry {

constexpr double PI = 3.14159265358979323846;
constexpr long double PIl = 3.141592653589793238462643383279502884L;

inline bool fuzzyCompare(double a, double b)
{
    return std::abs(a - b) < 1e-6;
}

///
/// \brief Converts radians to degrees
/// \param rad angle in radians
/// \return the same angle in degrees
///
inline double rad_to_deg(double rad) { return (rad * 180) / GraphGeometry::PI; }
///
/// \brief Converts degrees to radians
/// \param deg angle in degrees
/// \return the same angle in radians
///
inline double deg_to_rad(double deg) { return (deg * GraphGeometry::PIl) / 180; }

}

#endif // MATHEMATICS_H
