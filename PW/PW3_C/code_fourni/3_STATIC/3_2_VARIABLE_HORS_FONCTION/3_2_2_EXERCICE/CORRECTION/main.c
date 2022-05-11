#include <stdio.h>
#include <stdlib.h>

//## Indépendamment des warnings, seul l'accès à la variable static s échoue
//## On note que, contrairement aux fonctions, il est obligatoire de
//## de déclarer les variables globales. On parle d'un point de vue
//## technique ; d'un point de vue génie logiciel il est aussi obligatoire
//## de déclarer les fonctions.

//## Pour être linguistiquement exact, il n'y a pas d'erreur à la
//## compilation, mais uniquement à l'édition de liens

extern int g;  //## devrait normalement être dans le fichier variables.h
extern int s;  //## cette déclaration n'a pas de sens pour une variable static
               //## à commenter pour obtenir l'exécutable

int main()
{
    printf("%d\n", g);
    printf("%d\n", s);   //## à commenter pour obtenir l'exécutable
    
    return EXIT_SUCCESS;
}
