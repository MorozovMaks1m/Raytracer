#include "lambertian.h"

auto Lambertian::Scatter(const Ray &r_in, const HitRecord &rec,
                         Color &attenuation, Ray &scattered) const -> bool {
    auto scatterDirection = rec.normal_ + RandomUnitVector();

    // Catch degenerate scatter direction
    if (scatterDirection.NearZero()) {
        scatterDirection = rec.normal_;
    }

    scattered = Ray(rec.hitPoint_, scatterDirection);
    attenuation = albedo_;
    return true;
}
