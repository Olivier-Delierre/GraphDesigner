#ifndef GRAPHE_H
#define GRAPHE_H

#include <fstream>
#include <vector>

class Arc ;
class MatriceAdjacence ;
class FsAps ;
class Listes ;
class Sommet;

class Graphe
{
	public:
		/**
		 * Constructeur par défaut d'un Graphe.
		 */
		Graphe() = default ;

		/**
		 * Destructeur virtuel
		 */
		virtual ~Graphe() = default ;

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
		void Dijkstra(std::ostream &ost) const ;

		/**
		* Méthode fusionnant deux composantes connexes
		*
		* @param i - La composante connexe du premier sommet
		* @param j - La composante connexe du second sommet
		* @param prem - Le tableau des premiers éléments de rang k
		* @param pilch - La pile chainée des sommets de l'ARM
		* @param cc - Le tableau des composantes connexes
		* @param nb - La composante connexe du premier sommet
		*/
		void fusion(int i, int j, std::vector<int>& prem, std::vector<int>& pilch, std::vector<int>& cc, std::vector<int>& nb) const;

		/**
		* Méthode de quickSort modifiée pour trier les arcs, les somemts de début et les sommets de Fin
		*
		* @param arcs - Le tableau des arcs
		* @param first - L'indice de début du quickSort
		* @param last - L'indice de fin du quickSort
		* @param somDeb - Le vecteur des indices des sommets de départ
		* @param SomFin - Le vecteur des indices des sommets d'arrivée
		*/
		void sortWithQuickSort(std::vector<Arc*>& arcs,int first, int last, std::vector<int> somDeb, std::vector<int> somFin) const;

		/**
		* Méthode qui détermine et affiche un arbre recouvrant minimal du graphe
		*
		* @param ost - Une sortie standard.
		*/
		void Kruskal(std::ostream& ost) const ;

		/**
		* Méthode qui réalise et affiche le codage de Prufer.
		*
		* @param ost - Une sortie standard.
		*/
		void Prufer(std::ostream &ost) const ;

		/**
		* Renvoie le graphe stocke sous forme des vecteurs fs et aps
		*
		* @return un graphe sous la forme fs/aps.
		*/
		virtual FsAps convertirEnFsAps() const = 0 ;

		/**
		* Renvoie le graphe stocke sous forme de matrice d'adjacence
		*
		* @return un graphe sous la forme d'une matrice d'adjacence.
		*/
		virtual MatriceAdjacence convertirEnMatriceAdjacence() const = 0 ;

		/**
		* Renvoie le graphe stocke sous forme de listes chainees
		*
		* @return un graphe sous la forme de listes chainees.
		*/
		virtual Listes convertirEnListes() const = 0 ;

		/**
		* Méthode virtuelle pure qui supprime un sommet du graphe
		*
		* @param s - le sommet à supprimer
		*/
		virtual void supprimerSommet(Sommet* s) = 0;

		/**
		* Méthode virtuelle pure qui ajoute un sommet du graphe
		*
		* @param s - le sommet à ajouter
		*/
		virtual void ajouterSommet(Sommet* s) = 0;


	private:

};

#endif
