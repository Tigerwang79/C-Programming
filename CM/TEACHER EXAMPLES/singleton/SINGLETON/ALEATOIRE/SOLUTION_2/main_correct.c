#include <stdio.h>
#include <stdlib.h>

#include "alea.h"

// utilisation correcte

int main()
{
    // on pense bien à appeler alea_init en début et une seule fois
    alea_init();
    
    // une série de nombres aléatoires
    for (int i = 0; i < 7; i++)
    {
        int n = alea_get(15, 18);
        printf("tirage %d : %2d\n", i+1, n);
    }
    
    return EXIT_SUCCESS;
}
