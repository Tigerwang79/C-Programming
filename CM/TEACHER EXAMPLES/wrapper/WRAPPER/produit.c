#include <assert.h>

#include "produit.h"


/*
 * résolution du problème artificiellement récursive
 */

// fonction interne récursive
// on sait que le tableau initial n'est pas vide : inutile de vérifier
// la taille
float produitRec(float tab[], int taille, int pos)
{
    if (pos == taille)
        return 1.f;    // correct car le tableau initial n'est pas vide
    else
        return tab[pos] * produitRec(tab, taille, pos+1);
}

// wrapper :
// - fait les vérifications initiales
// - amorce la récursivité
float produit(float tab[], int taille)
{
    // vérification de base à faire une seule fois
    assert(taille > 0);

    // appel de la récursivité où on maîtrise l'appel initial
    float result = produitRec(tab, taille, 0);

    return result;
}
