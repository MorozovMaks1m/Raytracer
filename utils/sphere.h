#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vector3.h"

class Sphere : public Hittable {
public:
    // sphere() {}
    Sphere(Point3 cen, double r, std::shared_ptr<Material> m)
        : center_(cen), radius_(r), mat_ptr(m) {}

    bool hit(const Ray& ray, double t_min, double t_max, hit_record& record) const override;

private:
    Point3 center_;
    double radius_;
    std::shared_ptr<Material> mat_ptr;
};

#endif // SPHERE_H