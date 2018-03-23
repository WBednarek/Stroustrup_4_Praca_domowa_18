#include "stdafx.h"
#include "Token_stream.h"



Token_stream::Token_stream() : is_buffer_full(false)
{
}


void Token_stream::ignore_signs(char sign_to_find)
{
	char current_sign = ' ';
	if (is_buffer_full)
	{
		if (buffer.kind == sign_to_find) return;
		
	}
	
	while (cin >> current_sign)
	{
		if (current_sign == sign_to_find) return;
	}

}

void Token_stream::unget(Token t)
{
	if (is_buffer_full == true) error("Token_stream::unget(): Buffer is full"); // I made typical mistake xD, instead of == I putted single =
	is_buffer_full = true;
	buffer = t;
}

Token Token_stream::get()
{
	if (is_buffer_full == true)
	{
		is_buffer_full = false;
		return buffer;
	}
	char ch = ' ';
	cin >> ch;
	
	switch (ch)
	{
	case '+': case '-': case '*': case '/': case '%':
	case ',': case '(': case ')': case '=':
	{
		return Token(ch);
	}
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	case '.':
	{
		double val = 0;
		cin.putback(ch);
		cin >> val;
		return Token(number, val);
	}
	case quit:
	{
		return Token(quit);
	}
	case print:
	{
		return Token(print);
	}
		

	//defining own variable when calculator runs (in calculator)
	default:
		if (isalpha(ch) || isprint(ch))
		{
			string s = "";
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
			cin.unget(); // THAT LINE FIXED MY PROBLEM, because in the last loop iteration it gets the next symbol after searched word; 
			//cin.get(ch) does that in while loop eg. in sqrt(2) in the last loop iteration it eats '(' as well
				if (s == "let") return Token(declaration);
				if (s == "koniec") return Token(quit);
				if (s == "sqrt") return Token(sqrt_sign);
				if (s == "pow") return Token(pow_sign);
				return Token(variable, s);
				
			
		}
		error("Bad token");	
	}
	return Token('a');
}








