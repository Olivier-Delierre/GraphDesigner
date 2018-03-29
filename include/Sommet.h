/**
 * Classe virtuelle pure permettant de représenter
 * les sommets d'un graphe.
 */

#ifndef SOMMET_H
#define SOMMET_H

#include <ostream>

class Sommet
{
	public:
		/**
		 * Constructeur avec comme paramètre un ID.
		 *
		 * @param id Un identifiant.
		 */
		Sommet(unsigned int id);

		/**
		 * Méthode virtuelle pure permettant d'afficher un Sommet
		 * sur une sortie standard.
		 *
		 * @param ost - Une sortie standard.
		 */
		virtual void affiche(std::ostream& ost) const = 0;



		unsigned int id() const ;

	private:
		/// Identifiant d'un sommet.
		unsigned int d_id;
};

#endif
