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

		/**
		 * Ajoute un arc au graphe courant, allant du sommet i au sommet j
		 * Si les index sont incorrects, la fonction ne fait rien.
		 *
		 * @param arc Un arc à ajouter.
		 * @param[in] i Le sommet de depart.
		 * @param[in] j Le sommet d'arrivee.
		 */
		virtual void ajouterArc(Arc* arc , int i , int j) override ;

		/**
		 * Supprime l'arc (i,j) du graphe courant s'il existe.
		 *
		 * @param[in] i Le sommet de depart.
		 * @param[in] j Le sommet d'arrivee.
		 */
		virtual void supprimerArc(int i , int j) override;

	private:
		ListeSommets* d_principale;
};

#endif
