/**
 * Classe héritant de Graphe permettant de représenter
 * un graphe sous la forme d'une matrice d'adjacence.
 */

#ifndef MATRICEADJACENCE_H
#define MATRICEADJACENCE_H

#include <vector>

#include "Sommet.h"
#include "Arc.h"
#include "Graphe.h"

class MatriceAdjacence : public Graphe
{
	public:
		/**
		 * Constructeur par défaut de MatriceAdjacence.
		 */
		MatriceAdjacence();

		/**
		 * Affiche une matrice d'adjacence sur la sortie standard.
		 *
		 * @param ost Une sortie standard.
		 */
		virtual void affiche(std::ostream& ost) const override;

	private:
		std::vector< std::vector<int> > d_adjacence;
		std::vector<Sommet> d_sommets;
		std::vector<Arc> d_arcs;
};

#endif
