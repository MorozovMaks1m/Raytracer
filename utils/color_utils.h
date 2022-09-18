#ifndef COLOR_UTILS_H
#define COLOR_UTILS_H

#include <iostream>
#include "vector3.h"

constexpr auto aspect_ratio = 16.0 / 9.0;
constexpr int image_width = 800;
constexpr int image_height = static_cast<int>(image_width / aspect_ratio);
const int max_color_format = 255;
const double max_color = 255.999;

const double viewport_height = 2.0;
const double viewport_width = aspect_ratio * viewport_height;
const double focal_length = 1.0;

void CreateFileHeader(std::ostream &out);
void FillPlainColor(std::ostream &out);
void WriteColor(std::ostream &out, Color pixel_color);

#endif // COLOR_UTILS_H