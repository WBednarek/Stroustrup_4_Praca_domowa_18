#include "stdafx.h"
#include "cwiczenia_7.h"



/*
calculator08buggy.cpp

Helpful comments removed.

We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/


const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char sqrt_option = 'S';
const char pow_option = 'P';


Token::Token(char ch) : kind(ch), value(0)
{
}

Token::Token(char ch, string name) : kind(ch), name(name) // 5th logical mistake, no name constructor
{
}

Token::Token(char ch, double val) : kind(ch), value(val)
{
}




Token Token_stream::get()
{
	if (full) { full = false; return buffer; } // check buffer
	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case ',': // To use in pow(x, i) function
	//case '#': // To use in value declaration
		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget(); // this function used to be named putback()
	double val;
	cin >> val;
	return Token(number, val);
	}
	 
	default:
		if (isalpha(ch) || isprint(ch)) {
			string s;
			s += ch;
			
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch; // 2nd logical mistake, string should be made of chars, so s += ch;
			cin.unget();
			if (s == "#") return Token(let);
			if (s == "koniec") return Token(quit); // 1st logical mistake catched
			if (s == "pow") return Token(pow_option);
			if (s == "sqrt") return Token(sqrt_option);
			return Token(name,s); // 1st compiling mistake catched
		}
		error("Bad token");
	}
}

//Store variable in the buffer
void Token_stream::unget(Token t)
{
	buffer = t; 
	full = true;
}

//Ignores all charaters until c variable is found
void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names; // Stores names of declated variables in calculator

double get_value(string s)
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
}

void set_value(string s, double d)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts;


double primary()
{
	Token t = ts.get(); // get the next value form cin stream
	switch (t.kind) {
	case '(':
	{	
	double d = expression(); // ! What to do with d? 3rd logical miatake
	t = ts.get();
	if (t.kind != ')') error("'(' expected"); //Brackets needed to be closed
	return d; //3rd logical mistake, nothing was returned
	}
	case '-':
		return - primary();
	case '+':
			return +primary();
	case number:
		return t.value; //returns single inputted number to be displayed
	case name:
		return get_value(t.name); // returns value of defined variable stored in names vector
	case pow_option:
	{
		t = ts.get();
		if (t.kind == '(')
		{
			double x = expression();
			t = ts.get();
			if (t.kind != ',') error("No , in pow(x, i) function");
			double i = expression();
			t = ts.get();
			if (t.kind != ')') error("No closing bracket ')' in pow(x, i) function");
			return calculate_pow(x, i);
		}
	}	
	case sqrt_option:
	{
		t = ts.get();
		if (t.kind == '(')
		{
			double d = expression();
			t = ts.get();
			if (t.kind != ')') error("No closing bracket ')' in sqrt function");
			if (d < 0) error("Sqrt function argument is less than 0");
			return sqrt(d);
		}
	}
	default:
		error("primary expected");
	}
}

//Handling multiplication and division
double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) error("divide by zero");
		left /= d;
		break;
		}		
		default:
			ts.unget(t); 
			return left;
		}
	}
}

//Handling addition and subtraction
double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

//Allows to declare variables names in calculator e.g. let x = 23;
double declaration()
{
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration"); //'a' is magic constant, 1st style mistake, (should I consider it as 4th logical mistake ?)
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name); // magic constant
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

//Checks if there is variable declaration
double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression(); //Just calculate expression
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

// I don't know why does it work
void calculate()
{
	while (true) try {
		
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();  // Ignores all print signs (I assume). Software needs some additional symbol after expression to print value, so if you put: 88+7p it gonna work but it will make an error.
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}


void define_name(string name, double value)
{
	names.push_back(Variable(name, value));
}

double calculate_pow(double x, double i)
{
	int ii = int(i);
	if (abs(ii - i) != 0) error("In pow(x, i) function \"i\" is not an integer");
	if (i == 0) return x;
	//if (i < 0) error("In pow(x, i) function \"i\" cannot be less than 0");
	double pow_result = 0.0;
	if (i < 0)
	{
		pow_result = (1.0 / x); // Remember about having at least one dot in some of numbers in double value e.g. 2.0 instead of 2
		int k = abs(i);
		for (int j = 1; j < k; ++j) // Loop starts from one since pow_result is like powered to minus one, since the begining
		{
			pow_result *= (1.0 / x); 
		}
	}
	else
	{
		pow_result = x;
		for (int j = 1; j < i; ++j) // Loop starts from one since pow_result is like powered to one, since the begining
		{
			pow_result *= x;
		}
	}
	
	return pow_result;
}


int cwiczenia_7()
{
	try {
		define_name("k", 1000);
		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >> c&& c != print); // ';' was magic constant
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin >> c && c != print); // ';' was magic constant
		return 2;
	}
}

