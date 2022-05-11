#define _XOPEN_SOURCE 700 //afin d'éviter des problèmes de compilation
#include <stdio.h>       // peut-être inutile
#include <stdlib.h>
#include <stdbool.h>     // peut-être inutile
#include <string.h>      // peut-être inutile
// inclure les .h nécessaires
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// on utilise les fonctions fopen, fwrite et fclose

int main()
{
    int n1 = 1952540739;
    int n2 = 1130914164;

    printf("%x %X\n", n1, n2);

    // créer le fichier "exoB_1_test" et écrire dedans en binaire (avec fwrite) le nombre n1

    FILE * f1 = fopen("exoB_1_test", "w+");
    fwrite(&n1, sizeof(int), 1, f1);
    fclose(f1);

    // créer le fichier "exoB_2_test" et écrire dedans en binaire (avec fwrite) le nombre n2

    FILE * f2 = fopen("exoB_2_test", "w+");
    fwrite(&n2, sizeof(int), 1, f2);
    fclose(f2);

    printf("- Valeur en hexadécimal de notre premier entier %d : %x.\n", n1, n1);
    printf("- Valeur en hexadécimal de notre second entier %d : %x.\n", n2, n2);
    
    return EXIT_SUCCESS;
}