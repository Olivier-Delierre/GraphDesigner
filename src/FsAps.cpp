#include "../include/FsAps.h"
#include <iostream>



FsAps::FsAps() :
	d_fs(0),
	d_aps(0),
	d_arcs(0),
	d_sommets(0)
{}

void FsAps::ajouterSommet(Sommet * sommet)
{
}

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
    for (unsigned int i=0 ; i<fs.size() ; i++)
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

void FsAps::ajouterArc(Arc* arc , int i , int j)
{
    if (i>0 && j>0 && i<=nombreSommets() && j<=nombreSommets())
    {
        unsigned int k = d_aps[i-1] ;
        while (k<d_fs.size() && d_fs[k]<j)
            k++ ;
        if (d_fs[k]!=j)
        {
            d_fs.resize(d_fs.size()+1) ;

            // DECALAGE DU TABLEAU FS et ARCS
            for (unsigned int l=d_fs.size() ; l>k ; l--)
            {
                d_fs[l] = d_fs[l-1] ;
                d_arcs[l] = d_arcs[l-1] ;
            }
            d_fs[k] = j ;
            d_arcs[k] = arc ;

            // MISE A JOUR DE APS
            for (unsigned int l=i ; l<d_aps.size() ; l++)
                d_aps[l]++ ;
        }
    }
}

void FsAps::supprimerArc(int i , int j)
{
    if (i > 0 && j > 0 && i <= nombreSommets() && j <= nombreSommets())
    {
        unsigned int k = d_aps[i - 1];

		while (k < d_fs.size() && d_fs[k] != j)
		{
			k++;
		}

        if (d_fs[k] == j)
        {
            // DECALAGE DU TABLEAU FS et ARCS
            for (unsigned int l = k; l < d_fs.size() - 1; l++)
            {
                d_fs[l] = d_fs[l + 1] ;
                d_arcs[l] = d_arcs[l + 1] ;
            }
            d_fs.pop_back() ;
            delete d_arcs.back() ;
            d_arcs.pop_back() ;

            // MISE A JOUR DE APS
            for (unsigned int l = i; l < d_aps.size(); l++)
                d_aps[l]-- ;
        }
    }
}

void FsAps::affiche(std::ostream& ost) const
{
    ost << "(FS APS) Sommets : " ;
    for (int i=0 ; i<nombreSommets() ; i++)
    {
        sommets()[i]->affiche(ost) ;
        ost << ' ' ;
    }
    ost << std::endl << "Arcs : " << std::endl ;
    for (unsigned int i=0 ; i<d_aps.size() ; i++)
    {
        for (unsigned int j=d_aps[i] ; d_fs[j]!=0 ; j++)
        {
            ost << i+1 << "->" << d_fs[j] << " (" << d_arcs[j]->poids() << ")" << std::endl ;
        }
    }
}

bool FsAps::estPredecesseur(int i, int j) const
{
	int k = d_aps[i - 1];
	int nextZero;

	if ((i - 1) == d_aps.size() - 1)
	{
		nextZero = d_fs.size();
	}
	else
	{
		nextZero = d_aps[i];
	}

	while (k < nextZero && d_fs[k] != j)
	{
		k++;
	}

	return !(k == nextZero);
}


FsAps FsAps::convertirEnFsAps() const
{
    return *this ;
}


MatriceAdjacence FsAps::convertirEnMatriceAdjacence() const
{
    std::vector<std::vector<Arc*> > matrice(nombreSommets(),std::vector<Arc*>(nombreSommets(),0)) ;
    int i=0 ;
    for(unsigned int j=0 ; j<fs().size() ; j++)
    {
        if (fs()[j]==0)
        {
            i++ ;
        }
        else
        {
            matrice[i][fs()[j]-1] = arcs()[j] ;
        }
    }

    std::vector<Sommet*> s = sommets() ;

    return MatriceAdjacence{matrice,s} ;
}

Listes FsAps::convertirEnListes() const
{
	return Listes();
}



