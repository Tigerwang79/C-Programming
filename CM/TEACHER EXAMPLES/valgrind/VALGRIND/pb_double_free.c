#include <stdio.h>
#include <stdlib.h>

int * alloue(int n)
{
    return malloc(n * sizeof(int));
}

void desalloue(void *p)
{
    free(p);
}

int main()
{
    int *t = alloue(10);
    t[0] = 99;
    desalloue(t);
    free(t);     // donc deuxième free
    
    return EXIT_SUCCESS;
}


/*

Donc on compile avec l'option -g

Sans valgrind, on a une série impressionnante de messages d'insultes :
$ ./pb_double_free 
*** Error in `./pb_double_free': double free or corruption (fasttop): 0x0000000000db4010 ***
======= Backtrace: =========
/lib/x86_64-linux-gnu/libc.so.6(+0x777f5)[0x7f8c95d2c7f5]
...
Abandon (core dumped)

Et d'ailleurs la première ligne indique bien le problème probable, ce
qui est déjà très bien.
Mais il n'y aucune indication sur la localisation du problème.


Avec valgrind, il y a toutes les informations :
$ valgrind ./pb_double_free 
==10691== Memcheck, a memory error detector
==10691== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==10691== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==10691== Command: ./pb_double_free
==10691== 
==10691== Invalid free() / delete / delete[] / realloc()
          ^^^^^^^^^^^^
==10691==    at 0x4C2EDEB: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==10691==    by 0x4005D6: main (pb_double_free.c:19)
                          ^^^^  ^^^^^^^^^^^^^^^^ ^^
==10691==  Address 0x5204040 is 0 bytes inside a block of size 40 free'd
                                        ^^^^^^^^^^^^^^            ^^^^^^
==10691==    at 0x4C2EDEB: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==10691==    by 0x40059B: desalloue (pb_double_free.c:11)
                          ^^^^^^^^^  ^^^^^^^^^^^^^^^^ ^^
==10691==    by 0x4005CA: main (pb_double_free.c:18)
==10691==  Block was alloc'd at
==10691==    at 0x4C2DB8F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==10691==    by 0x400581: alloue (pb_double_free.c:6)
                          ^^^^^^  ^^^^^^^^^^^^^^^^ ^
==10691==    by 0x4005B0: main (pb_double_free.c:16)

Voici les indications :
- il y a un "free" invalide
- il eu lieu dans la fonction "main" du fichier pb_double_free.c à la ligne 19
  C'est donc le deuxième "free" qui est incriminé, ce qui est logique car
  le premier était tout à fait valide.
- il est indiqué où a eu lieu le premier free :
  fonction "desalloue" du fichier pb_double_free.c à la ligne 11
- et il est indiqué où a lieu le malloc :
  fonction "alloue" du fichier pb_double_free.c à la ligne 6

Il n'y a plus qu'à choisir quel "free" on garde.
*/
