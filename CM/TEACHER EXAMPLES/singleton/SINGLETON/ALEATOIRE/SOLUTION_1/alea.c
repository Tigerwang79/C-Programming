#include <stdlib.h>
#include <time.h>

#include "alea.h"

void alea_init()
{
    srand(time(NULL));
}

int alea_get(int min, int max)
{
    return min + rand()%(max - min + 1);
}
