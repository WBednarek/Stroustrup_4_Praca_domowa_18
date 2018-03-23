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
	bool is_declared(string name);
	double get(string name);
	void set(Variable elem);
	vector<Variable> get_var_table();
	void define(string name, double value);
};

