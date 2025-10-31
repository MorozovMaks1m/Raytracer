#include "vector3.h"

auto RandomInUnitSphere() -> Vector3 {
    Vector3 p = Vector3::Random(-1, 1);
    while (p.LengthSquared() >= 1) {
        p = Vector3::Random(-1, 1);
    }
    return p;
}

auto Refract(const Vector3 &uv, const Vector3 &n, double etai_over_etat)
    -> Vector3 {
    auto cos_theta = fmin(Dot(-uv, n), 1.0);
    Vector3 r_out_perp = etai_over_etat * (uv + cos_theta * n);
    Vector3 r_out_parallel = -sqrt(fabs(1.0 - r_out_perp.LengthSquared())) * n;
    return r_out_perp + r_out_parallel;
}

auto RandomInUnitDisk() -> Vector3 {
    while (true) {
        auto p = Vector3(RandomDouble(-1, 1), RandomDouble(-1, 1), 0);
        if (p.LengthSquared() >= 1) {
            continue;
        }
        return p;
    }
}