#ifndef METAL_H
#define METAL_H

#include "material.h"
#include "shapes/hittable.h"

class Metal : public Material {
public:
    Metal(const Color &a, double f) : albedo_(a), fuzz_(f < 1 ? f : 1) {}

    auto Scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation,
                 Ray &scattered) const -> bool override;

    Color albedo_;
    double fuzz_;
};

#endif // METAL_H