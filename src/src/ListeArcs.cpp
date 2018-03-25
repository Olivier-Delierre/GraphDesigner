#include "../include/ListeArcs.h"

ListeArcs::ListeArcs() {}

void ListeArcs::ajouter(Arc info, Sommet* successeur) {
    ListeArcs* courant = d_suivant;
    ListeArcs nouveau = new ListeArcs();
    nouveau->d_info = info;
    nouveau->d_successeur = successeur;

    while(courant->d_suivant != nullptr) {
        courant = courant->d_suivant;
    }
    courant->d_suivant = nouveau;
}

void ListeArcs::supprimer(Arc info, Sommet* successeur) {
    if(this != nullptr) {
        if(d_info == info && d_successeur == successeur) {
            ListeArcs* courant = d_suivant;
        }
    }
    while(courant->d_info != info || courant->d_successeur != successeur && courant->d_suivant != nullptr) {
        courant = courant->d_suivant;
    }
}
