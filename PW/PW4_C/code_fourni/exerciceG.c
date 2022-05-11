#include <stdio.h>       // peut-être inutile
#include <stdlib.h>
#include <stdbool.h>     // peut-être inutile
#include <string.h>      // peut-être inutile
// inclure les .h nécessaires

struct S
{
    int i;
    char c;
    float f;
    int tab[10];
};

void ecritStructBin(const char *nomFichier, const struct S *s)
{
    // todo (une seule instruction d'écriture)
}

void litStructBin(const char *nomFichier, struct S *s)
{
    // todo (une seule instruction de lecture)
}

void tailleStruct()
{
    // todo
}

int main()
{
    struct S original = {42, 'a', 3.14159, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}};
    struct S copie;

    // écrire la structure "original" dans le fichier exoG_test
    // todo

    // lire le fichier et remplir la structure "copie"
    // todo

    // comparer les deux structures
    // todo

    // appeler la fonction tailleStruct
    // todo

    return EXIT_SUCCESS;
}


/*
  SPOILER main

    // écrire la structure "original" dans le fichier exoG_test
    // todo
    ecritStructBin("exoG_test", &original);

    // lire le fichier et remplir la structure "copie"
    // todo
    litStructBin("exoG_test", &copie);

    // comparer les deux structures
    // todo
    if (memcmp(&original, &copie, sizeof(struct S)) == 0)
        printf("Ok les structures sont identiques\n");
    else
        printf("PB ! Les structures sont différentes\n");
        
    // appeler la fonction tailleStruct
    // todo
    tailleStruct();
*/
