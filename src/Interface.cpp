#include "../include/Interface.h"

namespace Interface {

	void Header()
	{
		system("cls");
		std::cout << "=============" << std::endl;
		std::cout << "GraphDesigner" << std::endl;
		std::cout << "=============" << std::endl;
		std::cout << std::endl;
	}

	void MenuPrincipal()
	{
		int choice = -1;

		while (choice != 0)
		{
			Header();

			std::cout << "- Menu principal -" << std::endl;
			std::cout << "1. Importer un graphe" << std::endl;
			std::cout << "2. Creer un graphe" << std::endl;

			if (grapheSelectionne != nullptr)
			{
				std::cout << std::endl;
				std::cout << "3. Transformer le graphe" << std::endl;
				std::cout << "4. Appliquer un algorithme" << std::endl;
				std::cout << std::endl;
				std::cout << "5. Afficher le graphe" << std::endl;
				std::cout << "6. Enregistrer le graphe" << std::endl;
			}

			std::cout << std::endl;

			std::cout << "0. Quitter" << std::endl;

			std::cout << std::endl;

			std::cout << "Votre choix : ";
			std::cin >> choice;

			switch (choice)
			{
			case 1:
				ImporterGraphe();
				break;

			case 2:
				CreerGraphe();
				break;

				if (grapheSelectionne != nullptr)
				{
				case 3:
					TransformerGraphe();
					break;

				case 4:
					AppliquerAlgorithme();
					break;

				case 5:
					AfficherGraphe();
					break;

				case 6:
					SauvegarderGraphe();
					break;
				}

			case 0:
				Quitter();
				break;

			default:
				break;
			}
		}
	}

	void ImporterGraphe()
	{
		Header();
	}

	void CreerGraphe()
	{
		int choice = -1;

		while (choice != 0)
		{
			Header();
			int choice;

			std::cout << "- Creer un graphe -" << std::endl;
			std::cout << "1. Syntaxe Matrice Adjacence" << std::endl;
			std::cout << "2. Syntaxe Fs Aps" << std::endl;
			std::cout << "3. Syntaxe Listes" << std::endl;
			std::cout << std::endl;
			std::cout << "0. Retour" << std::endl;

			std::cout << std::endl;

			std::cout << "Votre choix : ";
			std::cin >> choice;

			switch (choice)
			{
			case 1:
				CreerMatriceAdjacence();
				break;

			case 2:
				CreerFsAps();
				break;

			case 3:
				CreerListes();
				break;

			case 0:
				return;
			}

			std::cout << choice;
		}
	}

	void CreerMatriceAdjacence()
	{
		Header();
		std::cout << "- Syntaxe Matrice Adjacence -" << std::endl;
		std::cout << "Saisir le nombre de sommet : ";
		int nombreSommet = 0;
		std::cin >> nombreSommet;

		std::vector<Sommet*> sommets(nombreSommet);
		std::vector< std::vector<Arc*> > arcs(nombreSommet, std::vector<Arc*>(nombreSommet));

		int choice = -1;

		while (choice != 1 && choice != 2)
		{
			std::cout << "Les sommets seront t-ils des nombres (1) ou des mots (2) ? ";
			std::cin >> choice;

			if (choice != 1 && choice != 2)
			{
				std::cout << "Merci de saisir 1 ou 2." << std::endl << std::endl;
			}
		}

		if (choice == 1)
		{
			for (int i = 0; i < nombreSommet; i++)
			{
				std::string nomSommet = "";
				while (nomSommet == "")
				{
					std::cout << "Nom du sommet no." << i + 1 << " : ";
					std::cin >> nomSommet;

					int j = 0;
					while (j < nomSommet.size() && (nomSommet[j] < 48 || nomSommet[j] > 57))
					{
						j++;
					}	

					if (j == nomSommet.size())
					{
						std::cout << "Merci de saisir un nombre." << std::endl << std::endl;
						nomSommet = "";
					}
				}

				sommets[i] = new SommetNumero(i, std::stoi(nomSommet));
			}
		}

		if (choice == 2)
		{
			for (int i = 0; i < nombreSommet; i++)
			{
				std::string nomSommet = "";
				std::cout << "Nom du sommet no." << i + 1 << " : ";
				std::cin >> nomSommet;

				sommets[i] = new SommetMot(i, nomSommet);
			}
		}


		for (int i = 0; i < nombreSommet; i++)
		{
			std::cout << "Sommet no. " << i + 1 << " ("; sommets[i]->affiche(std::cout); std::cout << ") :" << std::endl;

			for (int j = 0; j < nombreSommet; j++)
			{
				std::string yes_no = "";
				std::cout << "\tLe sommet no. " << j + 1 << " ("; sommets[j]->affiche(std::cout); std::cout << ") est-t'il un successeur ? (Y/N) ";
				std::cin >> yes_no;

				while (yes_no != "y" && yes_no != "Y" && yes_no != "n" && yes_no != "N")
				{
					std::cout << "\tMerci de répondre par y ou par n." << std::endl << std::endl;
					yes_no = "";
				}

				if ((yes_no == "y") || (yes_no == "Y"))
				{
					std::string poids = "";

					while (poids == "")
					{
						std::cout << "\t\tQuel est le poids de l'arc ? ";
						std::cin >> poids;

						int j = 0;

						while (j < poids.size() && (poids[j] < 48 || poids[j] > 57))
						{
							j++;
						}

						if (j == poids.size())
						{
							std::cout << "\t\tMerci de saisir un nombre." << std::endl << std::endl;
							poids = "";
						}
					}

					std::string libelle = "";
					std::cout << "\t\tQuel est le libelle de l'arc ? ";
					std::cin >> libelle;

					arcs[i][j] = new Arc(std::stoi(poids), libelle);
				}
				else
				{
					arcs[i][j] = nullptr;
				}
			}
		}

		grapheSelectionne = new MatriceAdjacence(arcs, sommets);
		return;
	}

	void CreerFsAps()
	{

	}

	void CreerListes()
	{

	}

	void TransformerGraphe()
	{

	}

	void AppliquerAlgorithme()
	{

	}

	void AfficherGraphe()
	{

	}

	void SauvegarderGraphe() 
	{
		Header();
		std::cout << "- Sauvegarde du graphe -" << std::endl;

		std::ofstream f("data.txt");
		grapheSelectionne->affiche(f);

		std::cout << "Le graphe a bien ete sauvegarde ! " << std::endl << std::endl;
		system("pause");
	}

	void Quitter()
	{
		exit(0);
	}
}