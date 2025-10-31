#include "color_utils.h"

// add std::ostream& out
void CreateFileHeader(std::ostream &out, int image_width, int image_height) {
    out << "P3" << '\n';
    out << image_width << " " << image_height << '\n';
    out << max_color_format << '\n';
}
