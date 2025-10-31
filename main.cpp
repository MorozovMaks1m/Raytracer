#include <iostream>

#include "shapes/color.h"
#include "shapes/hittable_list.h"
#include "utils/camera.h"
#include "utils/color_utils.h"
#include "utils/constants.h"
#include "utils/ray.h"

#include "scene1.h"

auto main() -> int {
    constexpr double aspectRatio = 3.0 / 2.0;
    constexpr int imageWidth = 800;
    constexpr int imageHeight = static_cast<int>(imageWidth / aspectRatio);
    constexpr int samplesPerPixel = 100;
    constexpr int maxDepth = 10;
    CreateFileHeader(std::cout, imageWidth, imageHeight);

    HittableList world = RandomScene();

    Point3 lookfrom(13, 2, 2);
    Point3 lookat(0, 0, 0);
    Vector3 viewUp(0, 1, 0);
    double distToFocus = 10.0;
    double aperture = 0.1;

    Camera cam(lookfrom, lookat, viewUp, 40, aspectRatio, aperture,
               distToFocus);

    for (int i = imageHeight - 1; i >= 0; --i) {
        std::cerr << "\rScanlines remaining: " << i << ' ' << std::flush;
        for (int j = 0; j < imageWidth; ++j) {
            Color pixelColor(0, 0, 0);
            for (int s = 0; s < samplesPerPixel; ++s) {
                double u = (j + RandomDouble()) / (imageWidth - 1);
                double v = (i + RandomDouble()) / (imageHeight - 1);
                Ray ray = cam.GetRay(u, v);
                pixelColor += RayColor(ray, world, maxDepth);
            }
            WriteColor(std::cout, pixelColor, samplesPerPixel);
        }
    }
    std::cerr << '\n' << "Done." << '\n';
    return 0;
}