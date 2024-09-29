// ray_tracing_weekend.cpp : Defines the entry point for the application.
//

#include "ray_tracing_weekend.hpp"

#include "camera.hpp"
#include "colour.hpp"
#include "hittable.hpp"
#include "hittable_list.hpp"
#include "ray.hpp"
#include "sphere.hpp"
#include "vec3.hpp"

#include <iostream>

int main()
{
	// World

	HittableList world;

	world.add(std::make_shared<Sphere>(Point3(0, 0, -1), 0.5));
	world.add(std::make_shared<Sphere>(Point3(0, -100.5, -1), 100));

	Camera cam;

	cam.aspect_ratio = 16.0 / 9.0;
	cam.image_width = 400;

	cam.render(world);
}
