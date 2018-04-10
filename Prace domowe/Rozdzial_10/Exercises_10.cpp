#include "stdafx.h"
#include "Exercises_10.h"

namespace Ex10
{

	istream& operator >> (istream& is, Point_10& p)
	{
		char c;
		is >> c;


		/*
		is >> c >>p.x >> c >> p.y >> c;
		if (c != '(' || c != ',' || c != ')' || !isalnum(c))
	*/
		if (c != '(')
		{
			is.unget();
			is.clear(ios_base::failbit);
			//error("Points_10: wrong input, no '(' at the beginning");
		}

		is >> c;
		if (!isalnum(c))
		{
			is.unget();
			is.clear(ios_base::failbit);
			//error("Points_10: wrong input, x coordinate is no a number");
		}

		is.unget();
		is >> p.x;
		is >> c;
		if (c != ',')
		{
			is.unget();
			is.clear(ios_base::failbit);
			//error("Wrong format: missing comma ',' in (x,y) exected");
		}


		is >> c;
		if (!isalnum(c))
		{
			is.unget();
			cin.clear(ios_base::failbit);
			//error("Points_10: wrong input, y coordinate is no a number");
		}

		is.unget();
		is >> p.y;
		is >> c;
		if (c != ')')
		{
			is.unget();
			cin.clear(ios_base::failbit);
			//error("Wrong format: missing closing bracket ')' in (x,y) expected");
		}



		return is;
	}


	ifstream& operator >> (ifstream& is, vector<Point_10>& vec_p)
	{

		while (is)
		{
			char c;
			double x = 9999129;
			double y = 312332;

			is >> c;
			if (c != '(')
			{
				is.unget();
				is.clear(ios_base::failbit);
				//error("Points_10: wrong input, no '(' at the beginning");
				break;
			}

			is >> c;
			if (!isalnum(c))
			{
				is.unget();
				is.clear(ios_base::failbit);
				break;
				//error("Points_10: wrong input, x coordinate is no a number");
			}

			is.unget();
			is >> x;
			is >> c;
			if (c != ',')
			{
				is.unget();
				is.clear(ios_base::failbit);
				break;
				//error("Wrong format: missing comma ',' in (x,y) exected");
			}


			is >> c;
			if (!isalnum(c))
			{
				is.unget();
				is.clear(ios_base::failbit);
				break;
				//error("Points_10: wrong input, y coordinate is no a number");
			}

			is.unget();
			is >> y;
			is >> c;
			if (c != ')')
			{
				is.unget();
				is.clear(ios_base::failbit);
				break;
				//error("Wrong format: missing closing bracket ')' in (x,y) expected");
			}
			vec_p.push_back(Point_10(x, y));
		}


		return is;
	}

	ostream& operator<<(ostream& os, vector<Point_10>& points)
	{
		for (int i = 0; i < points.size(); ++i)
		{
			os << '(' << points[i].get_x() << ',' << points[i].get_y() << ')' << " ";
		}
		return os;
	}


	vector<Point_10> get_points(const string& communicate, const char termination)
	{

		vector<Point_10> points;

		Point_10 p;
		cout << communicate << endl;
		while (cin >> p) points.push_back(p);

		if (cin.eof()) return points;
		if (cin.bad()) error("Strumien Points_10 uszkodzony");
		if (cin.fail())
		{
			cin.clear();
			char c;
			cin >> c;
			if (c != termination)
			{
				cin.clear(ios_base::failbit);
			}
		}
		return points;
	}


	void clean_up_mess_10()
	{
		ignore_10(termination_sign());
	}

	void ignore_10(const char termination)
	{
		char c;
		cin.clear();
		while (cin >> c)
		{
			if (c == termination || c == '\n') return;
		}
		//cin.ignore(numeric_limits<int>::max(), '\n');
	}


	void cwiczenia_10()
	{

		/*

		cout << "Podaj nazwê pliku wejœciowego: ";
		string name;
		cin >> name;
		ifstream ist(name.c_str());
		if (!ist) error("Nie mo¿na otworzyæ pliku wejœiowego");
		*/
		vector<Point_10> original_points;
		original_points = get_points("Wpisz n elementów Point_10 w formacie (x,y)", termination_sign());

		cout << original_points << endl;
		save_inputted_data("mojedane.txt", original_points);

		vector<Point_10> points_to_read;
		points_to_read = read_inputted_data("mojedane.txt");

		cout << points_to_read << endl;

		compare_vectors(original_points, points_to_read);


	}

	void save_inputted_data(string filename, vector<Point_10>& input_data)
	{

		cout << "Zapisywanie danych do pliku: " << filename << endl;
		ofstream ost(filename.c_str());
		ost << input_data;
	}


	vector<Point_10> read_inputted_data(string filename)
	{
		vector<Point_10> input_data;
		cout << "Odczytywanie danych z pliku: " << filename << endl;
		ifstream ist(filename.c_str());
		ist >> input_data;

		return input_data;
	}

	void compare_vectors(vector<Point_10>& first, vector<Point_10>& second)
	{
		if (first.size() != second.size())
		{
			cout << "Coœ jest nie tak!" << endl;
			return;
		}
		for (int i = 0; i < first.size(); ++i)
		{
			if (first[i].get_x() != second[i].get_x())
			{
				cout << "Coœ jest nie tak!" << endl;
				return;
			}

			if (first[i].get_y() != second[i].get_y())
			{
				cout << "Coœ jest nie tak!" << endl;
				return;
			}
		}
	}

	const char& termination_sign()
	{
		const static char termiantion = ';';
		return termiantion;
	}


}