#ifndef CHAINONARC_H
#define CHAINONARC_H

#include "Arc.h"
#include "Sommet.h"

class ChainonArc
{
public:
	/**
	 * Constructeur de ChainonArc
	 */
	ChainonArc(Arc* arc , ChainonArc* succ , Sommet* j);

    friend class ListeArcs ;
    friend class ChainonSommet ;
    friend class ListeSommets ;

private:
	Arc d_info;
	Sommet* d_successeur;
	ChainonArc* d_suivant;
};

#endif
