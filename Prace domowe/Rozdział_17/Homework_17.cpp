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

	void hw6()
	{
		long long num_to_allocate = 122337203;
		long long ll_size = sizeof(long long);
		
		cout << "long long size is: " << ll_size<< endl; 
		long long allocated_num_size_kb = ll_size * num_to_allocate / 1000;
		cout << "allocated num size is: " << allocated_num_size_kb << " kb" << endl;

		long long allocated_num_size_gb = ll_size * num_to_allocate / 1000000000;
		cout << "allocated num size is: " << allocated_num_size_gb << " gb" << endl;
		
		/*long long w = LLONG_MAX;
		cout << "long long max is: " << w << endl;*/
		int i = 1;
		long long* a = new long long(num_to_allocate);
		/*while (1)
		{
			
			++i;
			if(i%100000 = )
		}*/

		//CTRL+ALT+ESC in windows to open task manager of you can see memory usage in the Visual studio
	}

	Link* Link::erase()
	{
		if (this == 0) return 0;
		if(succ) succ->prev = prev;// or this->succ->prev = prev;
		if(prev) prev->succ = succ;
		return succ;
	}

	Link* Link::find(const string& s)
	{
		Link* p = this;
		while (this)
		{
			if (p == 0) return 0;
			if (p->succ)
			{
				if (p->value == s) return p;
				p = p->succ;
			}
			else
			{
				break;
			}
		}
		while (this)
		{
			if (p == 0) return 0;
			if (p->prev)
			{
				if (p->value == s) return p;
				p = p->prev;
			}
			else
			{
				break;
			}
		}

		return 0;
	}

	Link* Link::find_rev(const string& s)
	{
		Link* p = this;
		while (this)
		{
			if (p == 0) return 0;
			if (p->value == s) return p;
			p = p->prev;
		}
		return 0;
	}

	
	Link* Link::move(int n) // not fully works
	{
		if (n < 0)
		{
			while (n++)// going left
			{
				//Borr, Freia, Odyn, Thor - moving Odyn
				if (prev == 0) return this;
				if (prev->prev)
				{
					prev->prev->succ = this; // Borr-> succ = Odyn
				}
				prev->succ = succ; //Freia-> succ = Thor
				Link* tmp = prev->prev; 
				prev->prev = this;
				if (succ)
				{
					succ->prev = prev; //!	Thor->prev = Freia
				}
				succ = prev;
				prev = tmp;
			}
		}

		if (n > 0)
		{
			while (n--)// going right
			{
				//Borr, Freia, Odyn, Thor - moving Freia
				if (succ == 0) return this;
				if (succ->succ)
				{
					succ->succ->prev = this; //Thor->prev = Freia
				}
				succ->prev = prev; //Odyn->prev = Borr
				Link* tmp = succ->succ;
				succ->succ = this;
				if (prev)
				{
					prev->succ = succ; //Borr-> succ = Odyn	
				}
				prev = succ;
				succ = tmp;
			}
		}


		return this;
	}

/*
		Link* p = this;
		if (p == 0) return 0;
		if (n > 0)
		{
			while (n--) // going right
			{
				if (p->succ == 0) return 0;
				if(p->prev == 0) 
				p->prev->succ = p->succ;
				p->succ->prev = p->prev;
				Link* tmp = p->succ->succ;
				p->succ->succ = p;
				p->prev = p->succ;
				p->succ = tmp;
				//delete tmp;



				Link* Link::insert(Link * n)
				{
					if (n == 0) return this;
					if (this == 0) return n;
					n->succ = this;
					if (prev) prev->succ = n;
					n->prev = prev;
					prev = n;
					return n;
				}

			}
		}

		*/




	Link* Link::advance(int n) 
	{
		Link* p = this;
		if (p == 0) return 0;
		if (n < 0)
		{
			while (n++)
			{
				if (p->prev == 0) return 0;
				p = p->prev;
			}
		}

		if (n > 0)
		{
			while (n--)
			{
				if (succ == 0) return 0;
				p = p->succ;
			}
		}

		return p;
	}	
	
	

	Link* advance1(Link* p, int n)
	{
		
		if (p == 0) return 0;
		if (0<n)
		{
			while (n--) // going right
			{
				if (p->next() == 0) return 0;
				p = p->next();
			}
		}
		if (n < 0)
		{
			while (n++)// going left
			{
				if (p->previous() == 0) return 0;
				p = p->previous();
			}
		}

		return p;
	}


	Link* Link::insert(Link* n)
	{
		if (n == 0) return this;
		if (this == 0) return n;
		n->succ = this;
		if (prev) prev->succ = n;
		n->prev = prev;
		prev = n;
		return n;
	}

	void print_all(Link* p)
	{
		cout << "{";
		while (p)
		{
			cout << p->value;
			if (p = p->next()) cout << ", ";
		}
		cout << "}";
	}


	Link* Link::add(Link* n)
	{
		if (n == 0) return this;
		if (this == 0) return n;
		n->prev = this;
		if (succ)
		{
			succ->prev = n;
		}	
		n->succ = succ;
		succ = n;

		return n;
	}


	void hw11()
	{
		Link* norse_gods = new Link("Thor");
		norse_gods = norse_gods->insert(new Link("Odyn"));
		norse_gods = norse_gods->insert(new Link("Zeus"));
		norse_gods = norse_gods->insert(new Link("Freia"));

		Link* greek_gods = new Link("Hera");
		greek_gods = greek_gods->add(new Link("Atena"));
		greek_gods = greek_gods->add(new Link("Mars"));
		greek_gods = greek_gods->add(new Link("Posejdon"));
		greek_gods = greek_gods->add(new Link("Atreus"));
		greek_gods = greek_gods->insert(new Link("Kratos")); // before Atreus
		

		Link* p = greek_gods->find("Mars");
		if (p) p->value = "Ares";

		Link* p2 = norse_gods->find("Zeus");
		if (p2)
		{
			if (p2 == norse_gods) norse_gods = p2->next();
			p2->erase();
			greek_gods = greek_gods->insert(p2);
		}
		

		Link* p3 = greek_gods->find("Atena");
		p3->move(22);
		
		greek_gods = greek_gods->find_rev("Hera"); // !!! THIS WAS IMPORTANT we need to show the beginning of a LIST
		////TO DO implement better find fucntion that goes forward and backward to find an element

		print_all(norse_gods);
		cout << endl;
		print_all(greek_gods);
		cout << endl;
	}


	void homework_17()
	{
		//hw_1_2();
		//hw3();
		//hw4();
		//hw5();
		//hw6();
		hw11(); //TO DO implement better find fucntion that goes forward and backward to find an element
	}	

	

}
