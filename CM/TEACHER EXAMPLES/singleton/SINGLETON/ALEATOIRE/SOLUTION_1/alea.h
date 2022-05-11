/*
 * Il s'agit d'une bibliothèque qui est particulièrement simple
 * à utiliser.
 * L'utilisation du générateur aléatoire est plus compliquée
 * mais tout est caché dans le .c
 *
 * Cette solution impose à l'utilisateur une discipline stricte
 * qui si elle n'est pas respectée conduit à une utilisation
 * incorrecte de la bibliothèque.
 */
#ifndef ALEA_H
#define ALEA_H

// cette méthode doit être appelée une seule fois (et doit obligatoirement
// être appelée), et ce avant tout appel à alea_get
void alea_init();

// renvoie un nombre aléatoire compris entre min et max, bornes incluses
// alea_init doit être appelée avant tout appel à cette fonction
int alea_get(int min, int max);

#endif
