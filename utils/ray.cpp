#include "ray.h"
#include "constants.h"

// Add sphere to the project
// ax^2 + bx + c = 0
double HitSphere(const Point3& center, double radius, const Ray& r)
{
    Vector3 oc = r.origin() - center;
    double a = r.direction().length_squared();
    // b is positive cause oc.z < 0, r.z > 0
    double half_b = dot(oc, r.direction());
    double c = oc.length_squared() - radius * radius;
    double discriminant = half_b * half_b - a * c;
    if (discriminant < 0)
    {
        return -1.0;
    }
    return (-half_b - sqrt(discriminant)) / a;
}