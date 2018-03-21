#include "../include/Convertisseur.h"

FsAps Convertisseur::convertirEnFsAps(const MatriceAdjacence matriceAdjacence) const
{
    std::vector<int> aps (matriceAdjacence.sommets().size()) ;
    std::vector<int> fs (0) ;

    for (int i=0 ; i<matriceAdjacence.nombreSommets() ; i++)
    {
        for (int j=0 ; j<matriceAdjacence.nombreSommets() ; j++)
        {
            if (matriceAdjacence.matrice()[i][j] == 1)
            {
                fs.push_back(j) ;
            }
            fs.push_back(0) ;
        }
    }

    return FsAps{fs,aps,matriceAdjacence.arcs(),matriceAdjacence.sommets()} ;
}

MatriceAdjacence Convertisseur::convertirEnMatriceAdjacence(const FsAps fsAps) const
{
    std::vector<std::vector<int> > matrice(fsAps.nombreSommets(),std::vector<int>(fsAps.nombreSommets(),0)) ;
    int i=0 ;
    for(int j=0 ; j<fsAps.fs().size() ; j++)
    {
        if (fsAps.fs()[j]==0)
        {
            i++ ;
        }
        else
        {
            matrice[i][fsAps.fs()[j]] = 1 ;
        }
    }

    return MatriceAdjacence{matrice,fsAps.sommets(),fsAps.arcs()} ;
}
