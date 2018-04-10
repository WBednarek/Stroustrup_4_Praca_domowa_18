#pragma once
#include "../stdafx.h"
#include "../std_lib_facilities_v2.h"


namespace Ex10
{

	class Point
	{
	public:
		Point();
		Point(double x, double y);
		~Point();
		double& get_x();
		double& get_y();

		double x;
		double y;
	};

}