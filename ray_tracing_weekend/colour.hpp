#pragma once

#include "vec3.hpp"

#include <iostream>

using Colour = Vec3;

void write_colour(std::ostream& out, Colour pixel_colour)
{
	// Write out colour components, scaled to range [0,255].
    out << static_cast<int>(255.999 * pixel_colour.x()) << ' '
        << static_cast<int>(255.999 * pixel_colour.y()) << ' '
        << static_cast<int>(255.999 * pixel_colour.z()) << '\n';
}
