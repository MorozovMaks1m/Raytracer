#include <iostream>
#include <memory>

#include "utils/color_utils.h"
#include "utils/ray.h"
#include "utils/constants.h"
#include "utils/hittable_list.h"
#include "utils/sphere.h"
#include "utils/color.h"
#include "utils/camera.h"
#include "utils/lambertian.h"
#include "utils/metal.h"

int main()
{
    constexpr double aspect_ratio = 16.0 / 9.0;
    constexpr int image_width = 800;
    constexpr int image_height = static_cast<int>(image_width / aspect_ratio);
    constexpr int samples_per_pixel = 100;
    constexpr int max_depth = 50;
    CreateFileHeader(std::cout, image_width, image_height);


    Camera cam(aspect_ratio);

    HittableList world;
    auto material_ground = std::make_shared<lambertian>(Color(0.8, 0.8, 0.0));
    auto material_center = std::make_shared<lambertian>(Color(0.7, 0.3, 0.3));
    auto material_left   = std::make_shared<metal>(Color(0.8, 0.8, 0.8), 0.2);
    auto material_right  = std::make_shared<metal>(Color(0.8, 0.6, 0.2), 0.7);

    world.add(std::make_shared<Sphere>(Point3( 0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(std::make_shared<Sphere>(Point3( 0.0,    0.0, -1.0),   0.5, material_center));
    world.add(std::make_shared<Sphere>(Point3(-1.0,    0.0, -1.0),   0.5, material_left));
    world.add(std::make_shared<Sphere>(Point3( 1.0,    0.0, -1.0),   0.5, material_right));

    for (int i = image_height-1; i >= 0; --i) {
        std::cerr << "\rScanlines remaining: " << i << ' ' << std::flush;
        for (int j = 0; j < image_width; ++j) {
            Color pixel_color(0, 0, 0);
            for (int s = 0; s < samples_per_pixel; ++s)
            {
                double u = (j + RandomDouble()) / (image_width - 1);
                double v = (i + RandomDouble()) / (image_height - 1);
                Ray ray = cam.GetRay(u, v);
                pixel_color += RayColor(ray, world, max_depth);
            }
            WriteColor(std::cout, pixel_color, samples_per_pixel);
        }
    }
    std::cerr << std::endl << "Done." << std::endl;
    return 0;
}