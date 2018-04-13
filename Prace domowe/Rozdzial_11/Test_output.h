#pragma once
#include "../stdafx.h"
#include "../std_lib_facilities_v2.h"


namespace Ex11
{

	void cwiczenia_11();
	void exercises_1_to_7();
	void exercise_8();
	void exercise_9();
	void exercise_10();

	void display_table( vector<string>& names_vec, vector<string>& surnames_vec,  vector<string>& phone_numbers_vec,  vector<string>& emails_vec);


	class Test_output
	{
	public:
		Test_output();
		~Test_output();

	private:
		int birth_year;
	};

}
