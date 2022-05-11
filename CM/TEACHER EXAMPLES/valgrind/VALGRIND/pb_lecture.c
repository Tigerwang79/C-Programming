#include <stdio.h>
#include <stdlib.h>

int * alloue(int n)
{
    return malloc(n * sizeof(int));
}

void utilise(int tab[], int pos)
{
    printf("%d\n", tab[pos]);
}

int main()
{
    int *t = alloue(10);
    utilise(t, 10);   // donc une case trop loin
    free(t);
    
    return EXIT_SUCCESS;
}


/*
  Ce sont exactement les mêmes commentaires que pour pb_ecriture.c
*/
