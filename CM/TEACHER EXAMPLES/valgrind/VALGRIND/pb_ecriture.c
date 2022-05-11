#include <stdio.h>
#include <stdlib.h>

int * alloue(int n)
{
    return malloc(n * sizeof(int));
}

void utilise(int tab[], int pos)
{
    tab[pos] = 99;
}

int main()
{
    int *t = alloue(10);
    utilise(t, 10);   // donc une case trop loin
    free(t);
    
    return EXIT_SUCCESS;
}


/*

Donc on compile avec l'option -g

Sans valgrind, tout semble ok :
$ ./pb_ecriture 


Avec valgrind, il y a un message qui donne une grande quantité d'informations.
$ valgrind ./pb_ecriture 
==9091== Memcheck, a memory error detector
==9091== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==9091== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==9091== Command: ./pb_ecriture
==9091== 
==9091== Invalid write of size 4
         ^^^^^^^^^^^^^    ^^^^^^
==9091==    at 0x4005A3: utilise (pb_ecriture.c:11)
                         ^^^^^^^  ^^^^^^^^^^^^^ ^^
==9091==    by 0x4005D2: main (pb_ecriture.c:17)
==9091==  Address 0x5204068 is 0 bytes after a block of size 40 alloc'd
                               ^^^^^^^^^^^^^   ^^^^^    ^^^^^^^
==9091==    at 0x4C2DB8F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==9091==    by 0x400581: alloue (pb_ecriture.c:6)
                         ^^^^^^  ^^^^^^^^^^^^^ ^
==9091==    by 0x4005BD: main (pb_ecriture.c:16)

On a la localisation de l'erreur :
- fonction "utilise" dans le fichier pb_ecriture.c à la ligne 11
Et le type d'erreur :
- problème d'écriture de 4 octets

Et on a également des informations extrêmement importantes et précises
qui permettent de corriger l'erreur "facilement" :
- l'écriture a eu lieu après un bloc alloué de taille 40 octets
- et juste après ce bloc (0 bytes after)
- (bref on peut intuiter un indice qui est allé un cran trop loin)
Et on indique même où a été alloué ce bloc :
- fonction "alloue" dans le fichier pb_ecriture.c à la ligne 6


Notez que non seulement valgrind indique le ficher, la fonction et le
numéro de la ligne incriminée, mais également la pile d'appels.
Dans notre cas, l'écriture invalide a donc lieu :
- dans la fonction "utilise" (fichier pb_ecriture.c ligne 11)
Et cette fonction "utilise" a été appelée par :
- la fonction "main" (fichier pb_ecriture.c ligne 17)
*/
