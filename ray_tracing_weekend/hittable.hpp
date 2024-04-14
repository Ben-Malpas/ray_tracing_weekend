#pragma once

#include "ray.hpp"

class HitRecord
{
public:
	Point3 p;
	Vec3 normal;
	double t;
};

class hittable
{
public:
	virtual ~hittable() = default;

	virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, HitRecord& rec) const = 0;
};