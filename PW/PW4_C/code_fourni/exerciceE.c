#include <stdio.h>       // peut-être inutile
#include <stdlib.h>
#include <stdbool.h>     // peut-être inutile
#include <string.h>      // peut-être inutile
// inclure les .h nécessaires

void ecritTabIntBin(const char *nomFichier, const int tab[], int n)
{
    FILE * f1 = fopen(nomFichier, "w+");
    fwrite(tab, sizeof(int), n, f1);
    fclose(f1);
}

int litIntPosBin(const char *nomFichier, int pos)
{
    FILE * f1 = fopen(nomFichier, "r+");
    int t;
    int val = -1 ;
    fseek(f1, 0, SEEK_END);
    t = ftell(f1) / sizeof(int);
    
    if (pos < t)
    {
        fseek(f1, pos * sizeof(int), SEEK_SET);
        fread(&val, sizeof(int), 1, f1);
    }
    fclose(f1);

    return val;
}

bool remplaceIntPosBin(const char *nomFichier, int pos, int newVal)
{
    FILE * f1 = fopen(nomFichier, "r+");
    bool state = false;
    int t;

    fseek(f1, 0, SEEK_END);
    t = ftell(f1) / sizeof(int);

    if (pos < t)
    {
        state = true;
        fseek(f1, pos * sizeof(int), SEEK_SET);
        fwrite(&newVal, sizeof(int), 1, f1);
    }
    fclose(f1);

    return state;
}

int main()
{
    int tab[] = {10, 5, 87, 0, 5, 212, 12, 14, 55};
    int n = sizeof(tab)/sizeof(*tab);

    // écrire le tableau dans le fichier exoE_test
    // todo

    ecritTabIntBin("exoE_test", tab, n);

    // remplacer la case 2 (donc le 87) par 777
    // todo

    remplaceIntPosBin("exoE_test", 2, 777);

    // remplacer la case 9 (indice trop grand) par 66 : il ne se passe rien
    // todo

    remplaceIntPosBin("exoE_test", 9, 66);

    // remplacer la cse 0 (donc le 10) par 1111
    // todo

    remplaceIntPosBin("exoE_test", 0, 1111);

    // afficher le contenu du fichier en utilisant la fonction litIntPosBin
    // todo

    printf("[");
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            printf(", ");
        }
        printf("%d", litIntPosBin("exoE_test", i));
    }
    printf("]\n");
    
    return EXIT_SUCCESS;
}


/*
  SPOILER main

    // écrire le tableau dans le fichier exoE_test
    ecritTabIntBin("exoE_test", tab, n);

    // remplacer la case 2 (donc le 87) par 777
    remplaceIntPosBin("exoE_test", 2, 777);
    // remplacer la case 9 (indice trop grand) par 66 : il ne se passe rien
    remplaceIntPosBin("exoE_test", 9, 66);
    // remplacer la cse 0 (donc le 10) par 1111
    remplaceIntPosBin("exoE_test", 0, 1111);

    // afficher le contenu du fichier en utilisant la fonction litIntPosBin
    printf("  [");
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            printf(", ");
        printf("%d", litIntPosBin("exoE_test", i));
    }
    printf("]\n");
*/
