/**
 * Classe héritant de Graphe permettant de représenter
 * un graphe sous la forme de listes de sommets et d'arcs.
 */

#ifndef LISTES_H
#define LISTES_H

#include "Graphe.h"
#include "ListeSommets.h"

class Listes : public Graphe
{
	public:
		/**
		 * Constructeur par défaut de Listes.
		 */
		Listes();

		/**
		 * Affiche une Listes sur la sortie standard.
		 *
		 * @param ost Une sortie standard.
		 */
		virtual void affiche(std::ostream& ost) const override;

		/**
		* Méthode virtuelle pure qui renvoie le nombre de sommets du graphe.
		*
		* @return le nombre de sommets.
		*/
		virtual int nombreSommets() const override ;

	private:
		ListeSommets* d_principale;
};

#endif
