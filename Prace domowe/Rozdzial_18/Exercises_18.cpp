#include "stdafx.h"
#include "Exercises_18.h"

namespace Ex18
{



	X glob(2);

	X copy(X a) { return a; } 

	X copy2(X a)
	{
		X aa = a;
		return aa;
	}

	X& ref_to(X& a) { return a; }

	X* make(int i)
	{
		X a(i);
		return new X(a);
	}


	void drill_1()
	{
		X loc(4);
		X loc2 = loc;
		loc = X(5);
		loc2 = copy(loc);// Two copies are made in case of assignment, one inside a copy() function and the second during an assignment operation (at least I think this is how it works) 
		loc2 = copy2(loc);
		X loc3(6);
		X& r = ref_to(loc);
		
		delete make(7); // Eqivalent of X* foo = make(7); delete foo;
		delete make(8);
		vector<X> v(4);
		XX loc4;
		X* p = new X(9);
		delete p;
		X* pp = new X[5];
		delete[] pp;

	}


	void drill_2()
	{
		vec::vector v(3);
		int x = v[2];
		v[1] = 5;
		cout << v[1] << endl;
	}




	/*
	Example output for
	delete make(7); 
	delete make(8);


		00F796A0-- > X(int) : 0 (2)
		Active code page : 1250
		00EFF5F4-- > X(int) : -858993460 (7)
		011811A8-- > X(X&) : -842150451 (7) // Why NOT the val = 7, but is still a random (not initialized) number = -842150451?!
		00EFF5F4-- > ~X() : 7 (0)
		011811A8-- > ~X() : 7 (0)
		00EFF5F4-- > X(int) : -858993460 (8)
		011811D8-- > X(X&) : -842150451 (8)
		00EFF5F4-- > ~X() : 8 (0)
		011811D8-- > ~X() : 8 (0)
	
	*/
	
}

namespace vec
{
	void vector::copy(const vector& v)
	{
		for (int i = 0; i < v.sz; ++i)
		{
			elem[i] = v.elem[i];
		}

	}
}
