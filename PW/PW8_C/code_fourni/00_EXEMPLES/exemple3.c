/*
 * exemple 3
 *
 * On lance deux threads qui exécutent tous les deux la même fonction
 * en même temps.
 * Les threads reçoivent un pointeur sur une structure en paramètre
 */

#include <stdio.h>
#include <stdlib.h>
// inclure ici les .h nécessaires
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

// structure pour passer les paramètres aux pthread :
//   . deux float
//   . un pointeur sur une variable du main (celle nommée cpt)
typedef struct
{
    float a;
    float b;
    int *p;
} ThreadData;

// fonction support d'un thread
// le prototype est imposé
// dans cet exemple on utilise un paramètre qu'on sait être un "ThreadData *"
void * codeThread(void * arg)
{
    assert(arg != NULL);  // on ne peut pas faire mieux
    
    // immédiatement on cast dans le bon type
    ThreadData * pdata = (ThreadData *) arg;
    float res = pdata->a + pdata->b;
    
    // pour vérifier que le main attende bien la fin des threads
    sleep(1);
    printf("    -> Thread %g + %g = %g\n", pdata->a, pdata->b, res);
    // on a un pointeur sur une variable du main et on modifie cette variable
    // normalement devrait être en section critique
    *(pdata->p) += 1;
    
    return NULL;
}

int main()
{
    int ret;
    int cpt = 0;   // variable modifiée par les threads
    
    // On déclare ici les deux  identifiants des threads
    pthread_t tid1, tid2;
    // et les deux structures à transmettre (cf. tp pour savoir pourquoi on
    // on ne peut pas en utiliser une seule)
    ThreadData d1 = {3.14, 3.14, &cpt};
    ThreadData d2 = {3.14, 6.28, &cpt};

    // lancement des threads presque en même temps
    // - arg1 : on récupère l'identifiant du thread créé (paramètre en out donc)
    // - arg2 : toujours NULL pour nous
    // - arg3 : le nom de la fonction (un pointeur en fait) à lancer
    // - arg4 : l'argument à passer à cette fonction (qui est obligatoirement
    //          un pointeur). Ici c'est un pointeur sur un ThreadData
    ret = pthread_create(&tid1, NULL, codeThread, &d1);
    assert(ret == 0);
    ret = pthread_create(&tid2, NULL, codeThread, &d2);
    assert(ret == 0);

    // attente de la fin des threads
    ret = pthread_join(tid1, NULL);
    assert(ret == 0);
    ret = pthread_join(tid2, NULL);
    assert(ret == 0);

    // chaque thread a fait +1 dessus
    printf("Le compteur vaut %d (2 normalement)\n", cpt);
    
    printf("Fin thread principal\n");
    return EXIT_SUCCESS;
}
