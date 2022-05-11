#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Jeu.h"

/*
 * Exploration de la mémoire pour deviner comment elle
 *      est organisée et donc y avoir un accès direct.
 *
 * Première analyse, d'après le .h :
 *    - il y a un entier pour le prix
 *    - il y a un char * (vraisemblablement) pour le titre
 *    question : dans quel ordre sont-ils ?
 *
 * Deuxième analyse :
 *    - la méthode "getTitre" manifestement nous renvoie directement
 *      un pointeur sur la chaîne. Il suffit de faire un cast pour
 *      supprimer le const et avoir un accès direct sur la chaîne.
 *
 * Troisième analyse :
 *    - la technique ci-dessus ne s'applique pas pour le prix car
 *      la méthode getPrix renvoie une copie du titre
 *    - il faut savoir si le prix est stocké en premier dans la
 *      structure ou en second.
 *    - on fabrique deux structures avec les deux possibilités,
 *      et on vérifie laquelle est la bonne.
 *
 * Finalement :
 *    - une fois qu'on a trouvé, on se réécrit les accesseurs.
 *
 * Conclusion : cela de sert à rien de masquer l'implémentation ?
 * Réponse : non
 *        Le masquage sert uniquement au programmeur de bonne foi
 *        pour lui faciliter la vie, lui éviter de faire bêtises
 *        et plus largement l'obliger à programmer lisiblement.
 *        Celui qui passe outre avec la technique ci-dessous,
 *        rend son propre code instable en le faisant exprès, c'est
 *        son problème (rien de vous empêche d'acheter un meuble
 *        et ensuite de le détruire à coups de marteau, on ne peut
 *        pas blâmer le constructeur).
 *        Sans compter que si le concepteur change la structure, le
 *        code du main ne marche plus du tout.
 */

// analyse mémoire
void analyse()
{
    typedef struct
    {
        int p;
        char *t;
    } Test1;

    typedef struct
    {
        char *t;
        int p;
    } Test2;
    
    Jeu j = creer("Pouet", 123456);
    int prix = getPrix(j);
    const char *titre = getTitre(j);
    Test1 *j1 = (Test1 *) j;
    Test2 *j2 = (Test2 *) j;

    // valgrind pourrait ne pas aimer
    if ((j1->p == prix) && (strcmp(j1->t, titre) == 0))
        printf("Le prix est en premier\n");
    else if ((j2->p == prix) && (strcmp(j2->t, titre) == 0))
        printf("Le prix est en second\n");
    else
        printf("Echec analyse mémoire");
    
    // pour faire croire qu'on programme proprement
    detruire(&j);
}


// avec le code ci-dessus on s'est aperçu que le prix est en second
// récriture des setters
void mySetPrix(Jeu self, int prix)
{
    typedef struct
    {
        char *t;
        int p;
    } Test2;

    Test2 *j = (Test2 *) self;
    j->p = prix;
 }

void mySetTitre(Jeu self, const char *titre)
{
    typedef struct
    {
        char *t;
        int p;
    } Test2;

    Test2 *j = (Test2 *) self;
    // à faire le malin on fait une fuite mémoire
    j->t = strdup(titre);
}


int main()
{
    analyse();

    Jeu jeu = creer("Super Mario", 49);

    mySetPrix(jeu, -12);
    mySetTitre(jeu, "Mini Mario");
    printf("%s (%d)\n", getTitre(jeu), getPrix(jeu));

    mySetPrix(jeu, 0);
    mySetTitre(jeu, "Pif et Hercule");
    printf("%s (%d)\n", getTitre(jeu), getPrix(jeu));

    detruire(&jeu);
    
    return EXIT_SUCCESS;
}
