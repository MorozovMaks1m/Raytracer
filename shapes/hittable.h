#ifndef HITTABLE_H
#define HITTABLE_H

#include "utils/ray.h"
#include "utils/vector3.h"
class Material;

struct HitRecord {
    Point3 hitPoint_;
    Vector3 normal_;
    std::shared_ptr<Material> matPtr_;
    double t_{};
    bool frontFace_{};

    void SetFaceNormal(const Ray &r, const Vector3 &outward_normal) {
        frontFace_ = Dot(r.Direction(), outward_normal) < 0;
        normal_ = frontFace_ ? outward_normal : -outward_normal;
    }
};

class Hittable {
public:
    virtual auto Hit(const Ray &r, double t_min, double t_max,
                     HitRecord &rec) const -> bool = 0;
    virtual ~Hittable() = default;
};

#endif // HITTABLE_H