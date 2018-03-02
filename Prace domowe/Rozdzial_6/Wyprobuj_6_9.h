// This is example code from Chapter 6.6 "Trying the first version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

/*


#include "../stdafx.h"
#include "../../../../../std_lib_facilities_v2.h"

//------------------------------------------------------------------------------

class Token {
public:
	char kind;        // what kind of token
	double value;     // for numbers: a value 
	Token(char ch);    // make a Token from a char
	Token(char ch, double val);     // make a Token from a char and a double
};

class Token_stream
{
public: 
	Token_stream();
	Token get();
	void putback(Token t);

private:
	bool full;
	Token buffer;

};

Token get_token();
double expression();  // read and evaluate a Expression
double term();        // read and evaluate a Term
double primary();
int wyproboj_6_9();



*/
