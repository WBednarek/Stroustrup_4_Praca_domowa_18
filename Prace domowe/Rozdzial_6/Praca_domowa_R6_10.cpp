#include "stdafx.h"
#include "Praca_domowa_R6_10.h"


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
	/*catch (exception & e)
	{
	cerr << e.what() << endl;
	error("Unhandled exception");
	}*/

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
	const char number = '8';

	const char permutation_option = 'p';
	const char combination_option = 'c';
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
	case permutation_option:
	{
		return Token(permutation_option, character_option);
	}
	case combination_option:
	{
		return Token(combination_option, character_option);
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

/*
My solution of igrone(0 funtion
In my solution it os not member of Token_stream() class.
In my solution I am not checking buffer in Token_stream, it is disadvantage.

bool characters_ignore(char sign_to_check)
{
char to_check = ' ';

while (cin >> to_check)
{
if (to_check == sign_to_check) return true;
}

return true;
}


*/


void Token_stream::ignore(char sign_to_find)
{

	if (full && buffer.get_type() == sign_to_find)
	{
		full = false;
		return;
	}
	full = false;

	char to_check = ' ';
	while (cin >> to_check)
	{
		if (to_check == sign_to_find) return;
	}

}

void select_operation(int a, int b, char selection)
{
	const char permutation_option = 'p';
	const char combination_option = 'c';
	//cout << "Select type of operation\ninput 'c' for combitation\ninput'p' for permutation" << endl;
	//char selection = ' ';
	//cin >> selection;
	switch (selection)
	{
	case permutation_option:
		cout << "Result of permutation is: " << permutation(a, b) << endl;
		break;
	case combination_option:
		cout << "Number of combinations: " << combination(a, b) << endl;
		break;
	default:
		error("No such option type:\n'c' for combitation or\n'p' for permutation\n");
		break;
	}
}

//TO DO check how to make work sceranio of input data like: 10 3 c ; 3 2 p ; etc.

void clean_up_mess(char sign_to_check)
{
	ts.ignore(sign_to_check);
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
	t = ts.get();
	char c = t.get_type();
	if (a < b)
	{
		cout << "a has to be bigger than b, input values again\n" << endl;
		calculate();
	}

	if (a < 0 || b < 0) error("Inputted by user numbers for permuation/combination are less than 0");

	char to_print = ts.get().type;
	if (to_print == print)
	{
		select_operation(a, b, c);
	}

	return true;
}

int calculate()
{
	const char exit = 'e';
	const char print = ';';
	cout << "Input two numbers with spaces" << endl;
	cout << "After inputting two numbers select operation to perform\n c - combination\n p - permutation" << endl;
	cout << "Type \"e\" to finish program, type \";\" to print output" << endl;
	cout << "Example input: 12 3 p ;" << endl;
		while (cin)
		{
			try {
				if (!handle_input(print, exit))
				{
					return -1;
				}

		}
		catch (exception & e)
		{
			cerr << e.what() << endl;
			cout << "Try again" << endl;
			clean_up_mess(print);
		}
		catch (...)
		{
			cerr << "Exception" << endl;
			return -1;
		}

	}
	
	return 0;

}
