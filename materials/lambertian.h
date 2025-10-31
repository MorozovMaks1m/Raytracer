#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "shapes/hittable.h"
#include "material.h"

class Lambertian : public Material {
public:
    Lambertian(const Color &a) : albedo_(a) {}

    auto Scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation,
                 Ray &scattered) const -> bool override {
        auto scatter_direction = rec.normal_ + RandomUnitVector();

        // Catch degenerate scatter direction
        if (scatter_direction.NearZero()) {
            scatter_direction = rec.normal_;
        }

        scattered = Ray(rec.hitPoint_, scatter_direction);
        attenuation = albedo_;
        return true;
    }

    Color albedo_;
};

#endif // LAMBERTIAN_H