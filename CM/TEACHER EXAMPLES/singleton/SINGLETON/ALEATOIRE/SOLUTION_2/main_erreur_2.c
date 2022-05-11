#include <stdio.h>
#include <stdlib.h>

#include "alea.h"

// utilisation erronée : on oublie l'appel à init
// donc à chaque appel de l'exécutable on sort les mêmes nombres

int main()
{
    // AIE AIE : on oublie d'appeler init
    
    // une série de nombres aléatoires
    for (int i = 0; i < 7; i++)
    {
        int n = alea_get(15, 18);
        printf("tirage %d : %2d\n", i+1, n);
    }
    
    return EXIT_SUCCESS;
}
