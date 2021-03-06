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
#include "Listes.h"
#include "MatriceAdjacence.h"



class FsAps : public Graphe
{
	public:
		/**
		 * Constructeur par défaut de FsAps.
		 */
		FsAps();

        /**
		 * Destructeur virtuel
		 */
        virtual ~FsAps() = default ;

		/**
		* Ajoute un sommet à la matrice d'adjacence courante,
		* et redimensionne en conséquence celle-ci.
		*
		* @param sommet Un sommet à ajouter.
		*/
		virtual void ajouterSommet(Sommet* sommet) override;

		/**
		 * Constructeur complet de FsAps.
		 */
		FsAps(const std::vector<int>& fs , const std::vector<int>& aps , const std::vector<Arc*> arcs , const std::vector<Sommet*>& sommets) ;

		/**
		 * Constructeur sans arcs de FsAps (les poids seront nuls).
		 */
		FsAps(const std::vector<int>& fs , const std::vector<int>& aps , const std::vector<Sommet*>& sommets) ;

		/**
		 * Affiche un Fs Aps sur la sortie standard.
		 *
		 * @param ost Une sortie standard.
		 */
		void affiche(std::ostream& ost) const override;

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
		 * Retourne vrai si le sommet d'index i est un successeur du
		 * sommet d'index j.
		 *
		 * @param[in] i Le sommet de départ.
		 * @param[in] j Le sommet d'arrivée.
		 * @return vrai si i est prédecesseur de j, false sinon.
		 */
		bool estPredecesseur(int i, int j) const ;

		/**
		 * Supprime l'arc (i,j) du graphe courant s'il existe.
		 *
		 * @param[in] i Le sommet de depart.
		 * @param[in] j Le sommet d'arrivee.
		 */
		virtual void supprimerArc(int i , int j) override;

		/**
		* Retourne le tableau fs.
        *
        * @return un vecteur d'entier
		*/
		std::vector<int> fs() const ;

		/**
		* Retourne le tableau aps.
        *
        * @return un vecteur d'entier.
		*/
		std::vector<int> aps() const ;

		/**
		* Retourne le tableau des arcs.
        *
        * @return un vecteur de pointeurs d'arcs.
		*/
		std::vector<Arc*> arcs() const ;

		/**
		* Retourne la liste des sommets
        *
        * @return un vecteur de pointeurs de sommets;
		*/
		virtual std::vector<Sommet*> sommets() const override;

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

        virtual void supprimerSommet(Sommet* s) override ;

        virtual void ajouterSommet(Sommet* s) override ;

	private:
		std::vector<int> d_fs;
		std::vector<int> d_aps;
		std::vector<Arc*> d_arcs;
		std::vector<Sommet*> d_sommets;
};

#endif
