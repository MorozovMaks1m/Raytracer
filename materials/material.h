#ifndef MATERIAL_H
#define MATERIAL_H

#include "utils/vector3.h"
#include "utils/ray.h"

struct HitRecord;

class Material {
public:
    virtual auto Scatter(const Ray &ray_in, const HitRecord &record,
                         Color &attenuation, Ray &scattered) const -> bool = 0;
};

#endif // MATERIAL_H