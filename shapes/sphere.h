#ifndef SPHERE_H
#define SPHERE_H

#include <memory>

#include "hittable.h"
#include "utils/vector3.h"

class Sphere : public Hittable {
public:
    // sphere() {}
    Sphere(Point3 cen, double r, std::shared_ptr<Material> m);

    auto Hit(const Ray &ray, double t_min, double t_max,
             HitRecord &record) const -> bool override;

private:
    Point3 center_;
    double radius_;
    std::shared_ptr<Material> matPtr_;
};

#endif // SPHERE_H