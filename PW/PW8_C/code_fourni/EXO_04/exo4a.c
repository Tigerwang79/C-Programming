#include <stdio.h>
#include <stdlib.h>
// inclure ici les .h nécessaires
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

// nombre de threads à lancer
#define NB_THREADS  3

// Fonction support d'un thread
// Tous les threads lanceront cette fonction
// Code
//    le paramètre de la fonction est un void *
//    il faut le caster en int *, avec un code qui ressemble à
//            int *p = (int *) arg;
//    on fait une temporisation d'une seconde avant l'affichage
//    on affiche la valeur du pointeur (p) et de l'entier pointé (*p)
// TODO
void *codeThread(void * arg)
{
    assert(arg != NULL);
    int *p = (int *) arg;
    sleep(1);
    printf(" -> Thread de tid %ld, la valeur du pointeur (p) = %ls et la valeur du pointé (*p) = %d\n", pthread_self(), p, *p);
    printf("\n");
    return NULL;
}

int main()
{
    int ret;

    // On déclare ici un tableau de pthread_t pour stocker tous les
    // identifiants des threads
    // TODO
    pthread_t tabTid[NB_THREADS];
    
    // le compteur pour passer un numéro aux threads
    int compteur = 0;

    // lancement des threads
    for (int i = 0; i < NB_THREADS; i++)
    {
        compteur ++;
        // et donc on passe un pointeur sur compteur au thread
        // TODO
        ret = pthread_create(&(tabTid[i]), NULL, codeThread, &compteur);
        assert(ret == 0);
    }

    printf("Thread initial d'identite %ld\n", pthread_self());
    printf("\n");

    // attente de la fin des threads
    // (testez le programme sans attente, éventuellement avec une
    //  temporisation dans le code du thread)
    for (int i = 0; i < NB_THREADS; i++)
    {
        // TODO
        ret = pthread_join(tabTid[i], NULL);
        assert(ret == 0);
        printf("Fin thread de tid %ld\n", tabTid[i]);
        printf("\n");
    }

    printf("Fin thread principal\n");
    return EXIT_SUCCESS;
}