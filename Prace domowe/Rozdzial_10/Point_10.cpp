#include "stdafx.h"
#include "Point_10.h"

namespace Ex10
{
	Point::Point() : x(0), y(0)
	{
	}

	Point::Point(double x, double y) : x(x), y(y)
	{
	}





	Point::~Point()
	{
	}

	double& Point::get_x()
	{
		return x;
	}

	double& Point::get_y()
	{
		return y;
	}
}