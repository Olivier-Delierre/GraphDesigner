#ifndef CONVERTISSEUR_H
#define CONVERTISSEUR_H

#include "FsAps.h"
#include "Listes.h"
#include "MatriceAdjacence.h"

class Convertisseur {
    public:
        static FsAps convertirEnFsAps(const Listes listes);

        /**
        * Renvoie le graphe stocke sous forme des vecteurs fs et aps a partir d'un graphe stocke sous forme de matrice d'adjacence
        *
        * @return un graphe sous la forme fs/aps.
        */
        static FsAps convertirEnFsAps(const MatriceAdjacence matriceAdjacence);

        /**
        * Renvoie le graphe stocke sous forme de matrice d'adjacencea partir d'un graphe stocke sous forme des vecteurs fs et aps
        *
        * @return un graphe sous la forme d'une matrice d'adjacence.
        */
        static MatriceAdjacence convertirEnMatriceAdjacence(const FsAps fsAps);

        static MatriceAdjacence convertirEnMatriceAdjacence(const Listes listes);

		static Listes convertirEnListes(const FsAps fsAps);

        static Listes convertirEnListes(const MatriceAdjacence matriceAdjacence);
};

#endif
