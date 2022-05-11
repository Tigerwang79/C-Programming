#include <stdio.h>
#include <stdlib.h>

#include "memory.h"

int main()
{
    int *pt;
    MY_MALLOC(pt, int, 10);
    printf("valeur pointeur : %p\n", (void *) pt);
    
    // ...
    
    MY_FREE(pt);
    printf("valeur pointeur : %p\n", (void *) pt);

    return EXIT_SUCCESS;
}
