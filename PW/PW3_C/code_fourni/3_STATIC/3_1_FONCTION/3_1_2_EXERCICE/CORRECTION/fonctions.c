#include <stdio.h>

//## utilisable à l'extérieur du module
//## normalement devrait être déclarée dans fonctions.h
void f()
{
    printf("fonction globale\n");
}

//## locale au fichier courant
//## ne peut pas être appelée en dehors de fonctions.c
//## aucun sens de la déclarer dans fonctions.h (si le fichier existait)
static void g()
{
    printf("fonction statique\n");
}
