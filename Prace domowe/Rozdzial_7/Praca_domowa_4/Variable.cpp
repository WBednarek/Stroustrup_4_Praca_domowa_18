#include "stdafx.h"
#include "Variable.h"

Variable::Variable(string name) : name(name), value(0)
{
}


Variable::Variable(string name, double value) : name(name), value(value)
{
}

