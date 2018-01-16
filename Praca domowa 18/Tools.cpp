#include "stdafx.h"
#include "Tools.h"



string tolowercase(string tolower)
{
	for (int i = 0; i < tolower.length(); ++i)
	{
		if (tolower[i] < 97)
		{
			tolower[i] = tolower[i] + 32;
		}
	}

	return tolower;
}