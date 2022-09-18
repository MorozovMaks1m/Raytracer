#include "ray.h"

Color RayColor(const Ray& r)
{
    double t = HitSphere(Point3(0,0,-1), 0.5, r);

    if (t > 0.0) {
        // Intersection point - centre point
        Vector3 N = UnitVector(r.at(t) - Point3(0,0,-1));
        return 0.5 * Color(N.x() + 1, N.y() + 1, N.z() + 1);
    }

    Vector3 unit_direction = UnitVector(r.direction());
    t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

// Add sphere to the project
// ax^2 + bx + c = 0
double HitSphere(const Point3& center, double radius, const Ray& r)
{
    Vector3 oc = r.origin() - center;
    double a = dot(r.direction(), r.direction());
    // b is positive cause oc.z < 0, r.z > 0
    double b = 2.0 * dot(oc, r.direction());
    double c = dot(oc, oc) - radius * radius;
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
    {
        return -1.0;
    }
    return (-b - sqrt(discriminant)) / (2.0*a);
}