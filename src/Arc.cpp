#include "../include/Arc.h"

Arc::Arc(double poids, std::string libelle) :
    d_poids{ poids },
    d_libelle{ libelle }
{}

Arc::Arc() :
    d_poids{ 0.0 },
    d_libelle{ "" }
{}

double Arc::poids() const
{
    return d_poids ;
}

std::string Arc::libelle() const
{
    return d_libelle ;
}
