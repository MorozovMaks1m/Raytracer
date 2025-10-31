#include "utils/vector3.h"
#include "sphere.h"

Sphere::Sphere(Point3 cen, double r, std::shared_ptr<Material> m)
        : center_(cen), radius_(r), matPtr_(std::move(std::move(m))) {}

auto Sphere::Hit(const Ray &ray, double t_min, double t_max,
                 HitRecord &record) const -> bool {
    Vector3 oc = ray.Origin() - center_;
    double a = ray.Direction().LengthSquared();
    double half_b = Dot(oc, ray.Direction());
    double c = oc.LengthSquared() - (radius_ * radius_);
    double discriminant = (half_b * half_b) - (a * c);
    if (discriminant < 0) {
        return false;
    }

    double sqrtd = sqrt(discriminant);

    // Find the nearest root that lies in the acceptable range.
    double root = (-half_b - sqrtd) / a;
    if (root < t_min || root > t_max) {
        root = (-half_b + sqrtd) / a;
        if (root < t_min || root > t_max) {
            return false;
        }
    }

    record.t_ = root;
    record.hitPoint_ = ray.At(record.t_);
    Vector3 outward_normal = (record.hitPoint_ - center_) / radius_;
    record.SetFaceNormal(ray, outward_normal);
    record.matPtr_ = matPtr_;

    return true;
}