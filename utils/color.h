#ifndef COLOR_H
#define COLOR_H

#include "color_utils.h"
#include "ray.h"
#include "hittable.h"
#include "constants.h"

Color RayColor(const Ray& r, const Hittable& world);
void WriteColor(std::ostream &out, Color pixel_color, int samples_per_pixel);

#endif // COLOR_H