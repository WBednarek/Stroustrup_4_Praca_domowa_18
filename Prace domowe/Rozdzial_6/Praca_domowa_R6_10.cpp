#include "stdafx.h"
#include "Praca_domowa_R6_10.h"



long long factorial(int number)
{
	const int max__tested_input = 20; // Value based on experimental (empirical) tests
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
	if (factorial_out <= 0) error("To big output for factorial function"); //When sosme number exceed type range it may be less than zero
	return factorial_out;
}


long long permutation(int a, int b) // Such trivial variables names, since those names are in the permutation formula
{
	long long denominator = factorial(a - b);
	if (denominator == 0) error("Demoninator in the functionpermutation is equal 0"); // It should not happen since you won't find such number for factorial to have 0 in result, 
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



void calculate()
{
	const string finish_program = "end";
	while (cin)
	{
		int a = 0;
		int b = 0;
		cout << "Input two numbers with spaces, type \"end\" to finish program" << endl;
		cin >> a >> b;
		if (a < 0 || b < 0) error("Inputted by user numbers for permuation/combination are less than 0");
		select_operation(a, b);
	}
}

void select_operation(int a, int b)
{
	const char permutation_option = 'p';
	const char combination_option = 'c';
	cout << "Select type of operation\n'c' for combitation\n'p' for permutation" << endl;
	char selection = ' ';
	switch (selection)
	{
	case permutation_option:
		permutation(a, b);
		break;
	case combination_option:
		combination(a, b);
		break;
	default:
		error("No such option type 'c' for combitation or 'p' for permutation");
		break;
	}