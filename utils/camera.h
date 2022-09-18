#ifndef CAMERA_H
#define CAMERA_H

#include "constants.h"
#include "ray.h"

class Camera
{
public:
    Camera(double aspect_ratio)
    {
        double viewport_height = 2.0;
        double viewport_width = aspect_ratio * viewport_height;
        double focal_length = 1.0;

        origin = Point3(0, 0, 0);
        horizontal = Vector3(viewport_width, 0.0, 0.0);
        vertical = Vector3(0.0, viewport_height, 0.0);
        lower_left_corner = origin - horizontal/2 - vertical/2 - Vector3(0, 0, focal_length);
    }

    Ray GetRay(double u, double v) const
    {
        return Ray(origin, lower_left_corner + u * horizontal + v * vertical - origin);
    }

private:
    Point3 origin;
    Point3 lower_left_corner;
    Vector3 horizontal;
    Vector3 vertical;
};

#endif // CAMERA_H