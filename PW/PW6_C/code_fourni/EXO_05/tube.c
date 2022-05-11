#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h> 

void recepteur(int fds[2])
{
    printf("Je suis le récepteur %d\n", getpid());
    
    // fermeture de l'extrémité inutile
    //todo (ne pas oublier les assert)
    close(fds[1]);

    // on applique le protocole suivant :
    // on reçoit d'abord la taille de la chaine
    // on alloue la place nécessaire
    // on reçoit en une fois la chaîne
    //todo (attention aux fuites mémoire)
    char *s = NULL;
    int lgth;
    int res;

    res = read(fds[0], &lgth, sizeof(int));
    assert(res == sizeof(int));

    s = malloc(lgth * sizeof(char));
    
    res = read(fds[0], s, lgth * sizeof(char));
    assert(res == (int) (lgth * sizeof(char)));
    
    printf("Récepteur : lecture de %d caractère(s) : \"%s\"\n", lgth, s);
    free(s);
    // fermeture de l'extrémité restante
    //todo
    close(fds[0]);

    // pour ne pas retourner dans le main
    exit(EXIT_FAILURE);
}

void envoyeur(int fds[2], const char * s)
{
    printf("    Je suis l'envoyeur %d\n", getpid());
    
    // fermeture de l'extrémité inutile
    //todo
    close (fds[0]);

    // protocole : cf. fonction précédente
    //todo
    int 
    
    // fermeture de l'extrémité restante
    //todo
    
    // pour ne pas retourner dans le main
    exit(EXIT_FAILURE);
}


int main()
{
    // on déclare la chaîne en dur pour se concentrer sur la communication
    const char * const s = "Bonjour monde !";

    // création du tube
    //todo
    int pipefd[2];
    pid_t cpid;
    pipe(pipefd);
    cpid = fork();

    // on commence par le récepteur mais c'est arbitraire
    // donc fork et dans le fils on appelle recepteur
    //todo
    
    // puis l'envoyeur
    // donc fork et dans le fils on appelle envoyeur
    //todo
        
    // le père n'utilise pas le tube
    //todo

    if(cpid == 0)
    {
        close(pipefd[0]);
        write(pipefd[1], &s, 7);     // ici on met une taille de 7 pour contenir le mot bonjour
    }
    else
    {
        wait(NULL);
        char buffer;
        close(pipefd[1]);

        while(read(pipefd[0], &buffer,1) > 0)
        {

            printf("%c", &buffer);
        }
        printf("\n");
    }

    printf("Le père se met en attente de la fin des fils\n");
    //todo

    printf("fin processus père %d\n", getpid());
    
    return EXIT_SUCCESS;
}
