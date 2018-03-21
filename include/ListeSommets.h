#ifndef LISTESOMMETS_H
#define LISTESOMMETS_H

#include "ListeArcs.h"
#include "Sommet.h"

class ListeSommets
{
	public:
		/**
		 * Constructeur par défaut de ListeSommets.
		 */
		ListeSommets();

		friend class Listes ;

	private:
		Sommet* d_info;
		ListeSommets* d_suivant;
		ListeArcs* d_successeurs;
};

#endif
