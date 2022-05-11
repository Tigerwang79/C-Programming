#include <stdio.h>
#include <stdlib.h>

#include "ImageMono.h"

int main()
{
    ImageMono im;

    init(&im, 20, 30, "bleu");
    setCouleur(&im, "vert");
    printf("(%d, %d) : %s\n", getLargeur(&im), getHauteur(&im), getCouleur(&im));
    //## Le problème (cf. .h) est qu'on a ici accès directement au contenu
    //## de la structure (i.e. sans passer par les méthodes) et qu'on peut
    //## modifier la hauteur ou la largeur alors que c'est interdit.
    //## Dans un langage objet ces attributs seraient "private" et il
    //## n'y aurait plus de problème.
    //## En C on peut utiliser l'abstraction pointeur pour pallier ce problème.

    return EXIT_SUCCESS;
}
