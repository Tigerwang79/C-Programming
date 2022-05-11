/*
* Le code illustre le problème d'une mauvaise conception.
* 
* Rappel : 2 programmeurs sont concernés :
* - le concepteur de la bibliothèque (biblio.h et biblio.c)
* - l'utilisateur de la bibliothèque (celui qui écrit main.c)
* 
* L'utilisateur a uniquement un accès en lecteurs aux fichiers biblio.h
* et biblio.c
* 
* 
* Hypothèses :
* - le concepteur ne maitrise pas les const (où il pense que c'est
*   inutile ce qui revient au même) et n'en met pas.
* - l'utilisateur codee propremement et utilise les const
* 
* L'utilisateur va passer une variable constante à une fonction
* qui ne la déclare pas constante : erreur de compilation.
*/

#include <stdio.h>
#include <stdlib.h>

#include "biblio.h"

int main()
{
    const char * const msg = "bonjour";
    // pb de compilation à cause d'une mauvaise conception de la bibliothèque :
    // - la prototype de "affiche" laisse supposer que message sera modifiée
    // - mais comme msg est constante, le compilation faire une erreur.
    affiche(msg);
    
    // Il faudrait corriger biblio.h et biblio.c, mais on part du principe
    // qu'on en a pas les droits.
    // seule solution : un cast peu élégant (et injustifié)
    affiche((char *) msg);

    return EXIT_SUCCESS;
}
