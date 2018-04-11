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

		/**
		 * Renvoie le nombre de sommets de la liste.
         *
         * @returns le nombre de sommets.
		 */
		int nombreSommets() const ;

		/**
		 * Affiche une Listes sur la sortie standard.
		 *
		 * @param ost Une sortie standard.
		 */
		void affiche(std::ostream &ost) const ;

		/**
		 * Ajoute un arc au graphe courant, allant du sommet i au sommet j
		 * Si les index sont incorrects, la fonction ne fait rien.
		 *
		 * @param arc Un arc à ajouter.
		 * @param[in] i Le sommet de depart.
		 * @param[in] j Le sommet d'arrivee.
		 */
		void ajouterArc(Arc* arc , int i , int j) ;

		friend class Listes ;

	private:
		ChainonSommet *d_racine;
};

#endif
