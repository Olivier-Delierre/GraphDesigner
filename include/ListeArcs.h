#ifndef LISTEARC_H
#define LISTEARC_H

#include "Arc.h"
#include "ChainonArc.h"
#include "Sommet.h"

class ListeArcs 
{
public:
	/**
	 * Constructeur par défaut de ListeArcs.
	 */
	ListeArcs();

	/**
	 * Fonction qui ajoute un arc vers un sommet dans la liste des arcs
	 *
	 * @param[in] info Un arc
	 * @param[in] successeur Un pointeur sur le sommet de l'arc
	 */
	void ajouter(ChainonArc *chainearc);

	/**
	 * Fonction qui supprime un arc vers un sommet dans la liste des arcs
	 *
	 * @param[in] info Un arc
	 * @param[in] successeur Un pointeur sur le sommet de l'arc
	 */
	void supprimer(ChainonArc *chainearc);

private:
	ChainonArc *racine;
};

#endif