#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "material.h"
#include "shapes/hittable.h"

class Lambertian : public Material {
public:
    Lambertian(const Color &a) : albedo_(a) {}

    auto Scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation,
                 Ray &scattered) const -> bool override;

    Color albedo_;
};

#endif // LAMBERTIAN_H