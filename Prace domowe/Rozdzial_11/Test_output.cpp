#include "stdafx.h"
#include "Test_output.h"

namespace Ex11
{

	Test_output::Test_output()
	{
	}


	Test_output::~Test_output()
	{
	}


	void cwiczenia_11() 
	{
		//Exercises (Ex) 1-7
		//exercises_1_to_7();

		//Ex 8
		//exercise_8();

		//Ex 9
		//exercise_9();

		//Ex 10
		exercise_10();

	}

	void exercises_1_to_7()
	{
		int birth_year = 1990;

		cout << showbase << endl;
		cout << "Birth year in formats:"
			<< "\ndecimal \t|" << birth_year
			<< "\noctal \t\t|" << oct << birth_year
			<< "\nhexadecimal \t|" << hex << birth_year
			<< endl;
		int my_age = 28;
		cout << "My age: \t|" << dec << my_age << endl;
	}

	void exercise_8()
	{
		int a = -2;
		int b = -3;
		int c = -22;
		int d = -343;
		cout << "WprowadŸ 4 liczby" << endl;
		cin >> a >> oct >> b >> hex >> c >> d;
		cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
	}

	void exercise_9()
	{

		double some_double = 1234567.89;
		cout << "Some doble in:" << endl
			<< "general representation \t" << some_double << endl
			<< "fixed representation \t" << fixed << some_double << endl
			<< "scientific representation \t" << scientific << some_double
			<< endl;

	}

	void exercise_10()
	{
		string names[] = { "Jan", "Alicja", "Maciek", "Tomasz", "Patryk", "Adrian" };
		vector<string> names_vec(names, names + sizeof(names) / sizeof(names[0]));

		string surnames[] = { "Omega", "Curus", "Tomaszewski", "Jarowski", "Vege", "Marcinowski" };
		vector<string> surnames_vec(surnames, surnames + sizeof(surnames) / sizeof(surnames[0]));

		string phone_numbers[] = { "56564155", "5435342", "2463212", "52315", "63246", "+48 6548956794" };
		vector<string> phone_numbers_vec(phone_numbers, phone_numbers + sizeof(phone_numbers) / sizeof(phone_numbers[0]));

		string emails[] = { "wgwegwf@wo.pl", "Alicj@wo.pl", "Maciek@wo.pl", "Tomasz@wo.pl", "Patryk@wo.pl", "adrian@wo.pl" };
		vector<string> emails_vec(emails, emails + sizeof(emails) / sizeof(emails[0]));


		display_table(names_vec, surnames_vec, phone_numbers_vec, emails_vec);
		

	}

	void display_table(const vector<string>& names_vec, const vector<string>& surnames_vec, const  vector<string>& phone_numbers_vec,const vector<string>& emails_vec)
	{
		const int table_width = 15;
		int size1, size2, size3, size4;
		size1 = names_vec.size();
		size2 = surnames_vec.size();
		size3 = phone_numbers_vec.size();
		size4 = emails_vec.size();
		if ( (size1 != size2) || (size2 != size3) || (size3 != size4))
		{
			error("Wrong sizes of inputet vectors in order to make an table");
		}
		cout  << "|" << left<< setw(table_width) << "Name" << "|" << setw(table_width) << "Surname" << "|" << setw(table_width) <<"Phone Number" << "|" << setw(table_width) << "Email" <<"|" << endl;


		for (int i = 0; i < names_vec.size(); ++i)
		{
			cout << "|" << left << setw(table_width) << names_vec[i] << "|" << setw(table_width) << surnames_vec[i] << "|" << setw(table_width) << phone_numbers_vec[i] << "|" << setw(table_width) << emails_vec[i] << "|" << endl;
		}

	}

}