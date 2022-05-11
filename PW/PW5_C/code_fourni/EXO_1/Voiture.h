#ifndef VOITURE_H
#define VOITURE_H

//todo

#include <stdio.h>

struct T_Voiture;
typedef struct T_Voiture * Voiture;
typedef const struct T_Voiture * const_Voiture;


// Statistique
int voi_stat_getNbInitialisations();
int voi_stat_getNbImmatriculations();
int voi_stat_getAnneeMin();
int voi_stat_getAnneeMax();


// Constructeur
Voiture voi_creer(const char *marque, int annee, int kilometrage, int nbImmatriculations, const char *immatriculations[]);
Voiture voi_creerCopie(const_Voiture source);


// Écrire à partir d'un fichier
Voiture voi_creerFromFichier(FILE *fd);

void voi_detruire(Voiture *pself);

void voi_swap(Voiture v1, Voiture v2);


// Accesseurs
void voi_getMarque(const_Voiture self, char *marque);
int voi_getAnnee(const_Voiture self);
int voi_getKilometrage(const_Voiture self);
void voi_setKilometrage(Voiture self, int kilometrage);
int voi_getNbImmatriculations(const_Voiture self);
void voi_getImmatriculation(const_Voiture self, int pos, char *immatriculation);
void voi_addImmatriculation(Voiture self, const char *immatriculation);


// Affichage
void voi_afficher(const_Voiture self);


// Écrire-Lire
void voi_ecrireFichier(const_Voiture self, FILE *fd);
void voi_lireFichier(Voiture self, FILE *fd);

#endif