#include "../include/SommetMot.h"
#include <iostream>

SommetMot::SommetMot(unsigned int id, std::string nom) :
	Sommet{ id },
	d_nom{ nom }
{}

void SommetMot::affiche(std::ostream& ost) const
{
	ost << d_nom;
}
