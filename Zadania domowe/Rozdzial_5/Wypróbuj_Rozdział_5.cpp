#include "stdafx.h"
#include "Wypr�buj_Rozdzia�_5.h"


int area(int length, int width)
{
	//Calculates rectangle area
	//Initial conditions: length and width variables have to be positive
	//Final conditions: returns positive values which denotes area
	//if (length <= 0 || width <= 0) return -1; // For functions before exercise 5.10.1

	// Exercise 5.10.1 style
	if (length <= 0 || width <= 0) error("Warunek wst�pny funkcji area(). "); 
	int a = length * width;
	if(a<=0) error("Warunek ko�cowy funkcji area(). "); // Warunek wst�pny b�dzie niespe�noiny dla poprawnych du�ych liczb wej�ciowych np. area(1231243, 20001290), wtedy zostanie sprawdzony warunek ko�cowy
	return a;

}



void wyproboj_5_3_1()
{

	//int s1 = area(7;
	//int s2 = area(7);
	//Int s3 = area(7);
	//int s4 = area('7);
}


void wyproboj_5_3_2()
{

	//int x0 = arena(7);
	//int x1 = area(7);

	//int x2 = area(2 3);

	//cout << x1 << endl;

}

/**
Wypr�buj 5.5.3
*/

int framed_area(int x, int y)
{
	const int frame_width = 2;
	if (x - frame_width <= 0 || y - frame_width <= 0)
	{
		error("Argument funkcji area() wywo�anej przez framed_area() nie jest dodatni.");
	}
	return area(x - frame_width, y - frame_width);
}


int f(int x, int y, int z)
{
	int area1 = area(x, y);
	if (area1 <= 0) error("area1 - Pole powierzchni nie jest dodatnie.");

	//int area2 = framed_area(1, z); //Book's default value
	int area2 = framed_area(3, z);
	if (area2 <= 0) error("area2 - Pole powierzchni nie jest dodatnie.");

	int area3 = framed_area(y, z);
	if (area3 <= 0) error("area3 - Pole powierzchni nie jest dodatnie.");
	
	double ratio = double(area1 / area3);
	//double ratio = double(area1) / double(area3); //Corrected function
	if (ratio <= 0) error("Stosunek powierzachni nie jest dodatni.");

	cout << "area1: " << area1 << endl;
	cout << "area2: " << area2 << endl;
	cout << "area3: " << area3 << endl;
	cout << "ratio: " << ratio << endl;

	return area1;
		 

}


/**
Wypr�buj 5.6.3
*/


void wyproboj_5_6_3()
{

	error(" No catched exception");

	/**
	Handled exception
	
	try {

		vector<int> v = {23, 23, 1, 2, 3};
		int test = v[10];

		
	}
	catch (exception & e)
	{
		cout << "Error " << e.what() << endl;
	}
	*/
	
}

void wyproboj_5_7()
{
	/* Original values from the book
	double high_temp = 0;
	double low_temp = 0;

	//The lowest and the highest value, C style,
	//You ma need to #include <limits.h>
	double high_temp = DBL_MIN;
	double low_temp = DBL_MAX;
	*/

	vector<double> temps; //temperatury
	double temp = 0;
	double sum = 0;

	//The lowest and the highest value, C++ style, 
	//You ma need to #include <limits>
	//For numeric_limits<double>::min() program doesn't work properly, for some reason the value is positive
	double high_temp = numeric_limits<int>::min();
	double low_temp = numeric_limits<double>::max();;	
	

	while (cin >> temp)
	{
		temps.push_back(temp);
	}
	for (int i = 0; i < temps.size(); ++i)
	{
		if (temps[i] > high_temp) high_temp = temps[i];
		if (temps[i] < low_temp) low_temp = temps[i];
		sum += temps[i];
	}

	cout << "Najwy�sza tempetatura: " << high_temp << endl;
	cout << "Najni�sza tempetatura: " << low_temp << endl;
	cout << "�rednia tempetatura: " << sum/temps.size() << endl;
}




void wyproboj_5_10_1(int a, int b)
{

	cout << "Pole powierzchni prostok�ta o wymiarach: "<< a << " i " << b <<endl;
	cout << "Wynosi: " << area(a, b) << endl;

}