#include <stdio.h>       // peut-être inutile
#include <stdlib.h>
#include <stdbool.h>     // peut-être inutile
#include <string.h>      // peut-être inutile
// inclure les .h nécessaires


void ecritTabIntAsc(const char *nomFichier, const int tab[], int n)
{
    // todo
    // rq : pas moyen de faire l'écriture d'un coup, il faut les écrire un par un
    FILE * file = fopen(nomFichier, "w+");
    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%d ", tab[i]);
    }
    fclose(file);
}

int litIntPosAsc(const char *nomFichier, int pos)
{
    // todo
    // rq : il faut les lire un par un jusqu'à la bonne position
    FILE * file = fopen(nomFichier, "r+");
    int nb = -1;
    for (int i = 0; i < pos + 1; i++)
    {
        int tmp;
        int ret;
        
        ret = fscanf(file, "%d", &tmp);
        if (ret == EOF)
            break;
        if (i == pos)
            nb = tmp;
    }
    fclose(file);

    return nb;
}

bool remplaceIntPosAsc(const char *nomFichier, int pos, int newVal)
{
    int i = 0; 
    int nbr = 0;
    int tab[1000];      // Explication: int tab[1000] afin de prévoir suffisamment de place.
    bool valfind = false;
    FILE *file = fopen(nomFichier,"r+");

    while(fscanf(file,"%i ", &nbr) != -1)   // Explication: On va remplir ici notre tableau de int
    {
        tab[i] = nbr;
        i++;
    }
    fclose(file);

    if (i != 0)     // Explication: condition si notre compteur est nulle alors il n'y a pas de données trouvé dans le fichier.
    {
        remove(nomFichier);
        file = fopen(nomFichier,"w+");
        tab[pos] = newVal; // Explication: on va modifier ici la valeur.
        for(int j = 0; j< i; j++)
        {
            fprintf(file, "%i ", tab[j]);
        }
        valfind = true;
        fclose(file);
    }
    return valfind;
}

int main()
{
    int tab[] = {10, 5, 87, 0, 5, 212, 12, 14, 55};
    int n = sizeof(tab)/sizeof(*tab);

    // écrire le tableau dans le fichier exoF_test
    // todo

    ecritTabIntAsc("exoF_test", tab, n);

    // remplacer la case 2 (donc le 87) par 777
    // todo

    remplaceIntPosAsc("exoF_test", 2, 777);

    // remplacer la case 9 (indice trop grand) par 66 : il ne se passe rien
    // todo

    remplaceIntPosAsc("exoF_test", 9, 66);

    // remplacer la cse 0 (donc le 10) par 1111
    // todo

    remplaceIntPosAsc("exoF_test", 0, 1111);

    // afficher le contenu du fichier en utilisant la fonction litIntPosAsc
    // todo

    printf("[");
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            printf(", ");
        }
        printf("%d", litIntPosAsc("exoF_test", i));
    }
    printf("]\n");
    
    return EXIT_SUCCESS;
}