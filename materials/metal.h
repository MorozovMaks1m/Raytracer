#ifndef METAL_H
#define METAL_H

#include "shapes/hittable.h"
#include "material.h"

class Metal : public Material {
public:
    Metal(const Color &a, double f) : albedo_(a), fuzz_(f < 1 ? f : 1) {}

    auto Scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation,
                 Ray &scattered) const -> bool override {
        Vector3 reflected = Reflect(UnitVector(r_in.Direction()), rec.normal_);
        scattered =
            Ray(rec.hitPoint_, reflected + fuzz_ * RandomInUnitSphere());
        attenuation = albedo_;
        return (Dot(scattered.Direction(), rec.normal_) > 0);
    }

    Color albedo_;
    double fuzz_;
};

#endif // METAL_H