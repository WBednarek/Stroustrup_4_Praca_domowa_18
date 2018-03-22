#include "stdafx.h"
#include "Symbol_table.h"


Symbol_table::Symbol_table()
{
}


Symbol_table::~Symbol_table()
{
}

bool Symbol_table::is_defined(string name)
{
	for (Variable v : variable_table)
	{
		if (v.name == name) return true;
	}

	return false;
}



Variable Symbol_table::get_element(string name)
{
	if (is_defined(name))
	{
		for (Variable v : variable_table)
		{
			if (v.name == name) return v;
		}
	}
	else
	{
		error("Symbol_table: No such element in variable_table vector");
	}

	return Variable("Default");
}

void Symbol_table::set_element(Variable elem)
{
	if (!is_defined(elem.name))
	{
		variable_table.push_back(elem);
	}
	else
	{
		error("Symbol_table: Variable already exist");
	}
	

}
