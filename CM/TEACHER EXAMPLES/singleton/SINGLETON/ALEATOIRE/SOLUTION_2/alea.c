#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "alea.h"

void alea_init()
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
    return min + rand()%(max - min + 1);
}
