#include "../stdafx.h"
#include "../../../../../std_lib_facilities_v2.h"


/**
Program for counting permutations and combinations

Software asks user for input two numbers with spaces and asks if count combination or permutation.
User inputs 'c' character for combibation 'p' for permutation.
At the end program returns result of selected by user operation.

*/



/*

long long factorial(int number);

long long permutation(int a, int b);

long long combination(int a, int b);

void clean_up_mess(char sign_to_check);

bool handle_input(char print, char exit);

int calculate();

void select_operation(int a, int b, char selection);

class Token
{
private:
	
	int	value;
public:
	char type;
	Token(char type, int value);
	Token(int value);
	Token();
	char get_type();
	int get();
};


class Token_stream
{
private:
	bool full;
	Token buffer;
public:
	Token get();
	void putback(Token t);
	Token_stream();
	void ignore(char sign_to_find);
};


*/






/*
Pseudocode

factorial(int number)
{
const int max_valid_input = 20; //Value based on experimental tests
if(number < 0) error("Input number to factorial function is less than 0);
if(number == 0) return 1;
if(number == 1) return 1;
factorial_output = number * factorial(number - 1);
if(factorial_output < 0) error("To big output for factorial function"); //When a number exceed type range it may be less than zero
return lactorial output;


permutaion(int a, int b) // Such trivial variables names, since those names are in the permutation formula
{
	ldenominator = factorial(a-b);
	if (denominator == 0) error("Demoninator in the functionpermutation is equal 0"); // It should not happen since you won't find such number for factorial to have 0 in result, 
	//but nothing scarry will happen if we check that statement anyway.
	numerator = factorial(a);

	result = numerator / denominator;
	if (result < 0) error("Permutation result is wrong in permutation function");
	return result;

}

long long combination(int a, int b)
{
	enominator = factorial(b);
	if (denominator == 0) error("Demoninator in the functionpermutation is equal 0"); // It should not happen since you won't find such number for factorial to have 0 in result,
	//but nothing scarry will happen if we check that statement anyway.
	numerator = permutaion(a, b);

	result = numerator / denominator;
	if (result < 0) error("Permutation result is wrong in permutation function");
	return result;
}

class Token
{
private:
type
value
public:
Token(type, value) : type(type), value(value)
Token(value) : value(value)
get_type();
get();
};

char Token::get_type()
{
	return type;
}

char Token::get()
{
return value;
}

class Token_stream
{
private:
bool full;
Token buffer;
public:
get();
putback();
Token_steram() : full(false)
}

Token Token_stream::get()
{
if(buffer == full) return buffer;

const char exie = 'e';
const char number = '8';
char input = ' ';
exit = 'e'
cin >> input;
	swich(input)
	{
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		{
			return Token(input)
		}
		case exit:
		{
			return Token(character, input)
		}
		default:
			error("Wrong token");
			break;
	}
}

Token_stream::putback(Token t)
{
	if(buffer == true) error("Putback function call when buffer is full");
	buffer = t;
	full = true;
}



Token_stream ts;


void calculate()
{
const char exit = 'e';
while(cin)
{	
	cout << "Input two numbers with spaces, type "end" to finish program" << endl;
	Token t = ts.get();
	if(t.get_type() == end) exit_program;
	ts.putback(t);
	int a = ts.get();
	int b = ts.get();
	if(a < 0 || b < 0) error("Inputted by user numbers for permuation/combination are less than 0");
	select_operation(a, b);
}

void select_operation(int a, int b)
{
	const char permutation = 'p'
	const char combination = 'c';
	cout << "Select type of operation\n'c' for combitation\n'p' for permutation" << endl;
	char selection = ' ';
	switch(selection)
	{
	case permutation:
		permutation(a, b);
		break;
	case combination:
		combination(a, b);
		break;
	default:
		error("No such option type 'c' for combitation or 'p' for permutation");
		break;
}


*/