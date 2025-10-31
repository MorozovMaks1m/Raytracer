#ifndef RAY_H
#define RAY_H

#include "vector3.h"

class Ray {
public:
    Ray() = default;

    Ray(const Point3 &origin, const Vector3 &direction)
        : origin_(origin), direction_(direction) {}

    [[nodiscard]] auto Origin() const -> Point3 { return origin_; }

    [[nodiscard]] auto Direction() const -> Point3 { return direction_; }

    [[nodiscard]] auto At(double t) const -> Point3 {
        return origin_ + t * direction_;
    }

private:
    Point3 origin_;
    Vector3 direction_;
};

auto HitSphere(Point3 &center, double radius, const Ray &r) -> double;

#endif // RAY_H