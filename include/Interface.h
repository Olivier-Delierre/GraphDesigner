#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <string>
#include "../include/MatriceAdjacence.h"
#include "../include/SommetNumero.h"
#include "../include/SommetMot.h"
#include "../include/Graphe.h"

#define ADJACENCE 0
#define FSAPS 1
#define LISTES 2

namespace Interface {
	static Graphe* grapheSelectionne = nullptr;
	static int typeGraphe = -1;
	static int dernierIdArc = 0;

	void Header();
	void MenuPrincipal();

	void ImporterGraphe();

	void CreerGraphe();

	void TransformerGraphe();
	void AppliquerAlgorithme();

	void AfficherGraphe();
	void SauvegarderGraphe();

	void Quitter();
}

#endif