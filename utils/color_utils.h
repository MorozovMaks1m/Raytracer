#ifndef COLOR_UTILS_H
#define COLOR_UTILS_H

#include <iostream>

const int max_color_format = 255;
const double max_color = 255.999;

void CreateFileHeader(std::ostream &out, int image_width, int image_height);

#endif // COLOR_UTILS_H