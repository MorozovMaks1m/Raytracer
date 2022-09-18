#include <iostream>
#include <memory>

#include "utils/color_utils.h"
#include "utils/ray.h"
#include "utils/constants.h"
#include "utils/hittable_list.h"
#include "utils/sphere.h"
#include "utils/color.h"

int main()
{
    CreateFileHeader(std::cout);

    const Point3 origin = Point3(0, 0, 0);
    const Vector3 horizontal = Vector3(viewport_width, 0, 0);
    const Vector3 vertical = Vector3(0, viewport_height, 0);
    const Point3 lower_left_corner = origin - horizontal / 2 - vertical / 2 - Point3(0, 0, focal_length);

    HittableList world;
    world.add(std::make_shared<Sphere>(Point3(0, 0, -1), 0.5));
    world.add(std::make_shared<Sphere>(Point3(0, -100.5, -1), 100));

    for (int i = image_height-1; i >= 0; --i) {
        std::cerr << "\rScanlines remaining: " << i << ' ' << std::flush;
        for (int j = 0; j < image_width; ++j) {
            auto u = double(j) / (image_width-1);
            auto v = double(i) / (image_height-1);
            Ray ray(origin, lower_left_corner + u * horizontal + v * vertical - origin);
            Color pixel_color = RayColor(ray, world);
            WriteColor(std::cout, pixel_color);
        }
    }
    std::cerr << std::endl << "Done." << std::endl;
    return 0;
}