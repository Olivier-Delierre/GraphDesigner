#include "../include/Listes.h"

Listes::Listes() : d_principale{nullptr}
{}

void Listes::ajouterSommet(Sommet * sommet)
{
}

std::vector<Sommet*> Listes::sommets() const
{
	return std::vector<Sommet*>();
}

void Listes::affiche(std::ostream& ost) const
{
    d_principale->affiche(ost) ;
}

int Listes::nombreSommets() const
{
	return d_principale->nombreSommets();
}

void Listes::ajouterArc(Arc* arc , int i , int j)
{
    d_principale->ajouterArc(arc,i,j) ;
}

void Listes::supprimerArc(int i , int j)
{

}

FsAps Listes::convertirEnFsAps() const
{
	return FsAps();
}

MatriceAdjacence Listes::convertirEnMatriceAdjacence() const
{
	return MatriceAdjacence();
}

Listes Listes::convertirEnListes() const
{
    return *this ;
}

