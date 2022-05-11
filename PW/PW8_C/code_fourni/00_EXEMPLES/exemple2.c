/*
 * exemple 2
 *
 * On lance deux threads qui exécutent tous les deux la même fonction
 * en même temps.
 * Les threads reçoivent un "float *" en paramètre
 * l'ordre d'affichage est indéterminé (ce n'est pas obligatoirement le
 *     le premier thread qui s'affiche en premier)
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
// dans cet exemple on utilise un paramètre qu'on sait être un "float *"
void * codeThread(void * arg)
{
    assert(arg != NULL);  // on ne peut pas faire mieux
    
    // immédiatement on cast dans le bon type
    float * pval = (float *) arg;
    
    // pour vérifier que le main attende bien la fin des threads
    sleep(1);
    printf("    -> Thread avec %g\n", *pval);
    return NULL;
}

int main()
{
    int ret;
    
    // On déclare ici les deux  identifiants des threads
    pthread_t tid1, tid2;
    // et les deux float à transmettre
    float r1 = 3.14;
    float r2 = 6.28;

    // lancement des threads presque en même temps
    // - arg1 : on récupère l'identifiant du thread créé (paramètre en out donc)
    // - arg2 : toujours NULL pour nous
    // - arg3 : le nom de la fonction (un pointeur en fait) à lancer
    // - arg4 : l'argument à passer à cette fonction (qui est obligatoirement
    //          un pointeur). Ici c'est un pointeur sur un float
    ret = pthread_create(&tid1, NULL, codeThread, &r1);
    assert(ret == 0);
    ret = pthread_create(&tid2, NULL, codeThread, &r2);
    assert(ret == 0);

    // attente de la fin des threads
    ret = pthread_join(tid1, NULL);
    assert(ret == 0);
    ret = pthread_join(tid2, NULL);
    assert(ret == 0);

    printf("Fin thread principal\n");
    return EXIT_SUCCESS;
}
