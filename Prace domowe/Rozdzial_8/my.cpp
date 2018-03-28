#include "stdafx.h"
#include "my.h"

int foo;

void print_foo()
{
	cout << "print_foo(): Value of i " << foo << endl;
}


void mprint(int i)
{
	cout << "print_foo(): Value of i = " << i << endl;
}

void swap_v(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swap_r( int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swap_cr(const int& a, const int& b)
{
	int temp;
	temp = a;
	//a = b;
	//b = temp;
}