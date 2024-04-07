// ray_tracing_weekend.cpp : Defines the entry point for the application.
//

#include "ray_tracing_weekend.hpp"

#include "colour.hpp"
#include "ray.hpp"
#include "vec3.hpp"

#include <iostream>

Colour ray_colour(const Ray& r)
{
	return Colour(0, 0, 0); // returns black for now
}

int main()
{
	// Image

	auto aspect_ratio = 16.0 / 9.0;
	int image_width = 400;

	// Calculate image height, and insure it's at least one
	int image_height = static_cast<int>(image_width / aspect_ratio);
	image_height = (image_height < 1) ? 1 : image_height;

	// Camera

	auto focal_length = 1.0;
	auto viewport_height = 2.0;
	auto viewport_width = viewport_height * (static_cast<double>(image_width) / image_height);
	auto camera_center = Point3(0, 0, 0);

	// Calculate vectors which define the edges of the viewport
	auto viewport_u = Vec3(viewport_width, 0, 0);
	auto viewport_v = Vec3(0, -viewport_height, 0);

	// Calculate the horizontal and vertical delta vectors between each pixel
	auto pixel_delta_u = viewport_u / image_width;
	auto pixel_delta_v = viewport_v / image_height;

	// Calculate location of upper left pixel
	auto viewport_upper_left = camera_center 
		- Vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
	auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);


	// Render

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = 0; j < image_height; ++j)
	{
		std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
		for (int i = 0; i < image_width; ++i)
		{
			auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
			auto ray_direction = pixel_center - camera_center;
			Ray r(camera_center, ray_direction);

			Colour pixel_colour = ray_colour(r);
			write_colour(std::cout, pixel_colour);
		}
	}

	std::clog << "\rDone.                 \n";
	return 0;
}
