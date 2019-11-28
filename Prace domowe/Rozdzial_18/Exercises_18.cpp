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

	

	void copy(int toCopy[], int second[], int size)
	{
		/*int size1 = sizeof(toCopy) / sizeof(toCopy[0]);
		int size2 = sizeof(second) / sizeof(second[0]);
		if (size1 != size2) error("Sizes of arrays mismatch!");*/
		for (int i = 0; i < size; ++i)
		{
			toCopy[i] = second[i];
		}
	}

	int ga[] = { 1,2,4,8,16,32,64,128,256,512};

	void print_array(int arr[], int size)
	{
	
		for (int i = 0; i < size-1; ++i)
		{
			cout << arr[i] << ", ";
		}
		cout << arr[size-1] << endl;
	}

	void f(int tab[], int size)
	{
		
		int la[10];
		copy(la, tab, size);
		print_array(la, size);
		int* p = new int[size];
		copy(p, tab, size);
		print_array(p, size);
		delete[] p;
	}

	void fill_array_with_fct(int to_fill[], int n)
	{
		if (n > 19) error("Factorial is too big");
		int fact = 1;
		to_fill[0] = fact;
		for (int i = 1; i < n; ++i)
		{
			fact *= i;
			to_fill[i] = fact;
		}
	}

	vector<int> fill_vector_with_fct(int n)
	{
		if (n > 19) error("Factorial is too big");
		vector<int> to_fill;
		int fact = 1;
		to_fill.push_back(fact);
		for (int i = 1; i < n; ++i)
		{
			fact *= i;
			to_fill.push_back(fact);
		}
		return to_fill;
	}
	

	vector<int> gv = { 1,2,4,8,16,32,64,128,256,512 };


	ostream& operator<<(ostream& os, vector<int>& vec)
	{
		for (int i = 0; i < vec.size()-1; ++i)
		{
			os << vec[i] << ", ";
		}
		os << vec[vec.size() - 1];
		return os;
	}

	void fv(vector<int> vec)
	{
		vector<int> lv(vec.size());
		lv = gv;
		cout << lv << endl;
		vector<int> lv2(vec);
		cout << lv2 << endl;
	}


	void exercise_1()
	{
		//-----------------
		//C-style array case

		//int size = 10;
		//f(ga, size);
		//int aa[10];
		//fill_array_with_fct(aa, 10);
		//f(aa, size);

		//-----------------
		//std::vector case
		//fv(gv);
		vector<int> vv = fill_vector_with_fct(10);
		fv(vv);
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
