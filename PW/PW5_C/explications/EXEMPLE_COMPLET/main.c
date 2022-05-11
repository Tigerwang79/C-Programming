#include <stdio.h>
#include <stdlib.h>

#include "Jeu.h"

int main()
{
    Jeu j1, j2;

    j1 = creer("Mass Effect 1", 49);
    j2 = creer("Life is strange", 25);

    setPrix(j2, 19);
    setTitre(j2, "Life is Strange!");
    printf("titre : %s\n", getTitre(j2));
    printf("prix  : %d\n", getPrix(j2));

    affiche(j1);
    affiche(j2);

    detruire(&j1);
    detruire(&j2);
    
    return EXIT_SUCCESS;
}
