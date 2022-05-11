#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "alea.h"

// méthode locale au module
static void alea_init()
{
    static bool first = true;
    if (first)
    {
        srand(time(NULL));
        first = false;
    }
}

int alea_get(int min, int max)
{
    // appelle systématiquement alea_init, mais seule le premier
    // appel a un effet
    alea_init();
    return min + rand()%(max - min + 1);
}
