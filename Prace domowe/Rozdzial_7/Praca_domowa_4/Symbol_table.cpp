#include "stdafx.h"
#include "Symbol_table.h"


Symbol_table::Symbol_table()
{
}


Symbol_table::~Symbol_table()
{
}

bool Symbol_table::is_declared(string name)
{
	for (Variable v : variable_table)
	{
		if (v.name == name) return true;
	}

	return false;
}



double Symbol_table::get(string name)
{
	if (is_declared(name))
	{
		for (Variable v : variable_table)
		{
			if (v.name == name) return v.value;
		}
	}
	else
	{
		error("Symbol_table: No such element in variable_table vector");
	}

	return -1.0;
}

void Symbol_table::set(Variable elem)
{
	if (!is_declared(elem.name))
	{
		variable_table.push_back(elem);
	}
	else
	{
		error("Symbol_table: Variable already exist");
	}
	

}

vector<Variable> Symbol_table::get_var_table()
{
	return variable_table;
}

void Symbol_table::define(string name, double value)
{
	//*this.set(Variable(name, value));
	set(Variable(name, value));
}
