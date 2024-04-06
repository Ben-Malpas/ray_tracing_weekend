// ray_tracing_weekend.cpp : Defines the entry point for the application.
//

#include "ray_tracing_weekend.hpp"

#include "colour.hpp"
#include "vec3.hpp"

#include <iostream>

int main()
{
	// Image

	int image_width = 256;
	int image_height = 256;

	// Render

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = 0; j < image_height; ++j)
	{
		std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
		for (int i = 0; i < image_width; ++i)
		{
			auto pixel_colour = Colour(double(i)/(image_width-1), double(j)/(image_height-1), 0);
			write_colour(std::cout, pixel_colour);
		}
	}

	std::clog << "\rDone.                 \n";
	return 0;
}
