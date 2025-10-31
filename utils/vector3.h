#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>
#include <iostream>

#include "constants.h"

class Vector3 {
public:
    Vector3() : basis_{0, 0, 0} {}
    Vector3(const double e0, const double e1, const double e2)
        : basis_{e0, e1, e2} {}

    [[nodiscard]] auto X() const -> double { return basis_[0]; }

    [[nodiscard]] auto Y() const -> double { return basis_[1]; }

    [[nodiscard]] auto Z() const -> double { return basis_[2]; }

    auto operator-() const -> Vector3 {
        return Vector3(-basis_[0], -basis_[1], -basis_[2]);
    }

    auto operator[](const int i) const -> double { return basis_[i]; }

    auto operator[](const int i) -> double & { return basis_[i]; }

    auto operator+=(const Vector3 &v) -> Vector3 & {
        basis_[0] += v.basis_[0];
        basis_[1] += v.basis_[1];
        basis_[2] += v.basis_[2];
        return *this;
    }

    auto operator*=(const double t) -> Vector3 & {
        basis_[0] *= t;
        basis_[1] *= t;
        basis_[2] *= t;
        return *this;
    }

    auto operator-=(const Vector3 &v) -> Vector3 & { return *this += (-v); }

    auto operator/=(const double t) -> Vector3 & { return *this *= 1 / t; }

    [[nodiscard]] auto Length() const -> double {
        return std::sqrt(LengthSquared());
    }

    [[nodiscard]] auto LengthSquared() const -> double {
        return (basis_[0] * basis_[0]) + (basis_[1] * basis_[1]) +
               (basis_[2] * basis_[2]);
    }

    static auto Random() -> Vector3 {
        return Vector3(RandomDouble(0, 1), RandomDouble(0, 1),
                       RandomDouble(0, 1));
    }

    static auto Random(double min, double max) -> Vector3 {
        return Vector3(RandomDouble(min, max), RandomDouble(min, max),
                       RandomDouble(min, max));
    }

    [[nodiscard]] auto NearZero() const -> bool {
        // Return true if the vector is close to zero in all dimensions.
        const auto s = 1e-8;
        return (fabs(basis_[0]) < s) && (fabs(basis_[1]) < s) &&
               (fabs(basis_[2]) < s);
    }

    friend auto operator<<(std::ostream &out, const Vector3 &v)
        -> std::ostream &;
    friend auto operator+(const Vector3 &u, const Vector3 &v) -> Vector3;
    friend auto operator-(const Vector3 &u, const Vector3 &v) -> Vector3;
    friend auto operator*(const Vector3 &u, const Vector3 &v) -> Vector3;
    friend auto operator*(double t, const Vector3 &v) -> Vector3;
    friend auto Dot(const Vector3 &u, const Vector3 &v) -> double;
    friend auto Cross(const Vector3 &u, const Vector3 &v) -> Vector3;

private:
    double basis_[3];
};

inline auto operator<<(std::ostream &out, const Vector3 &v) -> std::ostream & {
    return out << v.basis_[0] << ' ' << v.basis_[1] << ' ' << v.basis_[2];
}

inline auto operator+(const Vector3 &u, const Vector3 &v) -> Vector3 {
    return Vector3(u.basis_[0] + v.basis_[0], u.basis_[1] + v.basis_[1],
                   u.basis_[2] + v.basis_[2]);
}

inline auto operator-(const Vector3 &u, const Vector3 &v) -> Vector3 {
    return Vector3(u.basis_[0] - v.basis_[0], u.basis_[1] - v.basis_[1],
                   u.basis_[2] - v.basis_[2]);
}

inline auto operator*(const Vector3 &u, const Vector3 &v) -> Vector3 {
    return Vector3(u.basis_[0] * v.basis_[0], u.basis_[1] * v.basis_[1],
                   u.basis_[2] * v.basis_[2]);
}

inline auto operator*(double t, const Vector3 &v) -> Vector3 {
    return Vector3(t * v.basis_[0], t * v.basis_[1], t * v.basis_[2]);
}

inline auto operator*(const Vector3 &v, double t) -> Vector3 { return t * v; }

inline auto operator/(Vector3 v, double t) -> Vector3 { return (1 / t) * v; }

inline auto Dot(const Vector3 /*unused*/ &u, const Vector3 &v) -> double {
    return (u.basis_[0] * v.basis_[0]) + (u.basis_[1] * v.basis_[1]) +
           (u.basis_[2] * v.basis_[2]);
}

inline auto Cross(const Vector3 /*unused*/ &u, const Vector3 &v) -> Vector3 {
    return Vector3((u.basis_[1] * v.basis_[2]) - (u.basis_[2] * v.basis_[1]),
                   (u.basis_[2] * v.basis_[0]) - (u.basis_[0] * v.basis_[2]),
                   (u.basis_[0] * v.basis_[1]) - (u.basis_[1] * v.basis_[0]));
}

inline auto UnitVector(Vector3 v) -> Vector3 { return v / v.Length(); }

auto RandomInUnitSphere() -> Vector3;

inline auto RandomUnitVector() -> Vector3 {
    return UnitVector(RandomInUnitSphere());
}

inline auto Reflect(const Vector3 /*unused*/ &v, const Vector3 &n) -> Vector3 {
    return v - 2 * Dot(v, n) * n;
}

auto Refract(const Vector3 &uv, const Vector3 &n, double etai_over_etat)
    -> Vector3;

auto RandomInUnitDisk() -> Vector3;

// Type aliases for Vector3
using Point3 = Vector3; // 3D point
using Color = Vector3;  // RGB color

#endif // VECTOR3_H