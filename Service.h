#pragma once
#include "Repo.h"

class service {
	repo &Repo;
public:
	service(repo& rep) : Repo(rep){}

	void Sorteaza_Lista()
	{
		Repo.Sorteaza_Lista();
	}

	vector<melodie> get_list()
	{
		return Repo.get_list();
	}

	void modifica(int id, int rank, string titlu)
	{
		Repo.modifica(id, rank, titlu);
	}

	string sterge(int id)
	{
		return Repo.sterge(id);
	}
};