#include <stdio.h>
#include <stdlib.h>

int main()
{
    // construire le tableau d'arguments à passer dans le execv
    // donc les arguements sont "-l" et "-h"
    //todo

    // appeler execv avec "/bin/ls"
    //todo
    
    // si on est là, execv obligatoirement renvoyé -1
    perror("Problème exec");
    
    return EXIT_SUCCESS;
}
