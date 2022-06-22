#pragma once
#include "Melodii.h"
#include <vector>
#include <fstream>

class repo {
	vector<melodie> melodii;
	string fisier;
public:

	repo(string fisier_)
	{
		fisier = fisier_;
		ifstream f(fisier);
		int a, d;
		string b, c;
		while (f >> a >> b >> c >> d)
		{
			melodie m(a, b, c, d);
			melodii.push_back(m);
		}

		bool ok = true;
		while (ok)
		{
			ok = false;
			for (int i = 0; i < melodii.size() - 1; i++)
				if (melodii[i].rank > melodii[i + 1].rank)
				{
					melodie aux = melodii[i];
					melodii[i] = melodii[i + 1];
					melodii[i + 1] = aux;
					ok = true;
				}
		}
	}

	void Sorteaza_Lista()
	{
		bool ok = true;
		while (ok)
		{
			ok = false;
			for (int i = 0; i < melodii.size() - 1; i++)
				if (melodii[i].rank > melodii[i + 1].rank)
				{
					melodie aux = melodii[i];
					melodii[i] = melodii[i + 1];
					melodii[i + 1] = aux;
					ok = true;
				}
		}

		/// scriem inapoi in fisier
		ofstream g(fisier);
		for (auto& x : melodii)
			g << x.id << " " << x.titlu << " " << x.artist << " " << x.rank << endl;
	}

	vector<melodie> get_list()
	{
		return melodii;
	}

	void modifica(int id,int rank_nou,string titlu_nou)
	{
		for (auto& x : melodii)
			if (x.id == id)
			{
				x.titlu = titlu_nou;
				x.rank = rank_nou;
				break;
			}
		
	}


	string sterge(int id)
	{
		string autor;
		int ind = -1;
		for (int i=0;i<melodii.size();i++)
			if (melodii[i].id == id)
			{
				autor = melodii[i].artist;
				ind = i;
				break;
			}

		int count = 0;
		for (auto& x : melodii)
			if (x.artist == autor)
				count++;

		if (count > 1)
		{
			for (int i = ind; i < melodii.size() - 1; i++)
				melodii[i] = melodii[i + 1];
			
			melodii.pop_back();

			return "";
		}
		
		return "LAST_SONG";
	}
};