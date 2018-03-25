#ifndef LISTEARCS_H
#define LISTEARCS_H

#include "Arc.h"
#include "Sommet.h"

class ListeArcs
{
	public:
		/**
		 * Constructeur par défaut de ListeArcs
		 */
		ListeArcs();

        /**
		 * Fonction qui ajoute un arc vers un sommet dans la liste des arcs
		 *
		 * @param[in] info Un arc
		 * @param[in] successeur Un pointeur sur le sommet de l'arc
		 */
		void ajouter(Arc info, Sommet* successeur);

		/**
		 * Fonction qui supprime un arc vers un sommet dans la liste des arcs
		 *
		 * @param[in] info Un arc
		 * @param[in] successeur Un pointeur sur le sommet de l'arc
		 */
		void supprimer(Arc info, Sommet* successeur);

	private:
		Arc d_info;
		Sommet* d_successeur;
		ListeArcs* d_suivant;
};

#endif
