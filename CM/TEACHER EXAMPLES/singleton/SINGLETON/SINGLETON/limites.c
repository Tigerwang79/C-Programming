#include <stdio.h>
#include <stdlib.h>

#include "limites.h"

// question : comment libère-t-on la mémoire en fin de programme ?
// mais ce n'est pas le propos ici.

const char * getLimites()
{
    static char * phrase = NULL;

    if (phrase == NULL)
    {
        int maxInt = ~(1 << (8*sizeof(int)-1));
        int l = snprintf(NULL, 0, "MAX_INT = %d ; RAND_MAX = %d",
                         maxInt, RAND_MAX);
        phrase = malloc((l+1) * sizeof(char));
        sprintf(phrase, "MAX_INT = %d ; RAND_MAX = %d",
                maxInt, RAND_MAX);
    }

    return phrase;
}
