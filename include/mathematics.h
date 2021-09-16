#ifndef MATHEMATICS_H
#define MATHEMATICS_H

#include <cmath>
#include <cstdlib>

inline bool fuzzyCompare(double a, double b)
{
    return std::abs(a - b) < 1e-6;
}

#endif // MATHEMATICS_H
