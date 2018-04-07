#include "../include/Sommet.h"

Sommet::Sommet(unsigned int id) :
    d_id{ id }
{}

unsigned int Sommet::id() const
{
    return d_id ;
}
