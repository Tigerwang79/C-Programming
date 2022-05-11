#ifndef COLLECTION_H
#define COLLECTION_H

#include <stdbool.h>

#include "Voiture.h"

struct T_Collection;
typedef struct CollectionP * Collection;
typedef const struct CollectionP * const_Collection;


Collection col_creer();
Collection col_creerCopie(const_Collection source);
void col_detruire(Collection *pself);
void col_vider(Collection self);


// Accesseurs
int col_getNbVoitures(const_Collection self);
Voiture col_getVoiture(const_Collection self, int pos);

void col_addVoitureSansTri(Collection self, const_Voiture voiture);
void col_addVoitureAvecTri(Collection self, const_Voiture voiture);

void col_supprVoitureSansTri(Collection self, int pos);
void col_supprVoitureAvecTri(Collection self, int pos);

void col_trier(Collection self);


// Affichage
void col_afficher(const_Collection self);


// Écrire-Lire
void col_ecrireFichier(const_Collection self, FILE *fd);
void col_lireFichier(Collection self, FILE *fd);

#endif