#ifndef GRAPHE_H
#define GRAPHE_H

#include <fstream>

class Arc ;

class Graphe
{
	public:
		/**
		 * Constructeur par défaut d'un Graphe.
		 */
		Graphe() = default ;

		/**
		 * Méthode virtuelle pure permettant d'afficher un Graphe
		 * sur une sortie standard.
		 *
		 * @param ost - Une sortie standard.
		 */
		virtual void affiche(std::ostream& ost) const = 0;

		/**
		* Méthode virtuelle pure qui renvoie le nombre de sommets du graphe.
		*
		* @return le nombre de sommets.
		*/
		virtual int nombreSommets() const = 0;

		/**
		 * Ajoute un arc au graphe courant, allant du sommet i au sommet j
		 * Si les index sont incorrects, la fonction ne fait rien.
		 *
		 * @param arc Un arc à ajouter.
		 * @param[in] i Le sommet de depart.
		 * @param[in] j Le sommet d'arrivee.
		 */
		virtual void ajouterArc(Arc* arc , int i , int j) = 0 ;

		/**
		 * Supprime l'arc (i,j) du graphe courant s'il existe.
		 *
		 * @param[in] i Le sommet de depart.
		 * @param[in] j Le sommet d'arrivee.
		 */
		virtual void supprimerArc(int i , int j) = 0 ;

		/**
		* Méthode qui réalise et affiche l'algorithme de calcul des distances d'un graphe
		*
		* @param ost - Une sortie standard.
		*/
		void distance(std::ostream ost) const ;

		/**
		* Méthode qui réalise et affiche l'algorithme de determination des rangs des sommets
		*
		* @param ost - Une sortie standard.
		*/
		void rangs(std::ostream ost) const ;

		/**
		* Méthode qui réalise et affiche l'algorithme de determination des CFC selon Tarjan
		*
		* @param ost - Une sortie standard.
		*/
		void Tarjan(std::ostream ost) const ;

		/**
		* Méthode qui réalise et affiche l'algorithme de resolution du probleme d'ordonnancement
		*
		* @param ost - Une sortie standard.
		*/
		void ordonnancement(std::ostream ost) const ;

		/**
		* Méthode qui réalise et affiche l'algorithme de calcul des plus courts chemin selon Djikstra
		*
		* @param ost - Une sortie standard.
		*/
		void Djikstra(std::ostream ost) const ;

		/**
		* Méthode qui réalise et affiche l'algorithme de calcul des distances d'un graphe
		*
		* @param ost - Une sortie standard.
		*/
		void Kruskal(std::ostream ost) const ;

		/**
		* Méthode qui réalise et affiche le codage de Prufer.
		*
		* @param ost - Une sortie standard.
		*/
		void Prufer(std::ostream ost) const ;

	private:
};

#endif
