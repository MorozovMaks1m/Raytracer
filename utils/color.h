#ifndef COLOR_H
#define COLOR_H

#include "color_utils.h"
#include "ray.h"
#include "hittable.h"
#include "constants.h"

Color RayColor(const Ray& r, const Hittable& world);

#endif // COLOR_H