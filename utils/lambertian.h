#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "material.h"
#include "hittable.h"

class lambertian : public Material
{
public:
    lambertian(const Color& a) : albedo(a) {}

    virtual bool scatter(const Ray& r_in, const hit_record& rec, Color& attenuation, Ray& scattered) const override 
    {
        auto scatter_direction = rec.normal + RandomUnitVector();

        // Catch degenerate scatter direction
        if (scatter_direction.near_zero())
        {
            scatter_direction = rec.normal;
        }

        scattered = Ray(rec.hit_point, scatter_direction);
        attenuation = albedo;
        return true;
    }

public:
    Color albedo;
};

#endif // LAMBERTIAN_H