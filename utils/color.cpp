#include "color.h"

Color RayColor(const Ray& ray, const Hittable& world)
{
    hit_record record;
    if (world.hit(ray, 0, infinity, record)) {
        return 0.5 * (record.normal + Color(1,1,1));
    }
    Vector3 unit_direction = UnitVector(ray.direction());
    double t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}