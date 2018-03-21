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

		Arc() = default;

	private:
		/// Poids de l'arc.
		double d_poids;
		/// Libellé de l'arc.
		std::string d_libelle;
};

#endif
