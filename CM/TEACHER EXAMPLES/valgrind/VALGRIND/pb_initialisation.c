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
    utilise(t, 3);
    free(t);
    
    return EXIT_SUCCESS;
}


/*

Donc on compile avec l'option -g

Sans valgrind, tout semble ok :
$ ./pb_initialisation 
0

Avec valgrind, il y a beaucoup de messages d'insulte (8 en tout)
qui ne sont pas faciles à lire et à peu près tous les mêmes.
Le premier est cependant suffisant pour comprendre l'erreur :
$ valgrind ./pb_initialisation 
==7494== Memcheck, a memory error detector
==7494== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==7494== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==7494== Command: ./pb_initialisation
==7494== 
==7494== Conditional jump or move depends on uninitialised value(s)
                                             ^^^^^^^^^^^^^
==7494==    at 0x4E87B93: vfprintf (vfprintf.c:1631)
==7494==    by 0x4E8F8A8: printf (printf.c:33)
==7494==    by 0x400609: utilise (pb_initialisation.c:11)
                         ^^^^^^^  ^^^^^^^^^^^^^^^^^^^ ^^
==7494==    by 0x400633: main (pb_initialisation.c:17)
==7494== 
==7494==  ...

Le message nous indique qu'on utilise une valeur non initialisée et
que le problème est à la ligne 11 du fichier pb_initialisation.c
dans la fonction "utilise".
Ce qui est amplement suffisant pour corriger le problème.

*/
