#pragma once
#include "Melodii.h"
#include <vector>
#include <fstream>

class repo {
	vector<melodie> melodii;
public:

	repo(string fisier)
	{
		ifstream f(fisier);
		int a, d;
		string b, c;
		while (f >> a >> b >> c >> d)
		{
			melodie m(a, b, c, d);
			melodii.push_back(m);
		}
	}
};