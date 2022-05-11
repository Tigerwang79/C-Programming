//GROUPE : Guillaume PIERRE Valdrin SALIHI
#if defined HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "myassert.h"

#include "master_client.h"
#include "master_worker.h"

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#include <sys/stat.h>
#include <fcntl.h>

/************************************************************************
 * Données persistantes d'un master
 ************************************************************************/

// on peut ici définir une structure stockant tout ce dont le master
// a besoin
typedef struct master{
    int semId, fd_00, fd_01, nbPrimeGrand, nbPrimeCal;
    int pipeW[2];
    int pipeM[2];

} * t_master;

/************************************************************************
 * Usage et analyse des arguments passés en ligne de commande
 ************************************************************************/

static void usage(const char *exeName, const char *message)
{
    fprintf(stderr, "usage : %s\n", exeName);
    if (message != NULL)
        fprintf(stderr, "message : %s\n", message);
    exit(EXIT_FAILURE);
}


/************************************************************************
 * boucle principale de communication avec le client
 ************************************************************************/
void loop(t_master master){
    // boucle infinie :
    // - ouverture des tubes (cf. rq client.c)
    // - attente d'un ordre du client (via le tube nommé)
    // - si ORDER_STOP
    //       . envoyer ordre de fin au premier worker et attendre sa fin
    //       . envoyer un accusé de réception au client
    // - si ORDER_COMPUTE_PRIME
    //       . récupérer le nombre N à tester provenant du client
    //       . construire le pipeline jusqu'au nombre N-1 (si non encore fait) :
    //             il faut connaître le plus nombre (M) déjà enovoyé aux workers
    //             on leur envoie tous les nombres entre M+1 et N-1
    //             note : chaque envoie déclenche une réponse des workers
    //       . envoyer N dans le pipeline
    //       . récupérer la réponse
    //       . la transmettre au client
    // - si ORDER_HOW_MANY_PRIME
    //       . transmettre la réponse au client
    // - si ORDER_HIGHEST_PRIME
    //       . transmettre la réponse au client
    // - fermer les tubes nommés
    // - attendre ordre du client avant de continuer (sémaphore : précédence)
    // - revenir en début de boucle
    //
    // il est important d'ouvrir et fermer les tubes nommés à chaque itération
    // voyez-vous pourquoi ?

        int order, number;
        bool reponse;
        int fd_00 = open("tube_client", O_RDWR);
        int fd_01 = open("tube_master", O_WRONLY);

        read(fd_00, &order, sizeof(int));

        if(order == -1){

            write(fd_01, 0, sizeof(int)); // envoye l'accusé de réception au client
        }else if(order == 1){
            
            read(fd_00, &number, sizeof(int));//récupère nombre du client
            write(master->pipeW[1], number, sizeof(int)); // envoie le nombre
            read(master->pipeW[0], reponse, sizeof(bool)); //récupère la réposne
            master->nbPrimeCal++; //incrémante le fait d'avoir testé un nombre
            if(number > master->nbPrimeGrand){
                master->nbPrimeGrand = number; //change si le nombre testé est plus grand que l'ancien
            }
        }else if(order == 2){
             write(fd_00, master->nbPrimeCal, sizeof(int)); //transmet le nombre de teste au client
        }else if(order == 3){
            write(fd_00, master->nbPrimeGrand, sizeof(int)); //transmet le plus grand nombre prime au client
        }
        

        close("tube_client");
        close("tube_master");

}

t_master intiMaster(){
    t_master master;
    master->nbPrimeCal = 0;
    master->nbPrimeGrand = 0;
    
    return master;
}


/************************************************************************
 * Fonction principale
 ************************************************************************/

int main(int argc, char * argv[])
{
    if (argc != 1)
        usage(argv[0], NULL);

    int id_00 = ftok("master_client.h", ID_PROJECT);
    int id_01 = ftok("master_client.h", ID_PROJECT);

    // - création des sémaphores
    int semId_00 = semget(id_00, 1, IPC_CREAT);
    int semId_01 = semget(id_01, 1, IPC_CREAT);

    // - création des tubes nommés
    mkfifo("tube_master", 0666);
    mkfifo("tube_client", 0666);
    // - création du premier worker
    fork();
    execv("worker.c", argv);

    t_master master = intiMaster();
    
    // boucle infinie
    loop(master);


    // destruction des tubes nommés, des sémaphores, ...
    semctl(semId_00,1,IPC_RMID);
    semctl(semId_01,1,IPC_RMID);
    unlink("tube_master");
    unlink("tube_client");
    return EXIT_SUCCESS;
}

// N'hésitez pas à faire des fonctions annexes ; si les fonctions main
// et loop pouvaient être "courtes", ce serait bien
