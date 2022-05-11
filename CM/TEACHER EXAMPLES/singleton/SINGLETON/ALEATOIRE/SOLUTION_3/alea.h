/*
 * Il s'agit d'une bibliothèque qui est particulièrement simple
 * à utiliser.
 * L'utilisation du générateur aléatoire est plus compliquée
 * mais tout est caché dans le .c
 *
 * Cette solution assure que l'utilisateur ne peut pas faire de bêtise
 * même s'il en a envie.
 * Et même il n'a pas à penser à initialiser le générateur aléatoire.
 */
#ifndef ALEA_H
#define ALEA_H

// note ; plus de méthode publique d'initialisation

// renvoie un nombre aléatoire compris entre min et max, bornes incluses
// alea_init doit être appelée avant tout appel à cette fonction
int alea_get(int min, int max);

#endif
