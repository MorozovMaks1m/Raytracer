#include "vector3.h"

Vector3 RandomInUnitSphere()
{
    Vector3 p = Vector3::random(-1,1);
    while (p.length_squared() >= 1)
    {
        p = Vector3::random(-1,1);
    }
    return p;
}

Vector3 refract(const Vector3& uv, const Vector3& n, double etai_over_etat)
{
    auto cos_theta = fmin(dot(-uv, n), 1.0);
    Vector3 r_out_perp =  etai_over_etat * (uv + cos_theta*n);
    Vector3 r_out_parallel = -sqrt(fabs(1.0 - r_out_perp.length_squared())) * n;
    return r_out_perp + r_out_parallel;
}

Vector3 RandomInUnitDisk() {
    while (true) {
        auto p = Vector3(RandomDouble(-1,1), RandomDouble(-1,1), 0);
        if (p.length_squared() >= 1)
        {
            continue;
        }
        return p;
    }
}