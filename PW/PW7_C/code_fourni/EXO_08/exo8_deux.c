// pour des problèmes de compilation
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#include "exo8_comm.h"


// récupération d'un sémaphore IPC
static int my_semget(int projectId)
{
    // TODO récupérer un des deux sémaphore créés par un

    return -1;
}

// -1 sur un sémaphore
static void prendre(int semId)
{
    // TODO faire un -1 sur un sémaphore
}

// +1 sur un sémaphore
static void vendre(int semId)
{
    // TODO faire un +1 sur un sémaphore
}

// récupération d'un segment
static int my_shmget()
{
    // TODO récupérer le segment de mémoire partagé créé par un

    return -1;
}

// attachement sur un segment
static char * my_shmat(int shmId)
{
    // TODO attacher un pointeur sur le segment
    return NULL;
}

// détachement d'un segment
void my_shmdt(void *pt)
{
    // TODO détacher le pointeur
}


int main()
{
    int semIdEcriture;
    int semIdFin;
    int shmId;
    char * ptShm = NULL;
    
    // récupération sémaphores
    semIdEcriture = my_semget( PROJ_ID_SEM_ECRITURE);
    semIdFin = my_semget(PROJ_ID_SEM_FIN);

    // création segment (rappel : on suppose le segment assez grand)
    shmId = my_shmget();
    // et un pointeur sur le segment (autant le mettre en read only)
    ptShm = my_shmat(shmId);

    // on attent l'autorisation de un
    prendre(semIdEcriture);

    // On affiche la chaine
    printf("chaine : %s\n", ptShm);

    // on détache le pointeur
    my_shmdt(ptShm);

    // on dit à un qu'il peut tout détruire
    vendre(semIdFin);

    // et donc rien à détruire
    
    printf("Fin de deux\n");
    
    return EXIT_SUCCESS;
}
