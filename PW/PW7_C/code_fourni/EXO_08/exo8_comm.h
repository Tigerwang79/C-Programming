#ifndef EXO8_COMM
#define EXO8_COMM

// fichier (qui doit être accessible) choisi pour l'identification du sémaphore
#define MON_FICHIER "exo8_comm.h"

// identifiants pour le deuxième paramètre de ftok
#define PROJ_ID_SEM_ECRITURE 5
#define PROJ_ID_SEM_FIN 6
#define PROJ_ID_SHM 5

// taille segment (surdimensionné)
#define SHM_TAILLE 100*sizeof(char)

#endif
