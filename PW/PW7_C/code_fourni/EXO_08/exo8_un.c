// pour des problèmes de compilation
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#include "exo8_comm.h"

// création d'un sémaphore IPC
static int my_semget(int projectId, int initVal)
{
    // TODO création et initialisation d'un sémaphore

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

// création d'un segment
static int my_shmget()
{
    // TODO création du segment de mémoire partagé

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

// suppression des sémaphores et du segment
static void my_destroyAll(int sem1, int sem2, int shm)
{
    // TODO détruire les deux sémaphores et le segment
}


int main()
{
    const char * const chaine = "Bonjour monde !";
    int semIdEcriture;
    int semIdFin;
    int shmId;
    char * ptShm = NULL;

    // création sémaphores
    semIdEcriture = my_semget( PROJ_ID_SEM_ECRITURE, 0);
    semIdFin = my_semget( PROJ_ID_SEM_FIN, 0);

    // création segment (rappel : on suppose le segment assez grand)
    shmId = my_shmget();
    // et un pointeur sur le segment
    ptShm = my_shmat(shmId);

    // on écrit avec une tempo
    sleep(3);
    printf("Je vais écrire la chaine\n");
    strcpy(ptShm, chaine);
    sleep(1);
    printf("Chaine écrite\n");

    // on débloque deux
    vendre(semIdEcriture);

    // on attend que deux n'ait plus besoin du segment (et des sémaphore)
    prendre(semIdFin);

    // on détache le pointeur
    my_shmdt(ptShm);

    // on détruit tout le monde
    my_destroyAll(semIdEcriture, semIdFin, shmId);
    

    printf("Fin de un\n");
    
    return EXIT_SUCCESS;
}
