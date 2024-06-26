#pragma once

#include "hittable.hpp"
#include "vec3.hpp"

class Sphere : public Hittable
{
public:
	Sphere(const Point3 & center, double radius) : center(center), radius(fmax(0,radius)) {}

	bool hit(const Ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override
	{
		Vec3 oc = center - r.origin();
		auto a = r.direction().length_squared();
		auto h = dot(r.direction(), oc);
		auto c = oc.length_squared() - radius * radius;

		auto discriminant = h * h - a * c;
		if (discriminant < 0)
		{
			return false;
		}

		auto sqrtd = sqrt(discriminant);

		// Find the nearest root that lies in the acceptable range.
		auto root = (h - sqrtd) / a;
		if (root <= ray_tmin || ray_tmax <= root)
		{
			root = (h + sqrtd) / a;
			if (root <= ray_tmin || ray_tmax <= root)
			{
				return false;
			}
		}

		rec.t = root;
		rec.p = r.at(rec.t);
		rec.normal = (rec.p - center) / radius;

		return true;
	}

private:
	Point3 center;
	double radius;
};