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

FsAps::FsAps(const std::vector<int>& fs , const std::vector<int>& aps , const std::vector<Sommet*>& sommets) :
    d_fs(fs),
	d_aps(aps),
	d_arcs(fs.size()),
	d_sommets(sommets)
{
    for (int i=0 ; i<fs.size() ; i++)
    {
        if (fs[i]==0)
        {
            d_arcs[i] = nullptr;
        }
        else
        {
            d_arcs[i] = new Arc() ;
        }
    }
}

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
    ost << "Sommets : " ;
    for (int i=0 ; i<nombreSommets() ; i++)
    {
        sommets()[i]->affiche(ost) ;
        ost << ' ' ;
    }
    ost << std::endl << "Arcs : " ;
    for (int i=0 ; i<d_aps.size() ; i++)
    {
        for (int j=d_aps[i] ; d_fs[j]!=0 ; j++)
        {
            ost << i+1 << "->" << d_fs[j] << " (" << d_arcs[j]->poids() << ")" << std::endl ;
        }
    }
}
