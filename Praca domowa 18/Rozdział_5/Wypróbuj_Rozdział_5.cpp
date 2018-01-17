#include "stdafx.h"
#include "Wypróbuj_Rozdzia³_5.h"


int area(int length, int width)
{
	if (length <= 0 || width <= 0) return -1;
	return length*width;
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

/*
Wypróbuj 5.5.3
*/
int framed_area(int x, int y)
{
	const int frame_width = 2;
	if (x - frame_width <= 0 || y - frame_width <= 0)
	{
		error("Argument funkcji area() wywo³anej przez framed_area() nie jest dodatni.");
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
	//double ratio = double(area1) / double(area3);
	if (ratio <= 0) error("Stosunek powierzachni nie jest dodatni.");

	cout << "area1: " << area1 << endl;
	cout << "area2: " << area2 << endl;
	cout << "area3: " << area3 << endl;
	cout << "ratio: " << ratio << endl;

	return area1;
		 

}