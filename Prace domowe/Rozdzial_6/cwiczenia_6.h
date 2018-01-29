#pragma once
#include "../stdafx.h"

//
// this is example code from chapter 6.7 "trying the second version" of
// "software - principles and practice using c++" by bjarne stroustrup
//

/*
this file is known as calculator02buggy.cpp

i have inserted 5 errors that should cause this not to compile
i have inserted 3 logic errors that should cause the program to give wrong results

first try to find an remove the bugs without looking in the book.
if that gets tedious, compare the code to that in the book (or posted source code)

happy hunting!

*/


#include "../std_lib_facilities_v2.h"

//------------------------------------------------------------------------------

class Token {
public:
	char kind;        // what kind of Token
	double value;     // for numbers: a value 
	Token(char ch);   // make a Token from a char
	Token(char ch, double val);     // make a Token from a char and a double

};

//------------------------------------------------------------------------------

class Token_stream {
public:
	Token_stream();   // make a token_stream that reads from cin
	Token get();      // get a Token (get() is defined elsewhere)
	void putback(Token t);    // put a Token back
private:
	bool full;        // is there a Token in the buffer?
	Token buffer;     // here is where we keep a Token put back using putback()
};

    // provides get() and putback() 

double primary();
double term();
double expression();
int cwiczenia_6_1();

