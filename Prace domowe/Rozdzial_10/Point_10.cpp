#include "stdafx.h"
#include "Point_10.h"


Point_10::Point_10() : x(0), y(0)
{
}

Point_10::Point_10(double x, double y) : x(x), y(y)
{
}





Point_10::~Point_10()
{
}

double& Point_10::get_x()
{
	return x;
}

double& Point_10::get_y()
{
	return y;
}
