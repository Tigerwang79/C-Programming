// pour des problèmes de compilation
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


void un(/* il faut le sémaphore en paramètre */)
{
    sleep(3);
    printf("Processus un   %d ! (normalement je m'affiche en premier)\n", getpid());
    
    // ici il faut débloquer le processus "deux"
}

void deux(/* il faut le sémaphore en paramètre */)
{
    // ici il faut attendre le déblocage venant de "un"
    
    printf("Processus deux %d ! (normalement je m'affiche en dernier)\n", getpid());
}

int main()
{
    // ici il faut déclarer un sémaphore (en mode IPC_PRIVATE) et l'initialiser
    // voyez-vous pourquoi il faut créer le sémaphore ici et non pas
    // dans les fonctions un et deux ?
    pid_t retFork;

    retFork = fork();
    assert(retFork != -1);
    if (retFork != 0)
        un(/* on passe le sémaphore en paramètre */);
    else
        deux(/* on passe le sémaphore en paramètre */);

    // attente de la fin du fils
    if (retFork != 0)
        wait(NULL);

    // ici il faut détruire le sémaphore
    // chaque processus doit-il le détruire ?
    // sinon qui doit s'en charger ?

    if (retFork != 0)
        printf("Fin de un   (%d)\n", getpid());
    else
        printf("Fin de deux (%d)\n", getpid());
    
    return EXIT_SUCCESS;
}
