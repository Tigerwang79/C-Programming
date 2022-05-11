// pour strdup
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "Jeu.h"

struct JeuP
{
    char *titre;
    int prix;
};

Jeu creer(const char *titre, int prix)
{
    assert(strcmp(titre, "") != 0);
    assert(prix >= 0);
    
    Jeu self = malloc(sizeof(struct JeuP));
    
    // ou strdup
    self->titre = malloc((strlen(titre)+1) * sizeof(char));
    strcpy(self->titre, titre);
    self->prix = prix;

    return self;
}

void detruire(Jeu *self)
{
    free((*self)->titre);
    free(*self);
    *self = NULL;
}

void setPrix(Jeu self, int prix)
{
    assert(prix >= 0);
    self->prix = prix;
}

int getPrix(const_Jeu self)
{
    return self->prix;
}

void setTitre(Jeu self, const char *titre)
{
    assert(strcmp(titre, "") != 0);
    
    // auto-affectation
    if (titre == self->titre)
        return;

    free(self->titre);
    self->titre = strdup(titre);
}

// c'est un problème de renvoyer un pointeur sur un membre de l'objet
const char * getTitre(const_Jeu self)
{
    return self->titre;
}

void affiche(const_Jeu self)
{
    printf("--------------------\n");
    printf("- titre : %s\n", self->titre);
    printf("- prix  : %d euro(s)\n", self->prix);
}
