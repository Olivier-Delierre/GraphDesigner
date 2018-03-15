#ifndef CONVERTISSEUR_H
#define CONVERTISSEUR_H

#include "FsAps.h"
#include "Listes.h"
#include "MatriceAdjacence.h"

class Convertisseur {
    public:
        FsAps convertirEnFsAps(const Listes listes) const;
        FsAps convertirEnFsAps(const MatriceAdjacence matriceAdjacence) const;

        MatriceAdjacence convertirEnMatriceAdjacence(const FsAps fsAps) const;
        MatriceAdjacence convertirEnMatriceAdjacence(const Listes listes) const;
        
		Listes convertirEnListes(const FsAps fsAps) const;
        Listes convertirEnListes(const MatriceAdjacence matriceAdjacence) const;
};

#endif