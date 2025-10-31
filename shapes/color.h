#ifndef COLOR_H
#define COLOR_H

#include "utils/vector3.h"

class Ray;
class Hittable;

auto RayColor(const Ray &r, const Hittable &world, int depth) -> Color;
void WriteColor(std::ostream &out, Color pixel_color, int samples_per_pixel);

#endif // COLOR_H