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
#include "FsAps.h"
#include "Listes.h"

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
		MatriceAdjacence(std::vector< std::vector<Arc*> > adjacence , std::vector<Sommet*> sommets) ;

		/**
		 * Ajoute un sommet à la matrice d'adjacence courante,
		 * et redimensionne en conséquence celle-ci.
		 *
		 * @param sommet Un sommet à ajouter.
		 */
		void ajouterSommet(Sommet* sommet);

		/**
		 * Ajoute un arc à la matrice d'adjacence courante, allant du sommet i au sommet j
		 * Si les index sont incorrects, la fonction ne fait rien.
		 *
		 * @param arc Un arc à ajouter.
		 * @param[in] i Le sommet de depart.
		 * @param[in] j Le sommet d'arrivee.
		 */
		virtual void ajouterArc(Arc* arc , int i , int j) override ;

		/**
		 * Supprime l'arc (i,j) de la matrice d'adjacence courante s'il existe.
		 *
		 * @param[in] i Le sommet de depart.
		 * @param[in] j Le sommet d'arrivee.
		 */
		virtual void supprimerArc(int i , int j) override;

		/**
		 * Affiche une matrice d'adjacence sur la sortie standard, sous la forme d'une liste d'arcs.
		 *
		 * @param ost Une sortie standard.
		 */
		virtual void affiche(std::ostream& ost) const override;

		/**
		 * Affiche une matrice d'adjacence sur la sortie standard.
		 *
		 * @param ost Une sortie standard.
		 */
		void afficheMatrice(std::ostream& ost) const ;

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
		std::vector< std::vector<Arc*> > matrice() const ;

        /**
		* Méthode virtuelle pure qui renvoie le nombre de sommets du graphe.
		*
		* @return le nombre de sommets.
		*/
        virtual int nombreSommets() const override ;

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

		void Dijkstra(std::ostream ost) const ;

	private:
		std::vector< std::vector<Arc*> > d_adjacence;
		std::vector<Sommet*> d_sommets;
};

#endif
