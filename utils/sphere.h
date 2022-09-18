#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vector3.h"

class Sphere : public Hittable {
public:
    // sphere() {}
    Sphere(Point3 cen, double r) : center_(cen), radius_(r) {}

    bool hit(const Ray& ray, double t_min, double t_max, hit_record& record) const override;

private:
    Point3 center_;
    double radius_;
};

#endif // SPHERE_H