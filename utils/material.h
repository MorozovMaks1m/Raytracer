#ifndef MATERIAL_H
#define MATERIAL_H

#include "constants.h"
#include "ray.h"

struct hit_record;

class Material
{
public:
    virtual bool scatter(const Ray& ray_in, const hit_record& record, Color& attenuation, Ray& scattered) const = 0;
};

#endif // MATERIAL_H