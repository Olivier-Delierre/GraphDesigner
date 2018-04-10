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

	// On redimensionne la matrice d'adjacence en lui augmentant la taille de une unit�.
	d_adjacence.resize(nouvelle_taille);
	for (unsigned int i = 0; i < nouvelle_taille; i++) {
		d_adjacence[i].resize(nouvelle_taille);
	}

	// On remplie la derni�re ligne de la matrice de pointeurs nuls.
	for (unsigned int index = 0; index < nouvelle_taille; index++)
	{
		d_adjacence[derniere_position][index] = nullptr;
	}

	// On remplie la derni�re colonne de la matrice de pointeurs nuls.
	for (unsigned int index = 0; index < nouvelle_taille - 1; index++) {
		d_adjacence[index][derniere_position] = nullptr;
	}
}

void MatriceAdjacence::ajouterArc(Arc* arc , int i , int j)
{
    if (i>0 && j>0 && i<=nombreSommets() && j<=nombreSommets())
        d_adjacence[i-1][j-1] = arc ;
}

void MatriceAdjacence::supprimerArc(int i , int j)
{
    if (i>0 && j>0 && i<=nombreSommets() && j<=nombreSommets())
    {
        delete d_adjacence[i-1][j-1] ;
        d_adjacence[i-1][j-1] = nullptr ;
    }
}

void MatriceAdjacence::affiche(std::ostream& ost) const
{
	ost << "(MA) Sommets : " ;
    for (int i=0 ; i<nombreSommets() ; i++)
    {
        sommets()[i]->affiche(ost) ;
        ost << ' ' ;
    }
    ost << std::endl << "Arcs : " << std::endl ;
	for (unsigned int ligne = 0; ligne < d_adjacence.size(); ligne++)
	{
		for (unsigned int colonne = 0; colonne < d_adjacence.size(); colonne++)
		{
			if(d_adjacence[ligne][colonne])
                ost << ligne+1 << "->" << colonne+1 << " (" << d_adjacence[ligne][colonne]->poids() << ")" << std::endl ;
		}
	}
}

void MatriceAdjacence::afficheMatrice(std::ostream& ost) const
{
    for (unsigned int ligne = 0; ligne < d_adjacence.size(); ligne++)
	{
		for (unsigned int colonne = 0; colonne < d_adjacence.size(); colonne++)
		{
            if (d_adjacence[ligne][colonne]!=nullptr)
                ost << 1 << " " ;
            else
                ost << 0 << " " ;
		}
		ost << std::endl ;
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

FsAps MatriceAdjacence::convertirEnFsAps() const
{
    std::vector<int> aps (0) ;
    std::vector<int> fs (0) ;
    std::vector<Arc*> arcs(0) ;

    for (int i=0 ; i<nombreSommets() ; i++)
    {
        aps.push_back(fs.size()) ;
        for (int j=0 ; j<nombreSommets() ; j++)
        {
            if (matrice()[i][j] != nullptr)
            {
                fs.push_back(j+1) ;
                arcs.push_back(matrice()[i][j]) ;
            }
        }
        fs.push_back(0) ;
        arcs.push_back(nullptr) ;
    }

    return FsAps{fs,aps,arcs,sommets()} ;
}

MatriceAdjacence MatriceAdjacence::convertirEnMatriceAdjacence() const
{
    return *this ;
}

Listes MatriceAdjacence::convertirEnListes() const
{
	return Listes();
}
