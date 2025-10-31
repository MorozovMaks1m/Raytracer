#include "dielectric.h"

auto Dielectric::Scatter(const Ray &r_in, const HitRecord &rec,
                         Color &attenuation, Ray &scattered) const -> bool {
    attenuation = Color(1.0, 1.0, 1.0);
    double refractionRatio = rec.frontFace_ ? (1.0 / ir_) : ir_;

    Vector3 unitDirection = UnitVector(r_in.Direction());
    double cosTheta = fmin(Dot(-unitDirection, rec.normal_), 1.0);
    double sinTheta = sqrt(1.0 - (cosTheta * cosTheta));

    bool cannotRefract = refractionRatio * sinTheta > 1.0;
    Vector3 direction;

    if (cannotRefract ||
        Reflectance(cosTheta, refractionRatio) > RandomDouble(0, 1)) {
        direction = Reflect(unitDirection, rec.normal_);
    } else {
        direction = Refract(unitDirection, rec.normal_, refractionRatio);
    }

    scattered = Ray(rec.hitPoint_, direction);
    return true;
}
auto Dielectric::Reflectance(double cosine, double ref_idx) -> double {
    // Use Schlick's approximation for reflectance.
    double r0 = (1 - ref_idx) / (1 + ref_idx);
    r0 = r0 * r0;
    return r0 + ((1 - r0) * pow((1 - cosine), 5));
}
