#include "../include/Graphe.h"

#include "../include/FsAps.h"

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
			// Si le sommet i n'est pas vérouillé
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
		while (isLocked[i]) { i++; }

		// On cherche maintenant la plus petite valeur.
		unsigned int index_min = i;
		for (; i <= this->nombreSommets(); i++)
		{
			if (!isLocked[i] && d[i] < d[index_min])
			{
				index_min = i;
			}
		}

		s = index_min;

		// Puis on enlève un élément à S.
		S--;
	}

	ost << "Résultat de Dijkstra : " << std::endl;
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

void Graphe::Kruskal(std::ostream ost) const
{

}

void Graphe::Prufer(std::ostream ost) const
{

}

void Graphe::Tarjan(std::ostream ost) const
{

}
