#ifndef DIELECTRIC_H
#define DIELECTRIC_H

#include "material.h"
#include "shapes/hittable.h"

class Dielectric : public Material {
public:
    Dielectric(double index_of_refraction) : ir_(index_of_refraction) {}

    auto Scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation,
                 Ray &scattered) const -> bool override;

private:
    double ir_; // Index of Refraction
    static auto Reflectance(double cosine, double ref_idx) -> double;
};

#endif // DIELECTRIC_H