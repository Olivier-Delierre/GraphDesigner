/**
* Classe héritant de Sommet permettant de représenter
* un sommet identifier par un mot.
*/

#ifndef SOMMETMOT_H
#define SOMMETMOT_H

#include "Sommet.h"

#include <string>

class SommetMot : public Sommet
{
public:
	/**
	* Constructeur prenant comme paramètre l'identifiant ainsi que le nom
	* du Sommet.
	*
	* @param id Un identifiant ;
	* @param nom Un nom sous forme d'entier.
	*/
	SommetMot(unsigned int id, std::string nom);

	/**
	* Affiche un SommetMot sur la sortie standard.
	*
	* @param ost Une sortie standard.
	*/
	void affiche(std::ostream& ost) const override;
private:
	/// Num du sommet.
	std::string d_nom;
};

#endif
