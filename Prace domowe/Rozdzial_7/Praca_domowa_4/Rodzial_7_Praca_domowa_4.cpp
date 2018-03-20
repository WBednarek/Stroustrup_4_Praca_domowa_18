#include "stdafx.h"
#include "Rodzial_7_Praca_domowa_4.h"

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
	try 
	{
		while (true)
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
	}
		
	catch (runtime_error & e)
	{
		cerr << e.what() << endl;
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
	case sqrt_sign:
		t = ts.get();
		if (t.kind != '(')
			error("No opening bracket '(' in sqrt operation");
		left = expression();
		t = ts.get();
		if (t.kind != ')')
			error("No closing bracket ')' in sqrt operation");
		return sqrt(left);
	default:
		error("Primary expected");
		break;
	}
	return left;
}



