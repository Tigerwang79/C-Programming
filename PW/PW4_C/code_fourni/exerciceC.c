#include <stdio.h>       // peut-être inutile
#include <stdlib.h>
#include <stdbool.h>     // peut-être inutile
#include <string.h>      // peut-être inutile
// inclure les .h nécessaires

void ecritChaine(const char *nomFichier, const char *s)
{
    int t = strlen(s) + 1;
    FILE * f1 = fopen(nomFichier, "w+");
    fwrite(&t, sizeof(int), 1, f1);
    fwrite(s, sizeof(char), t, f1);
    fclose(f1);
}

void litChaine(const char *nomFichier, char *s)
{
    int t;
    FILE * f1 = fopen(nomFichier, "r+");
    fread(&t, sizeof(int), 1, f1);
    fread(s, sizeof(char), t, f1);
    fclose(f1);
}

int main()
{
    // note : on ne gère pas ici la mémoire, ce n'est pas le but de l'exercice
    char original[1000] = "Bonjour monde !";
    char copie[1000];
    
    // todo (cf. spoiler ci-dessous)

    ecritChaine("exoC_test", original);
    litChaine("exoC_test", copie);

    if (strcmp(original, copie) == 0)
        printf("Tout est ok, les deux chaînes sont identiques\n");
    else
        printf("PB ! Les deux chaînes diffèrent\n");    
    
    return EXIT_SUCCESS;
}