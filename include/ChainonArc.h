#ifndef CHAINONARC_H
#define CHAINONARC_H

#include "Arc.h"
#include "Sommet.h"

class ChainonArc
{
public:
	/**
	 * Constructeur par défaut de ChainonArc
	 */
	ChainonArc();

private:
	Arc d_info;
	Sommet* d_successeur;
	ChainonArc* d_suivant;
};

#endif
