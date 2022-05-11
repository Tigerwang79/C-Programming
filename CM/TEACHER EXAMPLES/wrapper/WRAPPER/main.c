#include <stdio.h>
#include <stdlib.h>

#include "produit.h"

int main()
{
    float t1[] = {2.f, 3.f, 4.f, 5.f};
    int taille = sizeof(t1) / sizeof(*t1);
    float r;

    r = produit(t1, taille);
    printf("résultat : %g\n", r);
    
    return EXIT_SUCCESS;
}
