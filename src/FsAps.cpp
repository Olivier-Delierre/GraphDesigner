#include "../include/FsAps.h"
#include <iostream>

FsAps::FsAps() :
	d_fs(0),
	d_aps(0),
	d_arcs(0),
	d_sommets(0)
{}

FsAps::FsAps(const std::vector<int>& fs , const std::vector<int>& aps , const std::vector<Arc*> arcs , const std::vector<Sommet*>& sommets) :
    d_fs(fs),
	d_aps(aps),
	d_arcs(arcs),
	d_sommets(sommets)
{}

std::vector<int> FsAps::fs() const
{
    return d_fs ;
}

std::vector<int> FsAps::aps() const
{
    return d_aps ;
}

std::vector<Arc*> FsAps::arcs() const
{
    return d_arcs ;
}

std::vector<Sommet*> FsAps::sommets() const
{
    return d_sommets ;
}

int FsAps::nombreSommets() const
{
    return d_aps.size() ;
}

void FsAps::affiche(std::ostream& ost) const
{
    std::cout << "Sommets : " ;
    for (int i=0 ; i<nombreSommets() ; i++)
    {
        std::cout << sommets()[i] ;
    }
    std::cout << std::endl << "Arcs : " ;
    for (int i=0 ; i<d_aps.size() ; i++)
    {
        for (int j=d_fs[i] ; d_fs[j]!=0 ; i++)
        {
            std::cout << i << "->" << j << std::endl ;
        }
    }
}
