#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <limits>
#include <random>

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline auto DegreesToRadians(double degrees) -> double {
    return degrees * pi / 180.0;
}

inline auto RandomDouble() -> double {
    static std::uniform_real_distribution<double> distribution(-1.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

inline auto RandomDouble(double min, double max) -> double {
    // Returns a random real in [min,max).
    return min + ((max - min) * (RandomDouble() + 1.0) / 2);
}

inline auto Clamp(double x, double min, double max) -> double {
    if (x < min) {
        return min;
    }
    if (x > max) {
        return max;
    }
    return x;
}

#endif // CONSTANTS_H