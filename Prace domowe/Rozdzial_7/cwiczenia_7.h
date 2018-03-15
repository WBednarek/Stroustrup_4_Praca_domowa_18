#pragma once
#include "../stdafx.h"
#include "../std_lib_facilities_v2.h"

struct Token {
	char kind;
	double value;
	string name;
	Token(char ch);
	Token(char ch, string name);
	Token(char ch, double val);
};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }
	Token get();
	void unget(Token t);
	void ignore(char);
};

double get_value(string s);

void set_value(string s, double d);

bool is_declared(string s);

double primary();

double term();

double expression();

double declaration();

double statement();

void clean_up_mess();

void calculate();

int cwiczenia_7();

void define_name(string name, double value);

double calculate_pow(double x, double i);
