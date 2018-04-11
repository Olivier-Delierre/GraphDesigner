#include "../include/ChainonSommet.h"

ChainonSommet::ChainonSommet(Sommet* s) : d_info{s} , d_suivant{nullptr} , d_successeurs{nullptr}
{}

Sommet* ChainonSommet::sommet() const
{
    return d_info ;
}

void ChainonSommet::ajouterArc(Arc* arc , Sommet* j)
{
    ChainonArc* crt = d_successeurs->d_racine->d_suivant ;
    d_successeurs->d_racine->d_suivant = new ChainonArc{arc,crt,j} ;
}
