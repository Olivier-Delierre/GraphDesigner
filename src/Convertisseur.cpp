#include "../include/Convertisseur.h"

FsAps Convertisseur::convertirEnFsAps(const MatriceAdjacence matriceAdjacence)
{
    std::vector<int> aps (matriceAdjacence.sommets().size()) ;
    std::vector<int> fs (0) ;
    std::vector<Arc*> arcs(0) ;

    for (int i=0 ; i<matriceAdjacence.nombreSommets() ; i++)
    {
        for (int j=0 ; j<matriceAdjacence.nombreSommets() ; j++)
        {
            if (matriceAdjacence.matrice()[i][j] != nullptr)
            {
                fs.push_back(j) ;
                arcs.push_back(matriceAdjacence.matrice()[i][j]) ;
            }
            fs.push_back(0) ;
            arcs.push_back(nullptr) ;
        }
    }

    return FsAps{fs,aps,arcs,matriceAdjacence.sommets()} ;
}

MatriceAdjacence Convertisseur::convertirEnMatriceAdjacence(const FsAps fsAps)
{
    std::vector<std::vector<Arc*> > matrice(fsAps.nombreSommets(),std::vector<Arc*>(fsAps.nombreSommets(),0)) ;
    int i=0 ;
    for(int j=0 ; j<fsAps.fs().size() ; j++)
    {
        if (fsAps.fs()[j]==0)
        {
            i++ ;
        }
        else
        {
            matrice[i][fsAps.fs()[j]] = fsAps.arcs()[j] ;
        }
    }

    return MatriceAdjacence{matrice,fsAps.sommets()} ;
}
