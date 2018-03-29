#include "../include/SommetNumero.h"
#include <iostream>

SommetNumero::SommetNumero(unsigned int id, int num) :
    Sommet{ id },
    d_num{ num }
{}

void SommetNumero::affiche(std::ostream& ost) const
{
    ost << d_num ;
}
