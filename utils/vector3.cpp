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
    auto cosTheta = fmin(Dot(-uv, n), 1.0);
    Vector3 rOutPerp = etai_over_etat * (uv + cosTheta * n);
    Vector3 rOutParallel = -sqrt(fabs(1.0 - rOutPerp.LengthSquared())) * n;
    return rOutPerp + rOutParallel;
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