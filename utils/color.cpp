#include "color.h"

Color RayColor(const Ray& ray, const Hittable& world, int depth)
{
    hit_record record;

    // If we've exceeded the ray bounce limit, no more light is gathered.
    if (depth <= 0)
        return Color(0,0,0);

    if (world.hit(ray, 0.001, infinity, record))
    {
        Ray scattered;
        Color attenuation;
        if (record.mat_ptr->scatter(ray, record, attenuation, scattered))
            return attenuation * RayColor(scattered, world, depth - 1);
        return Color(0,0,0);
    }
    Vector3 unit_direction = UnitVector(ray.direction());
    double t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

void WriteColor(std::ostream &out, Color pixel_color, int samples_per_pixel)
{
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Divide the color by the number of samples and gamma-correct for gamma=2.0.
    auto scale = 1.0 / samples_per_pixel;
    r = std::sqrt(scale * r);
    g = std::sqrt(scale * g);
    b = std::sqrt(scale * b);

    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(256 * Clamp(r, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * Clamp(g, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * Clamp(b, 0.0, 0.999)) << '\n';
}