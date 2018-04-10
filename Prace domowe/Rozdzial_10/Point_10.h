#pragma once
#include "../stdafx.h"
#include "../std_lib_facilities_v2.h"

class Point_10
{
public:
	Point_10();
	Point_10(double x, double y);
	~Point_10();
	double& get_x();
	double& get_y();

	double x;
	double y;
};

