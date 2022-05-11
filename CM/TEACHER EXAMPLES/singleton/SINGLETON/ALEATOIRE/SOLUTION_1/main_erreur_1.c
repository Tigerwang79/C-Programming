#include <stdio.h>
#include <stdlib.h>

#include "alea.h"

// utilisation erronée : on appelle init avant chaque appel à get
// donc on tire toujours le même nombre

int main()
{
    // c'est ici qu'il aurait fallu appeler alea_init
    
    // une série de nombres aléatoires
    for (int i = 0; i < 7; i++)
    {
        // NON : il ne fallait l'appeler qu'une seule fois et pas ici
        alea_init();
        int n = alea_get(15, 18);
        printf("tirage %d : %2d\n", i+1, n);
    }
    
    return EXIT_SUCCESS;
}
