#pragma once

#include "ray.hpp"

class HitRecord
{
public:
	Point3 p;
	Vec3 normal;
	double t;
	bool front_face;

	void set_face_normal(const Ray& r, const Vec3& normalised_outward_normal)
	{
		// Sets the hit record normal vector
		front_face = dot(r.direction(), normalised_outward_normal);
		normal = front_face ? normalised_outward_normal : -normalised_outward_normal;
	}
};

class Hittable
{
public:
	virtual ~Hittable() = default;

	virtual bool hit(const Ray & r, double ray_tmin, double ray_tmax, HitRecord & rec) const = 0;
};