#include "stdafx.h"
#include "Exercises_17.h"


namespace Ex17
{
	ostream& print_array10(ostream& os, int* a) 
	{
		for (int i = 0; i < 10; ++i)
		{
			os << a[i] << endl;
		}
		return os;
	}

	ostream& print_array(ostream& os, int* a, int n)
	{
		for (int i = 0; i < n; ++i)
		{
			os << a[i] << endl;
		}
		return os;
	}

	ostream& print_vector(ostream& os, vector<int>& a)
	{
		for (int i = 0; i < a.size(); ++i)
		{
			os << a[i] << endl;
		}
		return os;
	}


	void ex1_2_3()
	{
		int* ex1 = new int[10];
		for (int i = 0; i < 10; ++i)
		{
			cout << ex1[i] << endl;
		}
		delete[] ex1;
	}

	void ex4()
	{
		int* ex4 = new int[10];
		print_array10(cout, ex4);
		delete[] ex4;
	}

	void initialize(int n)
	{
		int* init = new int[n];
		for (int i = 0; i < n; ++i)
		{
			init[i] = 100 + i;
		}
		print_array(cout, init,n);
		delete[] init;
	}

	void initialize_vector(int n)
	{
		vector<int> ex10(n);
		for (int i = 0; i < n; ++i)
		{
			ex10[i] = 100 + i;
		}
		print_vector(cout, ex10);
	}


	void ex5()
	{
		initialize(10);
	}

	void ex6()
	{
		initialize(11);
	}

	void ex8()
	{
		initialize(20);
	}

	void ex10()
	{
		initialize_vector(10);
		initialize_vector(11);
		initialize_vector(20);
	}

	void cwiczenia_17_part1()
	{
		//ex1_2_3();
		//ex4();
		//ex5();
		//ex6();
		//ex8();
		ex10();
	}


	void ex1_2_p2()
	{
		int p = 7;
		int* p1 = &p;
		cout << "p1 = " << p1 << ", *p1 = " << *p1 << endl;
	}


	void ex3_to_9_p2()
	{
		const int array_size = 7;
		int* p1 = new int[array_size];
		int to_pow_of_2 = 1;
		for (int i = 0; i < array_size; ++i)
		{
			p1[i] = to_pow_of_2;
			to_pow_of_2 *= 2;
		}
		int* p2 = p1;
		cout << "p2 = " << p2 << endl;
		print_array(cout, p2, array_size);
		int* p3 = p2;
		p1 = p2;
		p3 = p2;
		cout << "p1 = " << p1 << ", *p1 = " << *p1 << endl;
		cout << "p2 = " << p2 << ", *p2 = " << *p2 << endl;

		delete[] p1;
		
	}

	void copy_array(int* p1, int* p2, int size)
	{
		for (int i = 0; i < size; ++i)
		{
			p2[i] = p1[i];
		}
	}


	void ex10_to_12_p2()
	{
		const int array_size = 10;
		int* p1 = new int[array_size];
		int to_pow_of_2 = 1;
		for (int i = 0; i < array_size; ++i)
		{
			p1[i] = to_pow_of_2;
			to_pow_of_2 *= 2;
		}
		int* p2 = new int[array_size];
		copy_array(p1, p2, array_size);
		print_array(cout, p2, array_size);
		delete[] p1;
		delete[] p2;
	}

	void copy_vector(vector<int>& p1, vector<int>& p2)
	{
		for (int i = 0; i < p1.size(); ++i)
		{
			p2[i] = p1[i];
		}
	}

	void ex12_p2()
	{
		const int array_size = 10;
		vector<int> p1(array_size);
		int to_pow_of_2 = 1;
		for (int i = 0; i < array_size; ++i)
		{
			p1[i] = to_pow_of_2;
			to_pow_of_2 *= 2;
		}
		vector<int> p2(array_size);
		copy_vector(p1, p2);

		cout << "vector p1" << endl;
		print_vector(cout, p1);
		cout << endl;
		cout << "vector p2" << endl;
		print_vector(cout, p2);
		
	}



	void cwiczenia_17_part2()
	{
		//ex1_2_p2();
		//ex3_4_p2();
		//ex3_to_9_p2();
		//ex10_to_12_p2();
		//ex12_p2();
	}


}