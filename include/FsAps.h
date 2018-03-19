/**
 * Classe héritant de Graphe permettant de représenter
 * un graphe sous la forme Fs Aps.
 */

#ifndef FSAPS_H
#define FSAPS_H

#include <vector>

#include "Sommet.h"
#include "Arc.h"
#include "Graphe.h"

class FsAps : public Graphe
{
	public:
		/**
		 * Constructeur par défaut de FsAps.
		 */
		FsAps();

		/**
		 * Affiche un Fs Aps sur la sortie standard.
		 *
		 * @param ost Une sortie standard.
		 */
		virtual void affiche(std::ostream& ost) const override;

	private:
		std::vector<Sommet> d_fs;
		std::vector<int> d_aps;
		std::vector<Arc> d_arcs;
};

#endif
