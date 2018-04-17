/**
 * Classe héritant de Graphe permettant de représenter
 * un graphe sous la forme de listes de sommets et d'arcs.
 */

#ifndef LISTES_H
#define LISTES_H

#include "Graphe.h"
#include "ListeSommets.h"
#include "FsAps.h"
#include "MatriceAdjacence.h"

class Listes : public Graphe
{
	public:
		/**
		 * Constructeur par défaut de Listes.
		 */
		Listes();

		/**
		 * Destructeur virtuel
		 */
        virtual ~Listes() = default ;

		/**
		* Ajoute un sommet à la matrice d'adjacence courante,
		* et redimensionne en conséquence celle-ci.
		*
		* @param sommet Un sommet à ajouter.
		*/
		virtual void ajouterSommet(Sommet* sommet) override;

		virtual std::vector<Sommet*> sommets() const override;

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

		/**
        * Renvoie le graphe stocke sous forme des vecteurs fs et aps
        *
        * @return un graphe sous la forme fs/aps.
        */
        virtual FsAps convertirEnFsAps() const override ;

        /**
        * Renvoie le graphe stocke sous forme de matrice d'adjacence
        *
        * @return un graphe sous la forme d'une matrice d'adjacence.
        */
        virtual MatriceAdjacence convertirEnMatriceAdjacence() const override ;

        /**
        * Renvoie le graphe stocke sous forme de listes chainees
        *
        * @return un graphe sous la forme de listes chainees.
        */
        virtual Listes convertirEnListes() const override ;

        virtual void ajouterSommet(Sommet* s) override;

        virtual void supprimerSommet(Sommet* s) override;

	private:
		ListeSommets* d_principale;
};

#endif
