#pragma once
#include <string>
using namespace std;

class melodie {
public:
	int id;
	string titlu, artist;
	int rank;

	melodie() {};

	melodie(int id1, string titlu1,string artist1,int rank1)
	{
		id = id1;
		titlu = titlu1;
		artist = artist1;
		rank = rank1;
	}
};