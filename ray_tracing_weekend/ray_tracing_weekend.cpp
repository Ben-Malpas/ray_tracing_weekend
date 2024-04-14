// ray_tracing_weekend.cpp : Defines the entry point for the application.
//

#include "ray_tracing_weekend.hpp"

#include "colour.hpp"
#include "ray.hpp"
#include "vec3.hpp"

#include <iostream>

double hit_sphere(const Point3& center, double radius, const Ray& r)
{
	Vec3 oc = center - r.origin();
	auto a = r.direction().length_squared();
	auto h = dot(r.direction(), oc);
	auto c = oc.length_squared() - radius * radius;
	auto discriminant = h * h - a * c;

	if (discriminant < 0)
	{
		return -1.0; // Magic value, maybe replace this with an optional or something
	}
	else
	{
		return (h - sqrt(discriminant)) / a;
	}
}

Colour ray_colour(const Ray& r)
{
	auto t = hit_sphere(Point3(0, 0, -1), 0.5, r);
	if (t > 0.0)
	{
		Vec3 N = unit_vector(r.at(t) - Vec3(0, 0, -1));
		return 0.5 * Colour(N.x() + 1, N.y() + 1, N.z() + 1);
	}

	Vec3 unit_direction = unit_vector(r.direction());
	auto a = 0.5 * (unit_direction.y() + 1.0);
	return (1 - a) * Colour(1, 1, 1) + a * Colour(0.5, 0.7, 1);
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
