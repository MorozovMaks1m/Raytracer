#include "color_utils.h"


// add std::ostream& out
void CreateFileHeader(std::ostream &out, int image_width, int image_height)
{
    out << "P3" << std::endl;
    out << image_width << " " << image_height << std::endl;
    out << max_color_format << std::endl;
}
