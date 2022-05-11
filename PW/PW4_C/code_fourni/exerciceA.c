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

int main()
{
    char buffer[]="12";

    // avec open, dprintf et close, créer le fichier "exoA_1_test" et écrire l'entier 12 dedans

    int f1 = open("exoA_1_test", O_RDWR);
    dprintf(f1, "%s", "12");
    close(f1);
    
    // avec open, write et close, créer le fichier "exoA_2_test" et écrire l'entier 12 dedans

    int f2 = open("exoA_2_test", O_RDWR);
    write(f2, "12", sizeof(buffer));
    close(f2);

    // avec fopen, fprintf et fclose, créer le fichier "exoA_3_test" et écrire l'entier 12 dedans
    
    FILE * f3 = fopen("exoA_3_test", "w+");
    fprintf(f3, "%s", "12");
    fclose(f3);

    // avec fopen, fwrite et fclose, créer le fichier "exoA_4_test" et écrire l'entier 12 dedans
    
    FILE * f4 = fopen("exoA_4_test", "w+");
    fwrite(&buffer, sizeof(buffer), 1, f4);
    fclose(f4);

    return EXIT_SUCCESS;
}