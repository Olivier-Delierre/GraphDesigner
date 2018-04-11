#ifndef CHAINONSOMMET_H
#define CHAINONSOMMET_H

#include "ListeArcs.h"
#include "Sommet.h"

class ChainonSommet
{
public:
	/**
	* Constructeur de ChainonSommet.
	*/
	ChainonSommet(Sommet* s);

	/**
	*   Renvoie le sommet du chainon
	*
	* @returns le sommet du chainon.
	*/
	Sommet* sommet() const ;

	/**
     * Ajoute un arc au sommet courant, allant au sommet j
     *
     * @param arc Un arc à ajouter.
     * @param[in] j Le sommet d'arrivee.
     */
    void ajouterArc(Arc* arc , Sommet* j) ;

	friend class ListeSommets;
	friend class ChainonArc ;
	friend class ListeArcs ;

private:
	Sommet * d_info;
	ChainonSommet* d_suivant;
	ListeArcs* d_successeurs;
};

#endif
