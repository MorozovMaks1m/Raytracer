#include "hittable_list.h"

bool HittableList::hit(const Ray& ray, double t_min, double t_max, hit_record& record) const
{
    hit_record temp_rec;
    bool hit_anything = false;
    double closest_so_far = t_max;

    for (const auto& object : objects) {
        if (object->hit(ray, t_min, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            record = temp_rec;
        }
    }

    return hit_anything;
}