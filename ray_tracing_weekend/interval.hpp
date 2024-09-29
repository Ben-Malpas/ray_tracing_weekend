#pragma once

#include "ray_tracing_weekend.hpp"

struct Interval
{
	double min;
	double max;

	Interval() : min(+RtWeekend::infinity), max(-RtWeekend::infinity) {}
	 
	Interval(double min, double max) : min(min), max(max) {}

	double size() const
	{
		return max - min;
	}

	bool contains(double x) const
	{
		return min < x && x <= max;
	}

	bool surrounds(double x) const
	{
		return min < x && x < max;
	}

	static const Interval empty;
	static const Interval universe;
};

const Interval Interval::empty = Interval(+RtWeekend::infinity, -RtWeekend::infinity);
const Interval Interval::universe = Interval(-RtWeekend::infinity, +RtWeekend::infinity);
