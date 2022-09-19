#include "sphere.h"

bool Sphere::hit(const Ray& ray, double t_min, double t_max, hit_record& record) const
{
    Vector3 oc = ray.origin() - center_;
    double a = ray.direction().length_squared();
    double half_b = dot(oc, ray.direction());
    double c = oc.length_squared() - radius_ * radius_;
    double discriminant = half_b * half_b - a * c;
    if (discriminant < 0)
    {
        return false;
    }

    double sqrtd = sqrt(discriminant);

    // Find the nearest root that lies in the acceptable range.
    double root = (-half_b - sqrtd) / a;
    if (root < t_min || root > t_max) {
        root = (-half_b + sqrtd) / a;
        if (root < t_min || root > t_max)
        {
            return false;
        }
    }

    record.t = root;
    record.hit_point = ray.at(record.t);
    Vector3 outward_normal = (record.hit_point - center_) / radius_;
    record.set_face_normal(ray, outward_normal);
    record.mat_ptr = mat_ptr;

    return true;
}