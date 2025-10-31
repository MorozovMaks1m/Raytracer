#include "metal.h"

auto Metal::Scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation,
                    Ray &scattered) const -> bool {
    Vector3 reflected = Reflect(UnitVector(r_in.Direction()), rec.normal_);
    scattered = Ray(rec.hitPoint_, reflected + fuzz_ * RandomInUnitSphere());
    attenuation = albedo_;
    return (Dot(scattered.Direction(), rec.normal_) > 0);
}
