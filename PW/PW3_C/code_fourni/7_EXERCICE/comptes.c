// todo : des include
#include <stdlib.h>
#include <stdio.h>
#include "comptes.h"
#include "operation.h"

// todo : définitions des constantes, types, variables, ...

#define N 10            // Définitions de notre nombre de comptes
int comptes[N];         // Tableau des soldes de chaque compte de la banque
static int soldeDefaut = 15;   // Comptes initialisés à 15€

/*
 * fonctions internes
 */

// gestion violente
// l'utilisation d'un assert serait plus élégante
// todo : la fonction est locale au fichier, y a-t-il quelque chose à faire ?

void verifNumCompte(int numCompte)
{
    if ((numCompte < 0) || (numCompte >= getNbComptes()))
    {
        fprintf(stderr, "numéro de compte incorrect.\n");
        exit(EXIT_FAILURE);
    }
}

//Initialisation du solde par défaut des comptes de la banque

void initComptes()
{
    for (int i = 0; i < getNbComptes(); i++)
    {
        comptes[i] = soldeDefaut;
    }
}

// todo : le reste du code

int getNbComptes()
{
    return N;
}

int getSoldeCompte(int numCompte)
{
    verifNumCompte(numCompte);
    return comptes[numCompte];
}

void creditCompte(int numCompte, int montant)
{
    verifNumCompte(numCompte);
    int compteActuel = getSoldeCompte(numCompte);
    comptes[numCompte] = plus(compteActuel, montant);
}

void debitCompte(int numCompte, int montant)
{
    verifNumCompte(numCompte);
    int compteActuel = getSoldeCompte(numCompte);
    comptes[numCompte] = moins(compteActuel, montant);
}