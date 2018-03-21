#ifndef CONVERTISSEUR_H
#define CONVERTISSEUR_H

#include "FsAps.h"
#include "Listes.h"
#include "MatriceAdjacence.h"

class Convertisseur {
    public:
        FsAps convertirEnFsAps(const Listes listes) const;

        /**
        * Renvoie le graphe stocke sous forme des vecteurs fs et aps a partir d'un graphe stocke sous forme de matrice d'adjacence
        *
        * @return un graphe sous la forme fs/aps.
        */
        FsAps convertirEnFsAps(const MatriceAdjacence matriceAdjacence) const;

        /**
        * Renvoie le graphe stocke sous forme de matrice d'adjacencea partir d'un graphe stocke sous forme des vecteurs fs et aps
        *
        * @return un graphe sous la forme d'une matrice d'adjacence.
        */
        MatriceAdjacence convertirEnMatriceAdjacence(const FsAps fsAps) const;

        MatriceAdjacence convertirEnMatriceAdjacence(const Listes listes) const;

		Listes convertirEnListes(const FsAps fsAps) const;

        Listes convertirEnListes(const MatriceAdjacence matriceAdjacence) const;
};

#endif
