#include "stdafx.h"
#include "Praca_domowa_R6_10_v2.h"



/*



Token_stream ts; //!!! GLOBAL VARIABLE, but it works with Stroustrup PPP Chapter 6

long long factorial(int number)
{
	try
	{
		const int max__tested_input = 20; // Value of 20 based on experimental (empirical) tests
		const long long max_tested_output = 2432902008176640000; // Value based on experimental (empirical) tests
		if (number < 0) error("Factorial input is less than 0");
		if (number > max__tested_input) error("To big input number for factorial function");
		if (number == 0)
		{
			return 1;
		}

		if (number == 1)
		{
			return 1;
		}
		long long factorial_out = number * factorial(number - 1);
		if (factorial_out <= 0) error("To big output for factorial function"); //When some number exceed type range it may be less than zero
		return factorial_out;

	}
	catch (exception & e)
	{
		cerr << e.what() << endl;

	}

}


long long permutation(int a, int b) // Such trivial variables names, since those names are in the permutation formula
{
	//if (a < b) cout << "a has to be bigger than b, input value again" << endl;
	long long denominator = factorial(a - b);
	if (denominator == 0) error("Demoninator in the permutation function is equal 0"); // It should not happen since you won't find such number for factorial to have 0 in result, 
																					   //but nothing scarry will happen if we check that statement anyway.
	long long numerator = factorial(a);

	long long result = numerator / denominator;
	if (result < 0) error("Permutation result is wrong in permutation function");
	return result;

}

long long combination(int a, int b)
{
	long long denominator = factorial(b);
	if (denominator == 0) error("Demoninator in the functionpermutation is equal 0"); // It should not happen since you won't find such number for factorial to have 0 in result,
																					  //but nothing scarry will happen if we check that statement anyway.
	long long numerator = permutation(a, b);

	long long result = numerator / denominator;
	if (result < 0) error("Permutation result is wrong in permutation function");
	return result;
}



Token::Token(char type, int value) : type(type), value(value)
{}

Token::Token(int value) : value(value)
{}


Token::Token()
{}


char Token::get_type()
{
	return type;
}

int Token::get_value()
{
	return value;
}


Token Token_stream::get()
{
	if (full) return buffer;
	const char exit = 'e';
	const char print = ';';
	int character_option = 5;
	char input = ' ';
	cin >> input;
	switch (input)
	{
	case exit:
	{
		return Token(exit, character_option);
	}
	case print:
	{
		return Token(print, character_option);
	}

	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(input);
		int in;
		cin >> in;
		return Token(in);
	}
	default:
		error("Wrong token");
		break;
	}
}

void Token_stream::putback(Token t)
{
	if (full) error("Putback function call when buffer is full");
	buffer = t;
	full = true;
}

Token_stream::Token_stream() : full(false)
{
}


void select_operation(int a, int b)
{
	const char permutation_option = 'p';
	const char combination_option = 'c';
	cout << "Select type of operation\ninput 'c' for combitation\ninput'p' for permutation" << endl;
	char selection = ' ';
	cin >> selection;
	switch (selection)
	{
	case permutation_option:
		cout << "Result of permutation is: " << permutation(a, b) << endl << endl;
		break;
	case combination_option:
		cout << "Number of combinations: " << combination(a, b) << endl << endl;
		break;
	default:
		error("No such option type:\n'c' for combitation or\n'p' for permutation\n");
		break;
	}
}


void clean_up_mess()
{
	cin.ignore(numeric_limits<int>::max(), '\n'); //Skips number of INT_MAX symbols to the next line.
}


bool handle_input(char print, char exit)
{

	Token t;
	t = ts.get();
	if (t.get_type() == exit)
	{
		cout << "exiting program" << endl;
		return false;
	}
	int a = t.get_value();
	t = ts.get();
	int b = t.get_value();
	if (a < b)	error("a has to be bigger than b");
	if (a < 0 || b < 0) error("Inputted by user numbers for permuation/combination are less than 0");
	select_operation(a, b);

	return true;
}

int calculate()
{
	const char exit = 'e';
	const char print = ';';
	
	cout << "Example input: 12 3" << endl;
	while (cin)
	{
		try {
			cout << "Type \"e\" to finish program" << endl;
			cout << "Input two numbers with spaces" << endl;
			if (!handle_input(print, exit))
			{
				return -1;
			}

		}
		catch (exception & e)
		{
			cerr << e.what() << endl;
			cout << "Input values again" << endl << endl;
			clean_up_mess();
		}
		catch (...)
		{
			cerr << "Exception" << endl;
			return -1;
		}

	}

	return 0;

}


*/