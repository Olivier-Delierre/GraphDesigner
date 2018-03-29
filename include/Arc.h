#ifndef ARC_H
#define ARC_H

#include <string>

class Arc
{
	public:
		/**
		 * Constructeur prenant comme paramètre un poids, ainsi
		 * qu'un libelle.
		 *
		 * @param poids Le poids de l'arc ;
		 * @param libelle Le libellé de l'arc.
		 */
		Arc(double poids, std::string libelle);

        /**
		 * Constructeur qui initialise un arc de poids nul et sans nom.
		 */
		Arc();

		/**
		* Renvoie le poids de l'arc.
		*
		* @return le poids de l'arc.
		*/
		double poids() const ;

		/**
		* Renvoie le libelle de l'arc.
		*
		* @return le libelle de l'arc.
		*/
		std::string libelle() const ;

	private:
		/// Poids de l'arc.
		double d_poids;
		/// Libellé de l'arc.
		std::string d_libelle;
};

#endif
