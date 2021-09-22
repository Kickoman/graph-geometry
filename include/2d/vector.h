#ifndef GEOMETRY_VECTOR_2D_H
#define GEOMETRY_VECTOR_2D_H

#include "2d/point.h"

namespace GraphGeometry {
namespace D2 {

class Vector
{
public:
    ///
    /// \brief Constructs zero-length vector
    ///
    Vector();
    ///
    /// \brief Constructs a vector by point
    /// \param x X coordinate
    /// \param y Y coordinate
    ///
    Vector(double x, double y);
    ///
    /// \brief Constructs a vector by two points.
    /// \param from Start point
    /// \param to Finish point
    ///
    Vector(const Point &from, const Point &to);
    ///
    /// \brief Getter for vector's X coordinate
    /// \return x coordinate
    ///
    double x() const;
    ///
    /// \brief Getter for vector's Y coordinate
    /// \return y coordinate
    ///
    double y() const;
    ///
    /// \brief Overloaded operator for vectors addition
    /// \param other Another vector to be added to the current vector
    /// \return The sum of the current vector and the \a other vector
    ///
    Vector &operator+=(const Vector &other);
    ///
    /// \brief Overloaded operator for vectors addition
    /// \param other Another vector to be added to the current vector
    /// \return The sum of the current vector and the \a other vector
    ///
    Vector operator+(const Vector &other) const;
    ///
    /// \brief Returns "dot product" of two vectors
    /// \param other Another vector to be used in the dot product calculation
    /// \return The value of the dot product
    ///
    double dotProduct(const Vector &other) const;
    ///
    /// \brief Getter for the vector magnitude (length)
    /// \return Magnitude of vector
    ///
    double magnitude() const;
    ///
    /// \brief Rotates the vector by the given angle in degrees
    /// \param degrees The angle for rotation
    /// \return New vector which is rotated by the given angle
    ///
    Vector rotateDeg(double degrees) const;
    ///
    /// \brief Rotates the vector by the given angle in radians
    /// \param radians The angle for rotation
    /// \return New vector which is rotated by the given angle
    ///
    Vector rotateRad(double radians) const;
    ///
    /// \brief Multiplies the vector by the number
    /// \param number A number for vector to be multiplied by
    /// \return New vector of the magnitude \a number size bigger than the previous one
    ///
    Vector multiply(double number) const;
    ///
    /// \brief Divides the vector by the number
    /// \param number A number for vector to be divided by
    /// \return New vector of the magnitude \a number size smaller than the previous one
    ///
    Vector divide(double number) const;
private:
    double _x = 0;
    double _y = 0;
};

Vector operator*(const Vector &v, double number);
Vector operator/(const Vector &v, double number);

}   // D2
}   // GraphGeometry
#endif // GEOMETRY_VECTOR_2D_H
