#pragma once
#include "../../stdafx.h"
#include "../../std_lib_facilities_v2.h"

struct Token
{
public:
	char kind;
	double value;
	string name;
	Token();
	Token(char kind);
	Token(char kind, double value);
	Token(char kind, string name);
	
};

