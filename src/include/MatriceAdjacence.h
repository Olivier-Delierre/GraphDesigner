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
		* Constructeur complet de MatriceAdjacence
		*/
		MatriceAdjacence(std::vector< std::vector<int> > adjacence , std::vector<Sommet*> sommets , std::vector<Arc*> arcs) ;

		/**
		 * Ajoute un sommet à la matrice d'adjacence courante,
		 * et redimensionne en conséquence celle-ci.
		 *
		 * @param sommet Un sommet à ajouter.
		 */
		void ajouterSommet(Sommet* sommet);

		/**
		 * Ajoute un arc à la matrice d'adjacence courante.
		 *
		 * @param arc Un arc à ajouter.
		 */
		void ajouterArc(Arc* arc);

		/**
		 * Affiche une matrice d'adjacence sur la sortie standard.
		 *
		 * @param ost Une sortie standard.
		 */
		virtual void affiche(std::ostream& ost) const override;

		/**
		* Retourne le tableau des arcs.
        *
        * @return un vecteur d'arcs.
		*/
		std::vector<Arc*> arcs() const ;

		/**
		* Retourne le tableau des sommets.
        *
        * @return un vecteur de pointeur vers sommets.
		*/
		std::vector<Sommet*> sommets() const ;

		/**
		* Retourne la matrice d'adjacence
        *
        * @return un tableau à deux dimensions d'entiers.
		*/
		std::vector< std::vector<int> > matrice() const ;

        /**
		* Méthode virtuelle pure qui renvoie le nombre de sommets du graphe.
		*
		* @return le nombre de sommets.
		*/
        virtual int nombreSommets() const override ;

	private:
		std::vector< std::vector<int> > d_adjacence;
		std::vector<Sommet*> d_sommets;
		std::vector<Arc*> d_arcs;
};

#endif
