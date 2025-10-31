#ifndef DIELECTRIC_H
#define DIELECTRIC_H

#include "shapes/hittable.h"
#include "material.h"

class Dielectric : public Material {
public:
    Dielectric(double index_of_refraction) : ir_(index_of_refraction) {}

    auto Scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation,
                 Ray &scattered) const -> bool override {
        attenuation = Color(1.0, 1.0, 1.0);
        double refraction_ratio = rec.frontFace_ ? (1.0 / ir_) : ir_;

        Vector3 unit_direction = UnitVector(r_in.Direction());
        double cos_theta = fmin(Dot(-unit_direction, rec.normal_), 1.0);
        double sin_theta = sqrt(1.0 - (cos_theta * cos_theta));

        bool cannot_refract = refraction_ratio * sin_theta > 1.0;
        Vector3 direction;

        if (cannot_refract ||
            Reflectance(cos_theta, refraction_ratio) > RandomDouble(0, 1)) {
            direction = Reflect(unit_direction, rec.normal_);
        } else {
            direction = Refract(unit_direction, rec.normal_, refraction_ratio);
        }

        scattered = Ray(rec.hitPoint_, direction);
        return true;
    }

private:
    double ir_; // Index of Refraction
    static auto Reflectance(double cosine, double ref_idx) -> double {
        // Use Schlick's approximation for reflectance.
        double r0 = (1 - ref_idx) / (1 + ref_idx);
        r0 = r0 * r0;
        return r0 + ((1 - r0) * pow((1 - cosine), 5));
    }
};

#endif // DIELECTRIC_H