#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>

static void usage(const char *exeName, const char *message)
{
    fprintf(stderr, "usage : %s <fd>\n", exeName);
    if (message != NULL)
        fprintf(stderr, "message : %s\n", message);
    exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
    if (argc != 2)
        usage(argv[0], NULL);

    printf("    [fils] Je suis le fils %d (après exec)\n", getpid());

    // Lire, dans le file descriptor contenu dans argv[1] deux entiers en
    // mode binaire (toujours avec des assert)
    //todo

    // ne pas oublier de fermer le file descriptor
    //todo

    // afficher la somme
    //todo

    return EXIT_SUCCESS;
}
