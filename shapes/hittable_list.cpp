#include "utils/ray.h"
#include "hittable_list.h"


auto HittableList::Hit(const Ray &ray, double t_min, double t_max,
                       HitRecord &record) const -> bool {
    HitRecord temp_rec;
    bool hit_anything = false;
    double closest_so_far = t_max;

    for (const auto &object : objects_) {
        if (object->Hit(ray, t_min, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t_;
            record = temp_rec;
        }
    }

    return hit_anything;
}