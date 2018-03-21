#ifndef LISTEARCS_H
#define LISTEARCS_H

#include "Arc.h"
#include "Sommet.h"

class ListeArcs
{
	public:
		/**
		 * Constructeur par défaut de ListeArcs
		 */ 
		ListeArcs();

	private:
		Arc d_info;
		Sommet* d_successeur;
		ListeArcs* d_suivant;
};

#endif
