#pragma once
#include "../../stdafx.h"
#include "../../std_lib_facilities_v2.h"

class Variable
{
private:
	string name;
	double value;
public:
	Variable(string name, double value);
	Variable(string name);
};