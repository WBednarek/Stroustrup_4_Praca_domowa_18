#include "stdafx.h"
#include "Rodzial_7_Praca_domowa_4.h"

/*
Chapter 7 Exercise 4
Napisaæ kalkulator od nowa

*/


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
	ignore_signs(print);
}





void ignore_signs(char sign_to_find)
{
	char current_sign = ' ';
	while (cin >> current_sign)
	{
		if (current_sign == sign_to_find) return;
	}

}


double statement()
{
	double result = expression();
	

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
			left /= primary();
			break;
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
	case sqrt_sign:
		t = ts.get();
		if (t.kind != '(')
			error("No opening bracket '(' in sqrt operation");
		left = expression();
		t = ts.get();
		if (t.kind != ')')
			error("No closing bracket ')' in sqrt operation");
		return sqrt(left);
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
	if (to_check - int(to_check) != 0)
	{
		return false;
	}
	return true;
}




double my::pow(double x, double i)
{


	if (i == 0) // Change the previous program!
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
