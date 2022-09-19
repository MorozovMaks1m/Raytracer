#ifndef RAY_H
#define RAY_H

#include "vector3.h"

class Ray
{
public:
    Ray() {}
    
    Ray(const Point3 &origin, const Vector3 &direction)
        : origin_(origin), direction_(direction)
    {}

    Point3 origin() const
    {
        return origin_;
    }

    Point3 direction() const
    {
        return direction_;
    }

    Point3 at(double t) const
    {
        return origin_ + t * direction_;
    }

private:
    Point3 origin_;
    Vector3 direction_;
};

double HitSphere(const Point3& center, double radius, const Ray& r);

#endif // RAY_H