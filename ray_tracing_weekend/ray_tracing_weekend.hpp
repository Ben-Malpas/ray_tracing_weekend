// ray_tracing_weekend.hpp : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

namespace RtWeekend
{
    // Constants

    const double infinity = std::numeric_limits<double>::infinity();
    const double pi = 3.1415926535897932385;

    // Utility Functions

    inline double degrees_to_radians(double degrees) {
        return degrees * pi / 180.0;
    }
}
