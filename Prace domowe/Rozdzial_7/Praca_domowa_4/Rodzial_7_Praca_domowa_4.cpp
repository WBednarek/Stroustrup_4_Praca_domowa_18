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

	}
}

void calculation()
{
	try 
	{
		while (true)
		{
			Token t;
			t = ts.get();
			if (t.kind == quit) return;
			if (t.kind == print)
			{
				cout << result_sign << statement() << endl;
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
	return 0.0;
}



