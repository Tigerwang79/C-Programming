#include <stdio.h>
#include <stdlib.h>
// inclure ici les .h nécessaires
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

// nombre de threads à lancer
#define NB_THREADS  3

// fonction support d'un thread
// éventuellement faites une temporisation d'une seconde avant l'affichage
// tous les threads lanceront cette fonction
// TODO
void *codeThread(void * arg)
{
    assert(arg != NULL);
    sleep(1);
    printf(" -> Thread de tid %ld\n", pthread_self());
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

    // lancement des threads
    for (int i = 0; i < NB_THREADS; i++)
    {
        // TODO
        // ne pas oublier de tester le code de retour
        ret = pthread_create(&(tabTid[i]), NULL, codeThread, NULL);
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
        // ne pas oublier de tester le code de retour
        ret = pthread_join(tabTid[i], NULL);
        assert(ret == 0);
        printf("Fin thread de tid %ld\n", tabTid[i]);
        printf("\n");
    }
    
    // Rq : il y a bien deux boucles : une pour lancer tous les threads
    //      (quasi) en même temps, et une autre après pour attendre
    //      leurs fins.
    //      Si on ne fait qu'une seule boucle :
    //          for (...) {
    //              lancer thread
    //              attendre fin thread
    //          }
    //      alors les threads s'exécutent les uns après les autres au lieu
    //      d'être en concurrence (auquel cas les threads sont inutiles et
    //      autant appeler la fonction normalement).
    //      À tester pour être convaincu.

    printf("Fin thread principal\n");
    return EXIT_SUCCESS;
}