#include "../include/ListeSommets.h"

ListeSommets::ListeSommets() : d_racine{nullptr} {}

int ListeSommets::nombreSommets() const
{
    ChainonSommet* crt = d_racine ;
    int nb = 0 ;
    while (d_racine)
    {
        nb++ ;
        crt = crt->d_suivant ;
    }
    return nb ;
}

void ListeSommets::affiche(std::ostream &ost) const
{
    ost << "(LISTE) Sommets : " ;
    ChainonSommet* crt = d_racine ;
    while (d_racine)
    {
        crt->sommet()->affiche(ost) ;
        ost << ' ' ;
        crt = crt->d_suivant ;
    }
    ost << std::endl << "Arcs : " << std::endl ;
    //TO DO

}

void ListeSommets::ajouterArc(Arc* arc , int i , int j)
{
    if (i>0 && j>0 && i<=nombreSommets() && j<=nombreSommets())
    {
        ChainonSommet* i_crt = d_racine ;
        for (int k=1 ; k<i ; k++)
        {
            i_crt = i_crt->d_suivant ;
        }
        ChainonSommet* j_crt = d_racine ;
        for (int k=1 ; k<j ; k++)
        {
            j_crt = j_crt->d_suivant ;
        }
        i_crt->ajouterArc(arc,j_crt->sommet()) ;
    }
}
