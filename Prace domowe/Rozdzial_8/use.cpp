#pragma once
#include "stdafx.h"
#include "use.h"


namespace X
{
	int var;
	void print()
	{
		cout << "X::var = " << var << endl;
	}
}

namespace Y
{
	int var;
	void print()
	{
		cout << "Y::var = " << var << endl;
	}
}

namespace Z
{
	int var;
	void print()
	{
		cout << "Z::var = " << var << endl;
	}
}



void cwiczenia_8()
{
	//Exercise 1
	/*foo = 7;
	print_foo();
	mprint(99);

	{
		char cc;
		cin >> cc;
	}*/



	//Exercise 2
	//swap_v(x, y)
	/*int x = 7;
	int y = 9;
	swap_v(x, y);
	swap_v(7, 9);
	cout << "x = 7; y = 9; after swap_v(x, y): x = " << x << " y = " << y << endl;

	const int cx = 7;
	const int cy = 7;
	swap_v(cx, cy);
	swap_v(7.7, 9.9);
	cout << "cx = 7; cy = 9; after swap_v(cx, cy): cx = " << x << " cy = " << y << endl;

	double dx = 7.7;
	double dy = 9.9;
	swap_v(dx, dy);
	swap_v(dx, dy);
	cout << "dx = 7.7; dy = 9.9; after swap_v(dx, dy): dx = " << x << " dy = " << y << endl;*/



	//swap_r(x, y)
	//int x = 7;
	//int y = 9;
	//swap_r(x, y);
	//swap_r(7, 9);
	//cout << "x = 7; y = 9; after swap_r(x, y): x = " << x << " y = " << y << endl;

	//const int cx = 7;
	//const int cy = 7;
	//swap_r(cx, cy);
	//swap_r(7.7, 9.9);
	//cout << "cx = 7; cy = 9; after swap_r(cx, cy): cx = " << x << " cy = " << y << endl;

	//double dx = 7.7;
	//double dy = 9.9;
	//swap_r(dx, dy);
	//swap_r(dx, dy);
	//cout << "dx = 7.7; dy = 9.9; after swap_r(dx, dy): dx = " << x << " dy = " << y << endl;



	//swap_cr(x, y)
	//int x = 7;
	//int y = 9;
	//swap_cr(x, y);
	//swap_cr(7, 9);
	//cout << "x = 7; y = 9; after swap_cr(x, y): x = " << x << " y = " << y << endl;


	//const int cx = 7;
	//const int cy = 7;
	//swap_cr(cx, cy);
	//swap_cr(7.7, 9.9);
	//cout << "cx = 7; cy = 9; after swap_cr(cx, cy): cx = " << x << " cy = " << y << endl;

	//double dx = 7.7;
	//double dy = 9.9;
	//swap_cr(dx, dy);
	//swap_cr(dx, dy);
	//cout << "dx = 7.7; dy = 9.9; after swap_cr(dx, dy): dx = " << x << " dy = " << y << endl;



	//Exercise 3
	X::var = 7;
	X::print();
	using namespace Y;
	var = 9;
	print();
	{
		using Z::var;
		using Z::print;
		var = 11;
		print();
	}
	print();
	X::print();

}


