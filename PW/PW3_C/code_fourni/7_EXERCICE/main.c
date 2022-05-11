#include <stdio.h>
#include <stdlib.h>

// INCLURE ICI LES DEUX .h 
#include "operation.h"
#include "comptes.h"

int dummy = 14;     // Attention l'énoncé de l'exercice n'est pas correct au sujet de la variable dummy qui doit être définie dans le main.c et non dans le fichier operations.c car sinon une erreur se produit à la compilation de l'éxecutable

/*
 * Juste pour vérifier le module "operation"
 */
void exo1()
{
    int r;

    printf("dummy = %d\n", dummy);
    dummy += 19;
    printf("dummy = %d\n", dummy);

    r = plus(3, 4);
    printf("la somme de 3 et 4 est %d\n", r);

    r = moins(3, 4);
    printf("la soustraction de 3 et 4 est %d\n", r);
}

/*
 * manipulation des comptes bancaires
 */
void exo2()
{
    printf("Il y a %d compte(s) bancaire(s)\n", getNbComptes());

    initComptes();

    // quelques crédits (rappel : les comptes ne sont pas initialisés à 0)
    creditCompte(0, 1);
    creditCompte(1, 10);
    creditCompte(2, 100);
    creditCompte(3, 1000);
    creditCompte(4, 10000);
    creditCompte(0, 1);
    creditCompte(1, 10);       // on profite du bonus (si tous les 7 crédits)
    creditCompte(2, 100);
    creditCompte(3, 1000);
    creditCompte(4, 10000);

    // affichage complet
    printf("Etats des comptes : \n");
    for (int i = 0; i < getNbComptes(); i++)
        printf("Compte %2d : %5d euro(s)\n", i, getSoldeCompte(i));
    printf("\n");

    // un débit tout de même
    debitCompte(2, 7);
    printf("Compte %2d : %5d euro(s)\n", 2, getSoldeCompte(2));

    // s'il y a moins de 1000 comptes, ça plante
    // creditCompte(999, 1);

    printf("Il y a eu %d opérations\n", getNbOperations());
}

int main()
{
    exo1();
    exo2();
    
    return EXIT_SUCCESS;
}

/*Question : Je ne comprends pas pourquoi je ne vois pas les actions de crédit et de débit
effectuées sur différents comptes dans le void exo2() ne sont pas présent lors de l'éxecution du main pourriez vous m'éclairer là-dessus? Merci.*/