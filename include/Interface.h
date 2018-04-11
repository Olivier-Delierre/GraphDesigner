#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <string>
#include "../include/MatriceAdjacence.h"
#include "../include/SommetNumero.h"
#include "../include/SommetMot.h"
#include "../include/Graphe.h"
#include "../include/Arc.h"

namespace Interface {
	static Graphe* grapheSelectionne = nullptr;
	static int typeGraphe = -1;
	static int dernierIdArc = 0;
	static bool possedeSommetNumero;

	void Header();
	void MenuPrincipal();

	void ImporterGraphe();

	void CreerGraphe();

	// Manipulation du graphe
	void AjouterSommet();

	void TransformerGraphe();
	void AppliquerAlgorithme();

	void AfficherGraphe();
	void SauvegarderGraphe();

	void Quitter();
}

#endif