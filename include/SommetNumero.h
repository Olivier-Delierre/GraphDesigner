/**
 * Classe héritant de Sommet permettant de représenter
 * un sommet identifier par un numéro.
 */

#ifndef SOMMETNUMERO_H
#define SOMMETNUMERO_H

#include "Sommet.h"

class SommetNumero : public Sommet 
{
    public:
        /**
         * Constructeur prenant comme paramètre l'identifiant ainsi que le nom
         * du Sommet.
         * 
         * @param id Un identifiant ;
         * @param nom Un nom sous forme d'entier.
         */ 
        SommetNumero(unsigned int id, int nom);

        /**
		 * Affiche un SommetNumero sur la sortie standard.
		 * 
		 * @param ost Une sortie standard.
		 */ 
        virtual void affiche(std::ostream& ost) const override;
    private:
        /// Nom du sommet.
        int d_nom;
};

#endif
