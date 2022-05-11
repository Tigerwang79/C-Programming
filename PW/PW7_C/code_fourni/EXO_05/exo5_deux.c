// pour des problèmes de compilation
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
// ajouter ici les include nécessaires

#include "exo5_comm.h"


int main()
{
    // il faut récupérer le sémaphore avec la clé fournie dans exo5_comm.h
    // il faut être rigoureux : le sémaphore doit déjà exister sinon
    //      c'est une erreur
    // faut-il initialiser le sémaphore ?


    // ici il faut attendre le déblocage venant de "un"


    // affichage venant après celui de un
    printf("Processus deux %d ! (normalement je m'affiche en dernier)\n",
           getpid());

    // Qui doit détruire le sémaphore ? un ou deux ?
    // Rappelez-vous que lorsqu'on détruit un sémaphore, il faut
    // être certain qu'aucun autre processus ne l'utilise.


    printf("Fin de deux\n");
    
    return EXIT_SUCCESS;
}
