#ifndef LISTESOMMETS_H
#define LISTESOMMETS_H

#include "ChainonSommet.h"

class ListeSommets
{
	public:
		/**
		 * Constructeur par défaut de ListeSommets.
		 */
		ListeSommets();

		friend class Listes ;

	private:
		ChainonSommet *racine;
};

#endif
