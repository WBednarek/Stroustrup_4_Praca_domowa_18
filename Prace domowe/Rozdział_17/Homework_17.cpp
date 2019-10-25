#include "stdafx.h"
#include "Homework_17.h"


namespace Hw17
{

	void hw_1_2()
	{
		int num = 9;
		int* a = &num;
		cout << "a = " << a << ", *a = " << *a << endl;

		double dbl = 4.3534;
		double* ptr_dbl = &dbl;
		bool bol = true;
		bool* ptr_bool = &bol;

		cout << "Size of a int pointer: " << sizeof(a) << endl;
		cout << "Size of a double pointer: " << sizeof(dbl) << endl;
		cout << "Size of a bool pointer: " << sizeof(ptr_bool) << endl;
	}

	void to_lower(char* s)
	{
		// ASCII a = 97, where ASCII A = 65
		const int a = 97;
		const int A = 65;
		const int diff = a - A;
		const int Z = 90; //the last numerical sign of big characters

		int i = 0;
		while (s[i] != 0)
		{
			if (s[i] >= A && s[i] <= Z)
			{
				s[i] += diff;
			}
			++i;
		}


	}

	ostream& print_array(ostream& os, const char* arr)
	{
		int i = 0;
		while (1)
		{
			if (arr[i])
			{
				os << arr[i];
				++i;
			}
			else
			{
				break;
			}
		}

		return os;
	}
	
	void hw3()
	{
		char communicate[] = "Witaj Swiecie OOSDFASCQEEQW2!";
		to_lower(communicate);
		print_array(cout, communicate);
	}

	int get_array_len(const char* arr)
	{
		int length = 0;
		while (arr[length]) // eqivalent of (arr[length] != 0)
		{
			++length;
		}
		return length;
	}

	char* strup(const char* arr)
	{
		int array_length = get_array_len(arr);
		char* stack_array = new char[array_length];
		for (int i = 0; i < array_length+1; ++i) // +1 since we need to catch 0 at the on of array
		{
			stack_array[i] = arr[i];
		}

		return stack_array;
	}

	const char* findx(const char* s, const char* x)
	{
		int s_length = get_array_len(s);
		int x_length = get_array_len(x);
		if (s_length < x_length) error("array of cahracters to find in longer than array where it is looked for");
		int diff_len = s_length - x_length;
		char* x_ptr = 0;

		

		const char* nope = "The phrase is not in the following text";

		for (int i = 0; i <= diff_len; ++i) //diff_len = 3
		{
			for (int j = 0; j < x_length; ++j)
			{
				if (x[j] != s[j + i])
				{
					break;
				}
				else if(j == x_length-1)
				{
					return &s[i];
				}

			}
			
		}
		return nope;
	}


	void hw4()
	{
		char sr[] = "THIS 2413412 #@$##@r312R";
		char* ex4_array = strup(sr);
		print_array(cout, ex4_array);
	}

	void hw5()
	{
		char base[] = "witaj swiecie";
		char to_find[] = "iec";

		int x_length = get_array_len(to_find);
		int s_length = get_array_len(base);
		int diff_len = s_length - x_length;
		const char* pos = findx(base, to_find);
		cout << "The phare to search is: " << to_find << endl;
		cout << "From the firts occurance of searched phrase to the end of string where is was searched, the string is the following: " << endl;;
		print_array(cout, pos);
		cout << endl;
		cout << "The first occurance of the searched phrase has address: " << &pos << endl;
		cout << "And the letter that it starts is: " << *pos << endl;

	}

	void homework_17()
	{
		//hw_1_2();
		//hw3();
		//hw4();
		hw5();
	}

}
