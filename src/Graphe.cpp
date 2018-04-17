#include "../include/Graphe.h"

#include "../include/FsAps.h"
#include <string>
#include <iostream>

void Graphe::rangs(std::ostream ost) const
{

}

void Graphe::distance(std::ostream ost) const
{
}

void Graphe::ordonnancement(std::ostream ost) const
{

}

void Graphe::Dijkstra(std::ostream &ost) const
{
	FsAps fsaps = this->convertirEnFsAps();

	std::vector<int> d(this->nombreSommets() + 1);
	std::vector<bool> isLocked(this->nombreSommets() + 1);
	std::vector<int> pred(this->nombreSommets() + 1);

	int s = 1;
	int S = this->nombreSommets() - 1;

	for (unsigned int i = 1; i <= this->nombreSommets(); i++)
	{
		// On initialise toutes les distances à l'infini (-1 pour le coup)
		d[i] = -1;
		pred[i] = 1;
	}

	// On initialise la distance du premier point à 0.
	d[1] = 0;

	// On fait boucler l'algorithme tant que S n'est pas vide.
	while (S > 0)
	{
		// On parcourt la liste des sommets.
		for (unsigned int i = 1; i <= this->nombreSommets(); i++)
		{
			// Si le sommet i n'est pas verouillé
			if (!isLocked[i] && fsaps.estPredecesseur(s, i))
			{
				// On calcule la distance entre le point s et le point i.
				int index_distance = fsaps.aps()[s - 1];
				while (fsaps.fs()[index_distance] != i) { index_distance++; }
				int distance = fsaps.arcs()[index_distance]->poids();

				int temporaire = d[s] + distance;

				if ((temporaire < d[i]) || (d[i] == -1))
				{
					d[i] = temporaire;
					pred[i] = s;
				}
			}
		}

		isLocked[s] = true;

		// On remplace maintenant s par l'indice le plus petit non vérouillé.
		// On récupère le premier sommet non vérouillé
		unsigned int i = 1;
		while (isLocked[i] || d[i] == -1) { i++; }

		// On cherche maintenant la plus petite valeur.
		unsigned int index_min = i;
		for (; i <= this->nombreSommets(); i++)
		{
			if (!isLocked[i] && (d[i] != -1) && d[i] < d[index_min])
			{
				index_min = i;
			}
		}

		s = index_min;

		// Puis on enlève un élément à S.
		S--;
	}

	ost << "Résultat de Dijkstra : " << std::endl;

	ost << "d = {";
	for (int i = 1; i < d.size(); i++)
	{
		ost << d[i] << ',';
	}

	ost << '}' << std::endl;

	ost << "pred = {";
	for (int i = 1; i < pred.size(); i++)
	{
		ost << pred[i] << ',';
	}

	ost << '}' << std::endl;

	for (int i = 1; i <= this->nombreSommets(); i++)
	{
		if (d[i] != -1)
		{
			for (int j = 1; j <= this->nombreSommets(); j++)
			{
				if (d[j] != -1 && pred[j] == i && i != j)
				{
					ost << i << " -> " << j << std::endl;
				}
			}
		}
	}
}

void Graphe::fusion(int i, int j, std::vector<int>& prem, std::vector<int>& pilch, std::vector<int>& cc, std::vector<int>& nb) const
{
    int x;
    if(nb[i] > nb[j])
    {
        x = i;
        i = j;
        j = x;
    }
    x = prem[i];
    cc[x] = j;
    while(pilch[x] != 0)
    {
        x = pilch[x];
        cc[x] = j;
    }
    pilch[x] = prem[j];
    prem[j] = prem [i];
    nb[j] = nb[j] + nb[i];
}

void Graphe::sortWithQuickSort(std::vector<Arc*>& arcs,int first, int last, std::vector<int> somDeb, std::vector<int> somFin) const
{
    double x = arcs[(first + last) / 2]->poids();
    int i = first;
    int j = last;
    Arc* temp_var;
    int temp_num = 0;

    while (true) {
      while (arcs[i]->poids() < x) i++;
      while (x < arcs[j]->poids()) j--;
      if (i >= j) break;

      temp_var = arcs[i];
      arcs[i] = arcs[j];
      arcs[j] = temp_var;

      temp_num = somDeb[i];
      somDeb[i] = somDeb[j];
      somDeb[j] = temp_num;

      temp_num = somFin[i];
      somFin[i] = somFin[j];
      somFin[j] = temp_num;

      i++;
      j--;
    }

    if (first < (i -1)) sortWithQuickSort(arcs, first, i - 1, somDeb, somFin);
    if ((j + 1) < last) sortWithQuickSort(arcs, j + 1, last, somDeb, somFin);
}

