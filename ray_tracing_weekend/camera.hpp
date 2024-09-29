#pragma once

#include "colour.hpp"
#include "hittable.hpp"

class Camera
{
public:
	
	void render(const Hittable& world)
	{
		;
	}

private:
	
	void initialise()
	{
		;
	}

	Colour ray_colour(const Ray& r, const Hittable& world) const
	{
		;
	}
};
