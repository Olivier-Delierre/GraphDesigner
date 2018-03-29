#include "../include/MatriceAdjacence.h"

MatriceAdjacence::MatriceAdjacence() :
	d_adjacence(0, std::vector<Arc*>(0)),
	d_sommets(0)
{}

MatriceAdjacence::MatriceAdjacence(std::vector< std::vector<Arc*> > adjacence , std::vector<Sommet*> sommets) :
    d_adjacence(adjacence),
	d_sommets(sommets)

{}

void MatriceAdjacence::ajouterSommet(Sommet* sommet)
{
	unsigned int nouvelle_taille{ d_adjacence.size() + 1 };
	unsigned int derniere_position{ nouvelle_taille - 1 };

	d_sommets.push_back(sommet);

	// On redimensionne la matrice d'adjacence en lui augmentant la taille de une unité.
	d_adjacence.resize(nouvelle_taille);
	for (int i = 0; i < nouvelle_taille; i++) {
		d_adjacence[i].resize(nouvelle_taille);
	}

	// On remplie la dernière ligne de la matrice de pointeurs nuls.
	for (unsigned int index = 0; index < nouvelle_taille; index++)
	{
		d_adjacence[derniere_position][index] = nullptr;
	}

	// On remplie la dernière colonne de la matrice de pointeurs nuls.
	for (unsigned int index = 0; index < nouvelle_taille - 1; index++) {
		d_adjacence[index][derniere_position] = nullptr;
	}
}

void MatriceAdjacence::affiche(std::ostream& ost) const
{
	for (unsigned int ligne = 0; ligne < d_adjacence.size(); ligne++)
	{
		for (unsigned int colonne = 0; colonne < d_adjacence.size(); colonne++)
		{
			if(d_adjacence[ligne][colonne])
                ost << ligne+1 << "->" << colonne+1 << " (" << d_adjacence[ligne][colonne]->poids() << ")" << std::endl ;
		}
	}
}

std::vector< std::vector<Arc*> > MatriceAdjacence::matrice() const
{
    return d_adjacence ;
}

std::vector<Sommet*> MatriceAdjacence::sommets() const
{
    return d_sommets ;
}

int MatriceAdjacence::nombreSommets() const
{
    return d_adjacence.size() ;
}
