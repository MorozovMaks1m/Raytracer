#ifndef CAMERA_H
#define CAMERA_H

#include "constants.h"
#include "ray.h"

class Camera {
public:
    Camera(Point3 lookfrom, Point3 lookat, Vector3 view_up,
           double vfov, // vertical field-of-view in degrees
           double aspect_ratio, double aperture, double focus_dist)
        : origin_(lookfrom), lensRadius_(aperture / 2) {
        double theta = DegreesToRadians(vfov);
        double h = tan(theta / 2);
        double viewportHeight = 2.0 * h;
        double viewportWidth = aspect_ratio * viewportHeight;

        w_ = UnitVector(lookfrom - lookat);
        u_ = UnitVector(Cross(view_up, w_));
        v_ = Cross(w_, u_);

        horizontalSize_ = focus_dist * viewportWidth * u_;
        verticalSize_ = focus_dist * viewportHeight * v_;
        lowerLeftCorner_ =
            origin_ - horizontalSize_ / 2 - verticalSize_ / 2 - focus_dist * w_;
    }

    [[nodiscard]] auto GetRay(double s, double t) const -> Ray {
        Vector3 rd = lensRadius_ * RandomInUnitDisk();
        Vector3 offset = u_ * rd.X() + v_ * rd.Y();

        return Ray(origin_ + offset, lowerLeftCorner_ + s * horizontalSize_ +
                                         t * verticalSize_ - origin_ - offset);
    }

private:
    Point3 origin_;
    Point3 lowerLeftCorner_;
    Vector3 horizontalSize_;
    Vector3 verticalSize_;
    Vector3 u_, v_, w_;
    double lensRadius_;
};

#endif // CAMERA_H