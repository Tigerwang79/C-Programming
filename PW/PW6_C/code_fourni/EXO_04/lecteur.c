#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void usage(const char *exeName, const char *message)
{
    fprintf(stderr, "usage : %s <nom tube>\n", exeName);
    if (message != NULL)
        fprintf(stderr, "message : %s\n", message);
    exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
    if (argc != 2)
        usage(argv[0], NULL);

    printf("Le tube doit exister avant le lancement du programme\n");

    // ouvrir avec "open" le tube en lecture (ne pas oublier le assert)
    //todo

    int fd = open(argv[1],O_RDONLY);
    char buffer;

    printf("le tube vient d'être ouvert en écriture\n");

    while(true)
    {
        // lire un caractère en testant si l'écrivain s'est terminé (et sortir
        // de la boucle dans ce cas ; cf. "man read") et afficher le caractère
        // todo
        read(fd, &buffer, 1);
        printf("%c", buffer);
    }

     // il ne faut pas oublier qqch ici
    // todo
    close(fd);
    return EXIT_SUCCESS;
}
