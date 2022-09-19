#ifndef METAL_H
#define METAL_H

#include "material.h"
#include "hittable.h"

class metal : public Material
{
public:
    metal(const Color& a, double f) : albedo(a), fuzz(f < 1 ? f : 1) {}

    virtual bool scatter(const Ray& r_in, const hit_record& rec, Color& attenuation, Ray& scattered) const override
    {
        Vector3 reflected = reflect(UnitVector(r_in.direction()), rec.normal);
        scattered = Ray(rec.hit_point, reflected + fuzz * RandomInUnitSphere());
        attenuation = albedo;
        return (dot(scattered.direction(), rec.normal) > 0);
    }

public:
    Color albedo;
    double fuzz;
};

#endif // METAL_H