#pragma once

#include "../../stdafx.h"
#include "../../std_lib_facilities_v2.h"
#include "Variable.h"
#include "Database.h"



class Symbol_table
{
	vector<Variable> variable_table;
public:
	Symbol_table();
	~Symbol_table();
	bool is_defined(string name);
	Variable get_element(string name);
	void set_element(Variable elem);
};

