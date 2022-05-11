#define _XOPEN_SOURCE 500

#include <stdio.h>       // peut-être inutile
#include <stdlib.h>
#include <stdbool.h>     // peut-être inutile
#include <string.h>      // peut-être inutile
#include <assert.h>
// inclure les .h nécessaires

// note : la gestion mémoire est particulièrement brutale

// fonction qui sauvegarde un tableau de chaînes de caractères dans un fichier
void ecritTabChaines(const char *nomFichier, char * s[], int size)
{

    FILE * f1 = fopen(nomFichier, "w+");
    fwrite(&size, sizeof(int), 1, f1);
    for(int i = 0; i < size; i++)
    {
        int t = strlen(s[i]) + 1;
        fwrite(&t, sizeof(int), 1, f1);
        fwrite(s[i], sizeof(char), t, f1);
    }
    fclose(f1);
}


// fonction qui lit un tableau de chaînes de caractères
// size est un paramètre de sortie
void litTabChaines(const char *nomFichier, char * tab[], int *size)
{
    
    FILE * f1 = fopen(nomFichier, "r+");
    fread(size, sizeof(int), 1, f1);
    for(int i = 0; i < *size; i++)
    {
        int t;
        fread(&t, sizeof(int), 1, f1);
        fread(tab[i], sizeof(char), t, f1);
    }
    fclose(f1);
}


static int getNbChaine();
static char ** alloueInit();
static char ** alloue();
static void libere(char **tab);

int main()
{
    int n = getNbChaine();
    char **originaux = alloueInit();
    char **copies = alloue();

    // todo (cf. spoiler)

    int nCopies;

    ecritTabChaines("exoD_test", originaux, n);
    litTabChaines("exoD_test", copies, &nCopies);

    if (nCopies != n)
        printf("Pas le même nombre de chaînes.");
    else
    {
        for(int i = 0; i < nCopies; i++)
        {
            if (strcmp(originaux[i], copies[i]) == 0)
                printf("Tout est ok, les deux chaînes n°%d sont identiques\n", i);
            else
                printf("PB ! Les deux chaînes n°%d diffèrent\n", i);
        }
    }
    
    libere(originaux);
    libere(copies);
    
    return EXIT_SUCCESS;
}

/*
  SPOILER main

    int nbCopies;
    ecritTabChaines("exoD_test", originaux, n);
    litTabChaines("exoD_test", copies, &nbCopies);
    
    if (nbCopies != n)
        printf("PB ! mauvais nombre de chaînes lues\n");
    else
    {
        for (int i = 0; i < nbCopies; i++)
        {
            if (strcmp(originaux[i], copies[i]) == 0)
                printf("ok, les deux chaînes numéro %2d sont identiques\n", i);
            else
                printf("PB ! Les deux chaînes numéro %2d diffèrent\n", i);
        }
    }
*/


/* Gestion mémoire, inutile de regarder */

// surdimensionnement pour simplifier la gestion mémoire
#define EXO_D_LEN (1000 + 1)
#define EXO_D_NB 3

static int getNbChaine()
{
    return EXO_D_NB;
}

static char ** alloueInit()
{
    char *contenu[] = {"Bonjour monde !", "Atchoum", "Grincheux"};
    assert(sizeof(contenu)/sizeof(char *) == EXO_D_NB);
    
    char **tab = malloc(EXO_D_NB * sizeof(char *));
    for (int i = 0; i < EXO_D_NB; i++)
    {
        assert(strlen(contenu[i]) + 1 <= EXO_D_LEN);
        tab[i] = strdup(contenu[i]);
    }
        
    return tab;
}

static char ** alloue()
{
    char **tab = malloc(EXO_D_NB * sizeof(char *));
    for (int i = 0; i < EXO_D_NB; i++)
    {
        tab[i] = malloc(EXO_D_LEN * sizeof(char));
    }
        
    return tab;
}

static void libere(char **tab)
{
     for (int i = 0; i < EXO_D_NB; i++)
         free(tab[i]);
     free(tab);
}
