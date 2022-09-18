#include <iostream>
#include <memory>

#include "utils/color_utils.h"
#include "utils/ray.h"
#include "utils/constants.h"
#include "utils/hittable_list.h"
#include "utils/sphere.h"
#include "utils/color.h"
#include "utils/camera.h"

int main()
{
    constexpr double aspect_ratio = 16.0 / 9.0;
    constexpr int image_width = 1920;
    constexpr int image_height = static_cast<int>(image_width / aspect_ratio);
    constexpr int samples_per_pixel = 100;
    CreateFileHeader(std::cout, image_width, image_height);


    Camera cam(aspect_ratio);

    HittableList world;
    world.add(std::make_shared<Sphere>(Point3(0, 0, -1), 0.5));
    world.add(std::make_shared<Sphere>(Point3(0, -100.5, -1), 100));

    for (int i = image_height-1; i >= 0; --i) {
        std::cerr << "\rScanlines remaining: " << i << ' ' << std::flush;
        for (int j = 0; j < image_width; ++j) {
            Color pixel_color(0, 0, 0);
            for (int s = 0; s < samples_per_pixel; ++s)
            {
                double u = (j + RandomDouble()) / (image_width - 1);
                double v = (i + RandomDouble()) / (image_height - 1);
                Ray ray = cam.GetRay(u, v);
                pixel_color += RayColor(ray, world);
            }
            WriteColor(std::cout, pixel_color, samples_per_pixel);
        }
    }
    std::cerr << std::endl << "Done." << std::endl;
    return 0;
}