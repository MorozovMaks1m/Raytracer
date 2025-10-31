#include "hittable_list.h"
#include "utils/ray.h"

auto HittableList::Hit(const Ray &ray, double t_min, double t_max,
                       HitRecord &record) const -> bool {
    HitRecord tempRec;
    bool hitAnything = false;
    double closestSoFar = t_max;

    for (const auto &object : objects_) {
        if (object->Hit(ray, t_min, closestSoFar, tempRec)) {
            hitAnything = true;
            closestSoFar = tempRec.t_;
            record = tempRec;
        }
    }

    return hitAnything;
}