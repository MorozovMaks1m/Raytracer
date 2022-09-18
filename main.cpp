#include <iostream>

#include "utils/color_utils.h"
#include "utils/ray.h"

int main()
{
    CreateFileHeader(std::cout);

    const Point3 origin = Point3(0, 0, 0);
    const Vector3 horizontal = Vector3(viewport_width, 0, 0);
    const Vector3 vertical = Vector3(0, viewport_height, 0);
    const Point3 lower_left_corner = origin - horizontal / 2 - vertical / 2 - Point3(0, 0, focal_length);

    for (int i = image_height-1; i >= 0; --i) {
        std::cerr << "\rScanlines remaining: " << i << ' ' << std::flush;
        for (int j = 0; j < image_width; ++j) {
            auto u = double(j) / (image_width-1);
            auto v = double(i) / (image_height-1);
            Ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
            Color pixel_color = RayColor(r);
            WriteColor(std::cout, pixel_color);
        }
    }
    std::cerr << std::endl << "Done." << std::endl;
    return 0;
}

