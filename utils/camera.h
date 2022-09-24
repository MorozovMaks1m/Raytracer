#ifndef CAMERA_H
#define CAMERA_H

#include "constants.h"
#include "ray.h"

class Camera
{
public:
    Camera(Point3 lookfrom,
           Point3 lookat,
           Vector3 view_up,
           double vfov, // vertical field-of-view in degrees
           double aspect_ratio,
           double aperture,
           double focus_dist)
    {
        double theta = degrees_to_radians(vfov);
        double h = tan(theta / 2);
        double viewport_height = 2.0 * h;
        double viewport_width = aspect_ratio * viewport_height;

        w = UnitVector(lookfrom - lookat);
        u = UnitVector(cross(view_up, w));
        v = cross(w, u);

        origin = lookfrom;
        horizontal = focus_dist * viewport_width * u;
        vertical = focus_dist * viewport_height * v;
        lower_left_corner = origin - horizontal / 2 - vertical / 2 - focus_dist * w;

        lens_radius = aperture / 2;
    }

    Ray GetRay(double s, double t) const
    {
        Vector3 rd = lens_radius * RandomInUnitDisk();
        Vector3 offset = u * rd.x() + v * rd.y();


        return Ray(origin + offset, lower_left_corner + s * horizontal + t * vertical - origin - offset);
    }

private:
    Point3 origin;
    Point3 lower_left_corner;
    Vector3 horizontal;
    Vector3 vertical;
    Vector3 u, v, w;
    double lens_radius;
};

#endif // CAMERA_H