void Graphe::Kruskal(std::ostream& ost) const
{
    ost << "Resultat de Kruskal : " << std::endl;

    MatriceAdjacence matrice = this->convertirEnMatriceAdjacence();
    int n = this->nombreSommets();

    int k =0;

    std::vector<int> prem (n+1);
    std::vector<int> pilch(n+1);
    std::vector<int> cc (n+1);
    std::vector<int> nb (n+1);

    MatriceAdjacence* T = new MatriceAdjacence();

    std::vector<Sommet*> sommetsT = matrice.sommets();

    for(int i = 0; i < sommetsT.size() ; i++)
    {
        T->ajouterSommet(sommetsT[i]);
    }

    for(int i = 1; i <= n; i++)
    {
        prem[i] = i;
        pilch[i] = 0;
        cc[i] = i;
        nb[i] = 1;
    }

    std::vector<Arc*> arcTri;
    std::vector<int> sommetDebut;
    std::vector<int> sommetFin;

     //On récupère tous les arcs du graphe
        for(int i = 0; i < T->nombreSommets(); i++)
        {
            for(int j = 0; j < T->nombreSommets(); j++)
            {
                if(matrice.matrice()[i][j]!= nullptr)
                {
                    arcTri.push_back(matrice.matrice()[i][j]);
                    sommetDebut.push_back(i);
                    sommetFin.push_back(j);
                }
//                if(matrice.matrice()[i][j]!= nullptr && matrice.matrice()[i][j]->poids() < poidsMax)
//                {
////                    poidsMax = matrice.matrice()[i][j]->poids();
//                    a = new Arc(matrice.matrice()[i][j]->poids(), "");
//                    dep = i;
//                    arr = j;
//                }
            }
        }

        //tri des arcs pas ordre croissant
        for(int i = 0; i < arcTri.size(); i++)
            std::cout<<arcTri[i]->poids();
        sortWithQuickSort(arcTri,0, arcTri.size()-1, sommetDebut, sommetFin);

    while(k < n && arcTri.size() > 0)
    {
//        Arc* a = nullptr;
        int deb = sommetDebut[0];
        int arr = sommetFin[0];

        //si les sommets sont dans 2 composantes connexes différentes, on ajoute l'arc et fusionne les Cc
        if(cc[deb] != cc[arr])
        {
            fusion(deb, arr, prem, pilch, cc, nb);
            std::string nomArc = std::to_string(deb) + " - " + std::to_string(arr);
            T->ajouterArc(arcTri[0], deb, arr);
            k++;
            ost << "..";
        }

        //on enleve les arcs traités
        arcTri.erase(arcTri.begin());
        sommetDebut.erase(sommetDebut.begin());
        sommetFin.erase(sommetFin.begin());


    }
    std::cout<<std::endl;

    T->affiche(ost);
}

void Graphe::Prufer(std::ostream &ost) const
{
	ost << "Résultat de Prufer : " << std::endl;
	FsAps fsaps = this->convertirEnFsAps();

	bool *I = new bool[this->nombreSommets()];
	for (int i = 1; i <= this->nombreSommets(); i++)
	{
		I[i] = true;
	}

	int compteur = 0;
	ost << "{ ";
	// Tant qu'on a pas éliminer tout les sommets du graphe
	while (compteur < this->nombreSommets() - 2)
	{
		int i = 1;
		//Tant que i n'est pas présent et qu'il n'est pas une feuille
		while (((fsaps.aps()[i] - fsaps.aps()[i - 1]) != 2) || (I[i - 1] == false)) { i++; }

		int sommet = fsaps.fs()[fsaps.aps()[i - 1]];
		fsaps.supprimerArc(sommet, i);
		fsaps.supprimerArc(i, sommet);

		ost << sommet << ", ";

		I[i - 1] = false;

		compteur++;
	}
}

void empiler(int s , std::vector<int>& tarj)
{
    tarj[s] = tarj[0] ;
    tarj[0] = s ;
}

void depiler(std::vector<int>& tarj)
{
    tarj[0] = tarj[tarj[0]] ;
}

void traversee(int s , int &p , int& nbcfc , const FsAps& fsaps , std::vector<int>& num, std::vector<int>& mu , std::vector<int>&prem , std::vector<int>& pilch , std::vector<int>& cfc, std::vector<int>& tarj , std::vector<bool>& entarj)
{
    int t ;
    num[s] = p++ ;
    mu[s] = num[s] ;
    empiler(s,tarj) ;
    entarj[s] = true ;
    for(int k=fsaps.aps()[s] ; (t=fsaps.fs()[k])!=0 ; k++)
    {
        if (num[t] == 0)
        {
            traversee(t,p,nbcfc,fsaps,num,mu,prem,pilch,cfc,tarj,entarj) ;
            mu[s] = mu[s] < mu[t] ? mu[s] : mu[t] ;
        }
        else if (entarj[t] && num[t] < num[s])
        {
            mu[s] = mu[s] < num[t] ? mu[s] : num[t] ;
        }
    }
    if(mu[s]==num[s])
    {
        nbcfc++ ;
        int x = tarj[0] ;
        pilch[0] = 0 ;
        prem[nbcfc] = x ;
        x = tarj[x] ;
        entarj[x] = false ;
        while (x!=s)
        {
            empiler(x,pilch) ;
            cfc[x] = nbcfc ;
            x = tarj[x] ;
            entarj[x] = false ;
        }
    }

}

void Graphe::Tarjan(std::ostream ost) const
{
    ost << "Resultats de Tarjan" << std::endl ;

    FsAps fsaps = this->convertirEnFsAps() ;

    int p=1 , nbcfc=0 ;

    std::vector<int> num (nombreSommets(),0) ;
    std::vector<int> mu (nombreSommets()) ;
    std::vector<int> prem (nombreSommets()+1) ;
    std::vector<int> pilch (nombreSommets()+1,0) ;
    std::vector<int> cfc (nombreSommets()) ;
    std::vector<int> tarj (nombreSommets()+1,0) ;
    std::vector<bool> entarj (nombreSommets(),false) ;


    for (int s=0 ; s<nombreSommets() ; s++)
    {
        if (num[s]==0)
            traversee(s,p,nbcfc,fsaps,num,mu,prem,pilch,cfc,tarj,entarj) ;
    }

    prem[0] = nbcfc ;

    for(int i=0 ; i<prem.size() ; i++)
    {
        ost << prem[i] << ' ' ;
    }
    ost<<std::endl ;
    for(int i=0 ; i<pilch.size() ; i++)
    {
        ost << pilch[i] << ' ' ;
    }
    ost<<std::endl ;
    for(int i=0 ; i<cfc.size() ; i++)
    {
        ost << cfc[i] << ' ' ;
    }
    ost<<std::endl ;



}
