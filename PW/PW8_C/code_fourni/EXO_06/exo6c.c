#include <stdio.h>
#include <stdlib.h>
// inclure ici les .h nécessaires
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>


// nombre de threads à lancer
#define NB_THREADS  10

// nombre d'incrémentations par thread
#define NB_ITERATIONS  10*1000*1000

// structure pour passer les paramètres aux pthread :
//   . un pointeur sur l'entier devant recevoir le résultat
//   . le nombre d'incrémentations
typedef struct
{
    int *result;
    int nbIterations;
} ThreadData;

// mutex déclaré en global
// TODO
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Fonction support d'un thread
// Tous les threads lanceront cette fonction
// Code
//    le paramètre de la fonction est un void *
//    il faut le caster en ThreadData *
//    les itérations sont faites sur une variable locale
//    la mise à jour de la variable partagée est en section critique
// Faites des assert pour tester les verrouillage et déverrouillage
void * codeThread(void * arg)
{
    ThreadData *data = (ThreadData *) arg;
    int ajout = 0;

    for (int i = 0; i < data->nbIterations; i++)
    {
        ajout ++;
    }
    // TODO verrouiller
    int ret1 = pthread_mutex_lock(&mutex);
    assert(ret1 == 0);
    (*(data->result)) += ajout;
    // TODO déverrouiller
    int ret2 = pthread_mutex_unlock(&mutex);
    assert(ret2 == 0);
    
    return NULL;
}

int main()
{
    // variable partagée (ne pas oublier de l'initialiser à 0)
    int result = 0;

    // On déclare ici un tableau de pthread_t pour stocker tous les
    // identifiants des threads
    pthread_t tabId[NB_THREADS];
    // et un tableau de struct pour que chaque thread ait sa propre structure
    ThreadData datas[NB_THREADS];

    // pré-initialisation des données
    for (int i = 0; i < NB_THREADS; i++)
    {
        // il faut initialiser datas[i] avec :
        //   . un pointeur sur la variable à incrémennter
        //   . le nombre d'itérations à faire
        datas[i].result = &result;
        datas[i].nbIterations = NB_ITERATIONS;
    }

    // lancement des threads
    for (int i = 0; i < NB_THREADS; i++)
    {
        // et donc on passe un pointeur sur une struct différente chaque fois
        int ret = pthread_create(&(tabId[i]), NULL, codeThread, &(datas[i]));
        assert(ret == 0);
    }

    // attente de la fin des threads
    for (int i = 0; i < NB_THREADS; i++)
    {
        int ret = pthread_join(tabId[i], NULL);
        assert(ret == 0);
    }

    // pour être propre, on détruit le mutex
    // TODO
    pthread_mutex_destroy(&mutex);

    // Affichage résultat
    printf("Fin thread principal : résultat\n");
    printf("Attendu : %d\n", NB_THREADS * NB_ITERATIONS);
    printf("Obtenu  : %d\n", result);

    return EXIT_SUCCESS;
}
