#include "../include/Listes.h"

int Listes::nombreSommets() const
{
    int i=0 ;
    ListeSommets* crt = d_principale ;
    while (d_principale)
    {
        i++ ;
        crt = crt->d_suivant ;
    }
    return i ;
}
