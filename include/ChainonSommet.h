#ifndef CHAINONSOMMET_H
#define CHAINONSOMMET_H

#include "ListeArcs.h"
#include "Sommet.h"

class ChainonSommet
{
public:
	/**
	* Constructeur par défaut de ChainonSommet.
	*/
	ChainonSommet();

	friend class Listes;

private:
	Sommet * d_info;
	ChainonSommet* d_suivant;
	ListeArcs* d_successeurs;
};

#endif
