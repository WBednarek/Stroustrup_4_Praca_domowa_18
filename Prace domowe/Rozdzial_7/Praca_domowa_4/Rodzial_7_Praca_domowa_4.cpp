#include "stdafx.h"
#include "Rodzial_7_Praca_domowa_4.h"

/*
Chapter 7 Exercise 4
Napisaæ kalkulator od nowa

*/



Symbol_table st;
Token_stream ts;

void praca_domowa_R7_4()
{
	try
	{
		calculation();
	}
	catch (runtime_error & e)
	{
		cerr << e.what() << endl;
	}
	catch (...)
	{
		cerr << " Unknown error" << endl;
	}
}

void calculation()
{
	st.define("PI", 3.14);
	while (true)
	{
		try 
		{	
			cout << prompt << " ";
			Token t;
			t = ts.get();
			if (t.kind == quit) return;
			ts.unget(t);
			double result = statement();
			t = ts.get();
			if (t.kind == print)
			{
				cout << result_sign << " " <<  result << endl;
			}		
				
		}
		
		catch (runtime_error & e)
		{
			cerr << e.what() << endl;
			clean_up_mess();
		}

	}
}

void clean_up_mess()
{
	ts.ignore_signs(print);
}



double statement()
{
	Token t = ts.get();
	double result = 0.0;
	switch (t.kind)
	{
	case declaration:
		result = declare_variable();
		break;
	default:
		ts.unget(t);
		result = expression();
		break;
	}

	return result;
}



double expression()
{
	double left = term();
	Token t;
	while (cin)
	{
		t = ts.get();
		switch (t.kind)
		{
		case '+':
			//t = ts.get();
			left += term();
			break;
		case '-':
			//t = ts.get();
			left -= term();
			break;
		
		default:
			ts.unget(t);
			return left;
			//error("Addition or subtraction operation expected");
		}
		
	}
	return left;
}

double term()
{
	double left = primary();
	Token t;
	while (cin)
	{
		t = ts.get();
		switch (t.kind)
		{
		case '*':
			left *= primary();
			break;
		case '/':
		{
			double divisior = primary();
			if (divisior == 0)
				error("Division operation: dividing by zero");
			left /= divisior;
			break;
		}		
		case '%':
		{
			double right = primary();
			int int_left = int(left);
			if ((left - int_left) != 0)
				error("Modulo operation: The first (left) modulo operation argument is non-integer");
			int int_right = int(right);
			if ((right - int_right) != 0)
				error("Modulo operation: The second (right) modulo operation argument is non-integer");
			if (int_right == 0)
				error("Modulo operation: Dividing by zero");
			left = int_left % int_right;
			break;
		}
		default:
			ts.unget(t);
			//error("Multiplication or division operation expected");
			return left;
		}
	}
	
	return left;
}

double primary()
{
	Token t;
	t = ts.get();
	double left = 0.0;
	switch (t.kind)
	{
	case '(':
		left = expression();
		t = ts.get();
		if (t.kind != ')')
			error("No closing bracket ')' in expression");
		break;
	case number:
		return t.value;
	case minus_sign:
		return -expression();
	case plus_sign:
		return +expression();
	case variable:
		return st.get(t.name); // returning value from variable table
	case sqrt_sign:
	{
		t = ts.get();
		if (t.kind != '(')
			error("No opening bracket '(' in sqrt operation");
		left = expression();
		t = ts.get();
		if (t.kind != ')')
			error("No closing bracket ')' in sqrt operation");
		return sqrt(left);
	}
	case pow_sign:
	{
		t = ts.get();
		if (t.kind != '(')
			error("No opening bracket '(' in pow (power of) operation");
		left = expression();
		t = ts.get();
		if (t.kind != ',')
			error("Comma sign ',' expected in pow (power of) operation");
		double i = expression();
		t = ts.get();
		if (t.kind != ')')
			error("No closing bracket ')' in pow (power of)  operation");
		return my::pow(left, i);
	}
	default:
		error("Primary expected");
		break;

	}
	return left;
}


bool is_integer(double to_check)
{
	if (to_check - int(to_check) != 0.0)
	{
		return false;
	}
	return true;
}


double declare_variable()
{
	string var_name = ""; //Try to define when it is acceptable empty string, later it may (it rather will) cause the errors
	char ch = ' ';
	cin >> ch;
	if (!isdigit(ch) || !isalpha(ch))
	{
		cin.putback(ch);
		while (cin >> ch && ch != '=')
		{
			if (isalpha(ch))
			{
				var_name += ch;
			}
			else
			{
				error("Variable name has to contain only letters and digits (also digit cannot be on the first position)");
			}
		}
		cin.putback(ch);
	}
	else
	{
		error("Variable name has to have a letter at the first position");
	}
	Token t;
	t = ts.get();
	if (t.kind != '=')
	{
		error("No '=' sign found after variable name");
	}
	double declared_variable = expression();
	st.set(Variable(var_name, declared_variable)); // Adding variable to Symbol_table st object
	
	return declared_variable;
	//TODO 
	//concatenate chars instead of reading whole string. We need to check if char is valid ie. is not '='; '['; '>' etc. Only numebrs (apart from the first one) and signs
}




double my::pow(double x, double i)
{


	if (i == 0) 
	{
		return 1.0;
	}
	if (x == 0) 
	{
		return 0.0;
	}
	
	double result = 0;
	if (is_integer(i) && i > 0)
	{
		result = my::pow_int(x, i);
	}

	if (is_integer(i) && i < 0)
	{
		result = my::pow_negative_exponent(x, i);
	}

	return result;

}

double my::pow_int(double x, double i)
{
	double result = 0;
	if (is_integer(i) && i > 0)
	{
		result = x;
		for (int j = 1; j < i; ++j)
		{
			result *= x;
		}
	}

	return result;
}

double my::pow_negative_exponent(double x, double i)
{
	double result = 0;
	if (is_integer(i) && i < 0)
	{
		result = 1/x;
		i = abs(i);
		for (int j = 1; j < i; ++j)
		{
			result *= 1/x;
		}
	}

	return result;
}
