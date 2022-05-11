#include <stdio.h>
#include <stdlib.h>

int * alloue(int n)
{
    return malloc(n * sizeof(int));
}

int main()
{
    int *t = alloue(10);
    t[0] = 99;
    // on oublie le free
    
    return EXIT_SUCCESS;
}


/*

Donc on compile avec l'option -g

Sans valgrind, tout semble ok et la fuite est indétectable :
$ ./pb_fuite


Avec valgrind, il y a un message qui indique le nombre (et l'importance)
des fuites, mais pas leurs origines :
$ valgrind ./pb_fuite
==10115== Memcheck, a memory error detector
==10115== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==10115== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==10115== Command: ./pb_fuite
==10115== 
==10115== 
==10115== HEAP SUMMARY:
==10115==     in use at exit: 40 bytes in 1 blocks
==10115==   total heap usage: 1 allocs, 0 frees, 40 bytes allocated
                              ^^^^^^^^  ^^^^^^^  ^^^^^^^^
==10115== ...
==10115== Rerun with --leak-check=full to see details of leaked memory

Donc 1 allocation et 0 libération, soit une fuite de 40 octets
Ceci dit avec ces informations ce serait très long (dans un vrai projet)
de trouver l'origine de la fuite.

Relançons valgrind avec l'option suggérée :
$ valgrind --leak-check=full ./pb_fuite 
==10141== Memcheck, a memory error detector
==10141== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==10141== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==10141== Command: ./pb_fuite
==10141== 
==10141== 
==10141== HEAP SUMMARY:
==10141==     in use at exit: 40 bytes in 1 blocks
==10141==   total heap usage: 1 allocs, 0 frees, 40 bytes allocated
                              ^^^^^^^^  ^^^^^^^  ^^^^^^^^
==10141== 
==10141== 40 bytes in 1 blocks are definitely lost in loss record 1 of 1
==10141==    at 0x4C2DB8F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==10141==    by 0x400541: alloue (pb_fuite.c:6)
                          ^^^^^^  ^^^^^^^^^^ ^
==10141==    by 0x400555: main (pb_fuite.c:11)

L'information où le malloc a été fait est fournie :
- fonction "alloue" dans le fichier pb_fuite.c à la ligne 6

En revanche valgrind ne peut pas nous indiquer où l'on doit faire
le "free".
*/
