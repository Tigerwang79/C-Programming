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
    // il faut créer le sémaphore avec la clé fournie dans exo5_comm.h
    // il faut être rigoureux : si le sémphore existe déjà, c'est une erreur
    // et il ne faut pas oublier de l'initialiser


    // une longue attente pour qu'on ait le temps de lancer exo5_deux
    // et pour être sûr que ce dernier attend
    sleep(5);
    printf("Processus un %d ! (normalement je m'affiche en premier)\n",
           getpid());
    sleep(1);
    
    // ici il faut débloquer le processus "deux"


    // Qui doit détruire le sémaphore ? un ou deux ?
    // Rappelez-vous que lorsqu'on détruit un sémaphore, il faut
    // être certain qu'aucun autre processus ne l'utilise.


    printf("Fin de un\n");
    
    return EXIT_SUCCESS;
}
