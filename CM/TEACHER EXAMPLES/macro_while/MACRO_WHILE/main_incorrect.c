#include <stdio.h>
#include <stdlib.h>

#include "macro_incorrecte.h"

int main()
{
    // ok
    REPETER("a", 5);

    // non
    if (1 == 1)
        REPETER("b", 5);
    else
        REPETER("c", 5);
    
    return EXIT_SUCCESS;
}
