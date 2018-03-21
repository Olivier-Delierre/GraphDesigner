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
		 * Constructeur complet de FsAps.
		 */
		FsAps(const std::vector<int>& fs , const std::vector<int>& aps , const std::vector<Arc*> arcs , const std::vector<Sommet*>& sommets) ;

		/**
		 * Affiche un Fs Aps sur la sortie standard.
		 *
		 * @param ost Une sortie standard.
		 */
		void affiche(std::ostream& ost) const override;

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
		std::vector<Sommet*> sommets() const ;


		/**
		* Méthode virtuelle pure qui renvoie le nombre de sommets du graphe.
		*
		* @return le nombre de sommets.
		*/
		virtual int nombreSommets() const override ;

	private:
		std::vector<int> d_fs;
		std::vector<int> d_aps;
		std::vector<Arc*> d_arcs;
		std::vector<Sommet*> d_sommets;
};

#endif
