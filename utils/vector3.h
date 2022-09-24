#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>
#include <iostream>

#include "constants.h"

class Vector3
{
public:
    Vector3() : basis{0,0,0} {}
    Vector3(const double e0, const double e1, const double e2) : basis{e0, e1, e2} {}

    double x() const 
    {
        return basis[0];
    }

    double y() const 
    {
        return basis[1];
    }

    double z() const 
    {
        return basis[2];
    }

    Vector3 operator-() const 
    {
        return Vector3(-basis[0], -basis[1], -basis[2]);
    }

    double operator[](const int i) const
    {
        return basis[i];
    }

    double& operator[](const int i)
    {
        return basis[i];
    }

    Vector3& operator+=(const Vector3 &v)
    {
        basis[0] += v.basis[0];
        basis[1] += v.basis[1];
        basis[2] += v.basis[2];
        return *this;
    }

    Vector3& operator*=(const double t)
    {
        basis[0] *= t;
        basis[1] *= t;
        basis[2] *= t;
        return *this;
    }

    Vector3& operator-=(const Vector3 &v)
    {
        return *this += (-v);
    }

    Vector3& operator/=(const double t)
    {
        return *this *= 1/t;
    }

    double length() const
    {
        return std::sqrt(length_squared());
    }

    double length_squared() const
    {
        return basis[0]*basis[0] + basis[1]*basis[1] + basis[2]*basis[2];
    }

    inline static Vector3 random()
    {
        return Vector3(RandomDouble(0, 1), RandomDouble(0, 1), RandomDouble(0, 1));
    }

    inline static Vector3 random(double min, double max)
    {
        return Vector3(RandomDouble(min,max), RandomDouble(min,max), RandomDouble(min,max));
    }

    bool near_zero() const
    {
        // Return true if the vector is close to zero in all dimensions.
        const auto s = 1e-8;
        return (fabs(basis[0]) < s) && (fabs(basis[1]) < s) && (fabs(basis[2]) < s);
    }

    friend std::ostream& operator<<(std::ostream &out, const Vector3 &v);
    friend Vector3 operator+(const Vector3 &u, const Vector3 &v);
    friend Vector3 operator-(const Vector3 &u, const Vector3 &v);
    friend Vector3 operator*(const Vector3 &u, const Vector3 &v);
    friend Vector3 operator*(double t, const Vector3 &v);
    friend double dot(const Vector3 &u, const Vector3 &v);
    friend Vector3 cross(const Vector3 &u, const Vector3 &v);

private:
    double basis[3];
};

inline std::ostream& operator<<(std::ostream &out, const Vector3 &v)
{
    return out << v.basis[0] << ' ' << v.basis[1] << ' ' << v.basis[2];
}

inline Vector3 operator+(const Vector3 &u, const Vector3 &v)
{
    return Vector3(u.basis[0] + v.basis[0], u.basis[1] + v.basis[1], u.basis[2] + v.basis[2]);
}

inline Vector3 operator-(const Vector3 &u, const Vector3 &v)
{
    return Vector3(u.basis[0] - v.basis[0], u.basis[1] - v.basis[1], u.basis[2] - v.basis[2]);
}

inline Vector3 operator*(const Vector3 &u, const Vector3 &v)
{
    return Vector3(u.basis[0] * v.basis[0], u.basis[1] * v.basis[1], u.basis[2] * v.basis[2]);
}

inline Vector3 operator*(double t, const Vector3 &v)
{
    return Vector3(t * v.basis[0], t * v.basis[1], t * v.basis[2]);
}

inline Vector3 operator*(const Vector3 &v, double t)
{
    return t * v;
}

inline Vector3 operator/(Vector3 v, double t)
{
    return (1 / t) * v;
}

inline double dot(const Vector3 &u, const Vector3 &v)
{
    return u.basis[0] * v.basis[0] + u.basis[1] * v.basis[1] + u.basis[2] * v.basis[2];
}

inline Vector3 cross(const Vector3 &u, const Vector3 &v)
{
    return Vector3(u.basis[1] * v.basis[2] - u.basis[2] * v.basis[1],
                   u.basis[2] * v.basis[0] - u.basis[0] * v.basis[2],
                   u.basis[0] * v.basis[1] - u.basis[1] * v.basis[0]);
}

inline Vector3 UnitVector(Vector3 v)
{
    return v / v.length();
}

Vector3 RandomInUnitSphere();

inline Vector3 RandomUnitVector()
{
    return UnitVector(RandomInUnitSphere());
}

inline Vector3 reflect(const Vector3& v, const Vector3& n)
{
    return v - 2*dot(v,n)*n;
}

Vector3 refract(const Vector3& uv, const Vector3& n, double etai_over_etat);

Vector3 RandomInUnitDisk();

// Type aliases for Vector3
using Point3 = Vector3;   // 3D point
using Color = Vector3;    // RGB color

#endif // VECTOR3_H