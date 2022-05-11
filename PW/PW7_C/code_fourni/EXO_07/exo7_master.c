// pour des problèmes de compilation
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#include "exo7_comm.h"

const int MIN_WORKERS = 1;
const int MAX_WORKERS = 7;

//-----------------------------------------------------------------
static void usage(const char *exeName, const char *message)
{
    fprintf(stderr, "usage : %s <nbre workers>\n", exeName);
    fprintf(stderr, "        nombre de workers compris entre %d et %d\n",
            MIN_WORKERS, MAX_WORKERS);
    fprintf(stderr, "        le programme ne vérifie pas que le paramètre "
            "est un entier correctement constitué.\n");
    if (message != NULL)
        fprintf(stderr, "message : %s\n", message);
    exit(EXIT_FAILURE);
}


//-----------------------------------------------------------------
// Il faut créer le sémaphore avec une clé générée par ftok et le
// le fichier fourni dans exo7_comm.h
// Il faut être rigoureux : si le sémphore existe déjà, c'est une erreur
// et il ne faut pas oublier de l'initialiser en fonction du nombre
// de workers
static int my_semget(int nbreWorkers)
{
    //Recupère la clé
    int key = ftok("exo7_master.c",1);
    
    //Créé le semaphore
    int semid = semget(key,1,IPC_CREAT | 0641);
    assert(semid!=-1);
    //Ajoute le nombre de workers
    struct sembuf up ={0,nbreWorkers,0};
    semop(semid,&up,1);
    
    return semid;
}

//-----------------------------------------------------------------
// destruction du sémaphore
static void my_destroy(int semId)
{
	//Détruit le semaphore
    semctl(semId,1,IPC_RMID);
}


//-----------------------------------------------------------------
int main(int argc, char * argv[])
{
    if (argc != 2)
        usage(argv[0], "nombre de paramètres incorrect");

    int nbreWorkers;
    int semId;
    
    nbreWorkers = strtol(argv[1], NULL, 10);
    if ((nbreWorkers < MIN_WORKERS) || (nbreWorkers > MAX_WORKERS))
        usage(argv[0], "nbre workers incorrect");

    // création du sémaphore
    semId = my_semget(nbreWorkers);

    printf("Le sémaphore est crée et vous devez lancer %d workers\n",
           nbreWorkers);
     
    printf("Lorsque tous les workers ont terminé, appuyez sur <Entrée>\n");

    printf("--> ");
    getchar();

    // destruction du sémaphore
    // si vous êtes curieux, faites-le pendant que les workers l'utilisent
    my_destroy(semId);

    printf("Fin du master\n");
    
    return EXIT_SUCCESS;
}
