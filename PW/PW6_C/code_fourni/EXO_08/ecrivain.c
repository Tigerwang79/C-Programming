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

    printf("[père] Je suis le père %d (après exec)\n", getpid());

    int a, b;

    printf("[père] Entrez deux entiers : ");
    scanf("%d %d", &a, &b);
    
    // Ecrire, dans le file descriptor contenu dans argv[1] les deux entiers
    // en mode binaire (toujours avec des assert)
    //todo

    // ne pas oublier de fermer le file descriptor
    //todo
    
    // on pourrait envisager un wait ici

    return EXIT_SUCCESS;
}
