/*
 * exemple 1
 *
 * On lance deux threads qui exécutent tous les deux la même fonction
 * en même temps.
 * Les threads ne reçoivent pas de paramètres
 */

#include <stdio.h>
#include <stdlib.h>
// inclure ici les .h nécessaires
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>


// fonction support d'un thread
// le prototype est imposé
// dans cet exemple on n'utilise pas le paramètre
// note : 2 threads sont lancés avec ce code : ils s'exécutent en parallèle
void * codeThread(void * arg)
{
    assert(arg == NULL);
    
    // pour vérifier que le main attende bien la fin des threads
    sleep(1);
    printf("-> Thread de tid %ld\n", pthread_self());
    return NULL;
}

int main()
{
    int ret;
    
    // On déclare ici les deux  identifiants des threads
    pthread_t tid1, tid2;

    // lancement des threads presque en même temps
    // - arg1 : on récupère l'identifiant du thread créé (paramètre en out donc)
    // - arg2 : toujours NULL pour nous
    // - arg3 : le nom de la fonction (un pointeur en fait) à lancer
    // - arg4 : l'argument à passer à cette fonction (NULL ici)
    // Donc un thread est créé et le main continue immédiatement
    // sans attendre la fin du thread
    ret = pthread_create(&tid1, NULL, codeThread, NULL);
    assert(ret == 0);
    ret = pthread_create(&tid2, NULL, codeThread, NULL);
    assert(ret == 0);

    // attente de la fin des threads (équivalent du wait pour les fork)
    // (testez le programme en commentant ces instructions)
    // Vu le code des threads, on va attendre 1 seconde (et non deux)
    // Si on avait lancé 150 threads, on aurait attendu 1 seconde (et non 150)
    ret = pthread_join(tid1, NULL);
    assert(ret == 0);
    printf("Fin thread de tid %ld\n", tid1);
    ret = pthread_join(tid2, NULL);
    assert(ret == 0);
    printf("Fin thread de tid %ld\n", tid2);

    printf("Fin thread principal\n");
    return EXIT_SUCCESS;
}
