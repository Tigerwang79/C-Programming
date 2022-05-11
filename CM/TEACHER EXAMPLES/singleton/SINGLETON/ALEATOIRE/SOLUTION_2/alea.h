/*
 * Il s'agit d'une bibliothèque qui est particulièrement simple
 * à utiliser.
 * L'utilisation du générateur aléatoire est plus compliquée
 * mais tout est caché dans le .c
 *
 * Cette solution impose à l'utilisateur une discipline moins stricte
 * que la précédente, mais il encore possible d'avoir une utilisation
 * incorrecte de la bibliothèque.
 */
#ifndef ALEA_H
#define ALEA_H

// cette méthode doit être appelée une seule fois (et doit obligatoirement
// être appelée), et ce avant tout appel à alea_get.
// ceci dit, si vous appelez plusieurs fois cette méthode, cela n'a
// aucune incidence.
void alea_init();

// renvoie un nombre aléatoire compris entre min et max, bornes incluses
// alea_init doit être appelée avant tout appel à cette fonction
int alea_get(int min, int max);

#endif
