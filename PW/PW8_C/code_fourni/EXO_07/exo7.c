#include <stdio.h>
#include <stdlib.h>
// inclure ici les .h nécessaires
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>


// nombre de threads à lancer
#define NB_THREADS  3

// structure pour passer les paramètres aux pthread :
//   . le numéro du thread
//   . le sémaphore (un pointeur obligatoirement)
typedef struct
{
    int numero;
    // TODO déclaration sémaphore
    sem_t semaphore;
} ThreadData;

// Fonction support d'un thread
// Tous les threads lanceront cette fonction
// Code
//    le paramètre de la fonction est un void *
//    il faut le caster en ThreadData *
// Faites des assert pour tester les manipulations du sémaphore
void * codeThread(void * arg)
{
    ThreadData *data = (ThreadData *) arg;

    // simulation d'un temps d'initialisation
    sleep(rand()%3 + 1);

    printf("      [%d] commence à travailler\n", data->numero);
    // on prévient le thread principal qu'on commence à travailler
    // TODO réveil du thread principal
    int ret = sem_post(&(data->semaphore));
    assert(ret == 0);
    
    sleep(rand()%3 + 1);
    printf("      [%d] a fini de travailler\n", data->numero);
    
    return NULL;
}

int main()
{
    // sémaphore déclaré en local
    // TODO déclaration et initialisation
    sem_t semaphore;
    sem_init(&semaphore, 0, 1);

    // On déclare ici un tableau de pthread_t pour stocker tous les
    // identifiants des threads
    pthread_t tabId[NB_THREADS];
    // et un tableau de struct pour que chaque thread ait sa propre structure
    ThreadData datas[NB_THREADS];

    // initialisation génération nombres aléatoires
    srand(getpid());

    // pré-initialisation des données
    for (int i = 0; i < NB_THREADS; i++)
    {
        // il faut initialiser datas[i] avec :
        //   . le numéro du thread
        //   . le sémaphore partagé
        datas[i].numero = i+1;
        // TODO initialisation semaphore
        datas[i].semaphore = semaphore;
    }

    // lancement des threads
    for (int i = 0; i < NB_THREADS; i++)
    {
        // et donc on passe un pointeur sur une struct différente chaque fois
        int ret = pthread_create(&(tabId[i]), NULL, codeThread, &(datas[i]));
        assert(ret == 0);
    }

    // attendre que les threads aient fini leurs initialisations
    printf("J'attends les débuts des threads\n");
    for (int i = 0; i < NB_THREADS; i++)
    {
        // TODO attente de chaque fils
        sem_post(&(datas->semaphore));
        printf("  un thread de prêt (i = %d)\n", i);
        sem_wait(&(datas->semaphore));
    }
    printf("Fin attente\n");

    // attente de la fin des threads
    for (int i = 0; i < NB_THREADS; i++)
    {
        int ret = pthread_join(tabId[i], NULL);
        assert(ret == 0);
    }

    // pour être propre, on détruit le sémaphore
    // TODO destruction sémaphore
    sem_destroy(&semaphore);

    printf("Fin thread principal\n");

    return EXIT_SUCCESS;
}
