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

    // ouvrir avec "open" le tube en écriture (ne pas oublier le assert)
    //todo
    int fd = open(argv[1], O_WRONLY);

    printf("Le tube est ouvert en écriture\n");

    printf("Saisissez des caractères. '!' pour terminer\n");

    while(true)
    {
        char c = getchar();
        if (c == '!')
            break;
        // écrire dans le tube (avec un assert)
        //todo
        write(fd, &c, 1);
    }

    // il ne faut pas oublier qqch ici
    // todo
    close(fd);    
    return EXIT_SUCCESS;
}
