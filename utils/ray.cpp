#include "ray.h"

// Add sphere to the project
// ax^2 + bx + c = 0
auto HitSphere(const Point3 &center, double radius, const Ray &r) -> double {
    Vector3 oc = r.Origin() - center;
    double a = r.Direction().LengthSquared();
    // b is positive cause oc.z < 0, r.z > 0
    double half_b = Dot(oc, r.Direction());
    double c = oc.LengthSquared() - (radius * radius);
    double discriminant = (half_b * half_b) - (a * c);
    if (discriminant < 0) {
        return -1.0;
    }
    return (-half_b - sqrt(discriminant)) / a;
}