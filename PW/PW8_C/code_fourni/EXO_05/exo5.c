#include <stdio.h>
#include <stdlib.h>
// inclure ici les .h nécessaires
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>


// nombre de threads à lancer
#define NB_THREADS  4

// structure pour passer les paramètres aux pthread :
//   . un pointeur sur l'entier devant recevoir le résultat
//   . le début de l'intervalle
//   . la fin de l'intervalle
typedef struct
{
    // TODO
    int *res;
    int debut;
    int fin;
}ThreadData;

// Fonction support d'un thread
// Tous les threads lanceront cette fonction
// Code
//    le paramètre de la fonction est un void *
//    il faut le caster en ThreadData *
//    on calcule la somme des entiers (par exemple si l'intervalle
//        est [5, 9], il faut calculer 5+6+7+8+9)
//    on stocke le résultat dans la zone mémoire fournie
// TODO
void *codeThread(void * arg)
{
    assert(arg != NULL);
    ThreadData *data = (ThreadData *) arg;
    int res = 0;

    for (int i = data->debut; i <= data->fin ; i++) // On fait exceptionnellement un <= ici car on souhaite additionner tout l'intervalle
    {
        res += i;
        *(data)->res = res; // Stockage du résultat dans la zone mémoire
    }
    sleep(1);
    
    return NULL;
}

int main()
{
    int ret;
    // Débuts et fins des intervalles (attention si on change NB_THREADS)
    int debuts[NB_THREADS] = {3,  9, -3,  5};
    int fins[NB_THREADS]   = {7, 12,  2, 10};
    // tableau rempli par les threads
    int results[NB_THREADS];

    // On déclare ici un tableau de pthread_t pour stocker tous les
    // identifiants des threads
    // TODO
    pthread_t tabTid[NB_THREADS];
    // et un tableau de struct pour que chaque thread ait sa propre structure
    ThreadData datas[NB_THREADS];

    // pré-initialisation des données
    for (int i = 0; i < NB_THREADS; i++)
    {
        // il faut initialiser datas[i] avec :
        //   . un pointeur sur la ième case de results
        //   . le début de l'intervalle : debuts[i];
        //   . la fin de l'intervalle : fins[i]
        datas[i].res = &(results[i]);
        datas[i].debut = debuts[i];
        datas[i].fin = fins[i];
    }

    // lancement des threads
    for (int i = 0; i < NB_THREADS; i++)
    {
        // et donc on passe un pointeur sur une struct différente chaque fois
        // TODO
        ret = pthread_create(&(tabTid[i]), NULL, codeThread, &(datas[i]));
        assert(ret == 0);
    }

    // attente de la fin des threads
    // (testez le programme sans attente, éventuellement avec une
    //  temporisation dans le code du thread)
    for (int i = 0; i < NB_THREADS; i++)
    {
        // TODO
        ret = pthread_join(tabTid[i], NULL);
        assert(ret == 0);
    }

    // Affichages résultats
    printf("Fin thread principal : résultats\n");
    printf("Attendus : [");
    for (int i = 0; i < NB_THREADS; i++)
    {
        int res = 0;
        for (int v = debuts[i]; v <= fins[i]; v++)
            res += v;
        // ou sans boucle : res = b*(b+1)/2-(a-1)*a/2;
        if (i != 0)
            printf(", ");
        printf("%3d", res);
    }
    printf("]\n");
    printf("Obtenus  : [");
    for (int i = 0; i < NB_THREADS; i++)
    {
        if (i != 0)
            printf(", ");
        printf("%3d", results[i]);
    }
    printf("]\n");

    return EXIT_SUCCESS;
}