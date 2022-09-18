#include "color_utils.h"

// add std::ostream& out
void CreateFileHeader(std::ostream &out)
{
    out << "P3" << std::endl;
    out << image_width << " " << image_height << std::endl;
    out << max_color_format << std::endl;
}

void FillPlainColor(std::ostream &out)
{
    for (int i = image_height - 1; i > 0; --i)
    {
        std::cerr << "\rScanlines remaining: " << i << ' ' << std::flush;
        for (int j = 0; j < image_width; ++j)
        {
            Color pixel_color{double(j)/(image_width-1), double(i)/(image_height-1), 0.25};
            WriteColor(out, pixel_color);
        }
    }
    std::cerr << std::endl << "Done." << std::endl;
}

void WriteColor(std::ostream &out, Color pixel_color)
{
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}