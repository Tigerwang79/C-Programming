/*
 * Exercice 2
 *
 * Il s'agit de manipuler les chaînes de caractères en C :
 * - avec de l'allocation dynamique
 * - avec quelque(s) point(s) technique(s)
 *
 * Les endroits on l'on attend une réponse sont signalés par un :
 *     // ====== TODO ==========
 *
 */

#define _XOPEN_SOURCE 500  // pour strdup
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes


/**************************************************************************
 * Question 2a
 * clone d'une chaine
 * Le but est de dupliquer une chaine avec allocation dynamique : la
 * fonction alloue l'espace nécessaire avant de faire la copie.
 */

// Écrire ici une fonction "strClone" qui prend en paramètre la chaîne
// à copier et renvoie la copie.
// On alloue la mémoire juste nécessaire.
// Interdiction d'utiliser les fonctions de la bibliothèque
// string (à part strlen)
// ====== TODO ==========

char* strClone(const char *chaine){
  int len = strlen(chaine);
  int i;
  char *newChaine = (char *) malloc(len *sizeof(char));
  for(i=0; i<len ; i++)
  {
    newChaine[i]=chaine[i];
  }
  return newChaine;
}

void exo_2a()
{
    const char *source = "Tu vois, le monde se divise en deux catégories, "
        "ceux qui ont un pistolet chargé et ceux qui creusent."
        " Toi, tu creuses.";
    printf("source : %s\n", source);

    // déclarez la chaîne qui va recevoir la copie, faire la copie
    // et l'afficher.
    // ====== TODO ==========
    char *copie = strClone(source);
    printf("Copie  : %s\n",copie);
    // il y a sûrement quelque chose à faire ici ?
    // ====== TODO ==========
    free(copie);
}


/**************************************************************************
 * Question 2b
 * strcat version dynamique
 * Le but est d'écrire une version parculière de strcat : la chaîne
 * à allonger a été allouée dynamiquement et la fonction doit
 * la réallouer à la bonne taille.
 */

// Écrire ici une fonction "strDynCat" qui prend en paramètre la chaîne
// à copier et la chaîne à ajouter.
// On respecte les fonctionnalités classique de strcat avec deux différences :
// - donc la destination doit être réallouée.
// - la fonction renvoie void
// Il est autorisé d'utiliser les fonctions de la bibliothèque string
// Le prototype est particulièrement délicat
// ====== TODO ==========

void exo_2b()
{
    // Chaine qui doit être allongée : obligatoirement allouée dynamiquement
    const char *dest;
    dest = strdup("Tu vois, le monde se divise en deux catégories, ");
    const char *add1 = "ceux qui ont un pistolet chargé et ceux qui creusent.";
    const char *add2 = " Toi, tu creuses.";
    
    printf("avant : %s\n", dest);

    // En utilisant votre fonction, concaténez add1 et add2 à dest;
    // ====== TODO ==========

    // vérification
    printf("après : %s\n", dest);

    // il y a sûrement quelque chose à faire ici ?
    // ====== TODO ==========
}

/**************************************************************************
 * Question 2c
 * formatage et allocation
 *
 * La contrainte est parculière : on veut formater une chaîne (avec sprintf).
 * Mais on veut que la chaîne qui reçoit le résultat soit allouée au plus
 * juste.
 * La démarche est obligatoirement celle-ci :
 * - on alloue la chaine
 * - on appelle sprintf pour la remplir
 * Mais pour allouer la chaîne au mieux, il faut avoir le résultat
 * de sprintf auparavant, et donc on est dans une impasse.
 * Il est interdit de surdimensionner tout simplement parce que dans
 * un cas général (que nous ne ferons pas pour simplifier) il est impossible
 * d'avoir une idée de la taille maximale.
 */
char * strFormat()
{
    float r1 = 3.14159f;
    double r2 = 1.0 / 3.0;
    const char *format = "est-ce que %g est plus grand que %lf ?";
    char *res;

    // voici le code que l'on NE veut PAS
    // ----------------------------------
    res = malloc(10000*sizeof(char));    // on est tranquille (!!! vraiment ?)
    sprintf(res, format, r1, r2);
    // et il faudrait ici réallouer pour raccourcir la chaîne ;
    // même si ce n'est pas le propos ici, regardez comment on fait

    // Mettez le code ci-dessus en commentaire
    // Et écrivez votre propre code pour que le malloc, avant le sprintf,
    // soit directement de la bonne taille.
    // Pour calculer cette taille, étudiez la fonction snprintf et
    // regardez comment elle se comporte lorsque la taille fournie
    // n'est pas suffisante.
    // ====== TODO ==========

    return res;
}

void exo_2c()
{
    char *resultat = strFormat();
    printf("%s\n", resultat);

    // il y a sûrement quelque chose à faire ici ?
    // ====== TODO ==========
}



/**************************************************************************
 * Question 2d
 * retour sur les chaînes littérales
 */

void exo_2d()
{
    const char *s1 = "Tu vois, le monde se divise en deux catégories";
    const char *s2 = "Tu vois, le monde se divise en deux catégories";

    // Affichez et comparez les valeurs des deux pointeurs.
    // Expliquez ce qu'il se passe (attention spoiler dans la suite)
    // ====== TODO ==========

    // On s'aperçoit que les deux pointeurs ont la même valeur.
    // Donc que ce passe-t-il (il faudrait enlever le const) si
    // on modifie la chaîne pointée par s1 ? Normalement la chaîne
    // pointée par s2 est aussi modifiée ?
    // Essayez
    // ====== TODO ==========

    s1 = NULL;
    s2 = NULL;
    // la zone mémoire qui contient la chaîne n'est plus référencée.
    // A-t-on une fuite mémoire ?
    // ====== TODO ==========
}



/*
 * fin des exercices
 * vous pouvez regarder le code ci-dessous, mais il ne fait pas
 * partie des exercices à faire.
 */


// pour afficher la répétition d'une chaîne
static void header_repeat(const char *s, int n, bool withReturn)
{
    for (int i = 0; i < n; i++)
        printf("%s", s);
    if (withReturn)
        printf("\n");
}

// pour afficher un joli titre encadré
static void header(const char *title)
{
    const int LINE_LENGTH = 75;
    int titleLength = strlen(title);

    printf("\n");
    header_repeat("=", LINE_LENGTH, true);
    printf("= %s", title);
    header_repeat(" ", LINE_LENGTH - titleLength - 4, false);
    printf(" =\n");
    header_repeat("=", LINE_LENGTH, true);
}

// fonction d'erreur
static void usage(const char *exe, const char *msg)
{
    fprintf(stderr,"usage : %s -\n", exe);
    fprintf(stderr,"   ou : %s <lettre>\n", exe);
    fprintf(stderr," - pour lancer toutes les fonctions\n");
    fprintf(stderr," une lettre pour lancer une seule fonction\n");
    if (msg != NULL)
        fprintf(stderr,"message : %s\n", msg);
    exit(EXIT_FAILURE);
}

// the main
int main(int argc, char * argv[])
{
    typedef struct
    {
        char extension;
        void (*fonction)();
        char *titre;
    } Exercice;

    Exercice exercices[] = 
    {
        {'a', exo_2a, "Exercice a"},
        {'b', exo_2b, "Exercice b"},
        {'c', exo_2c, "Exercice c"},
        {'d', exo_2d, "Exercice d"}
    };
    const int nbExercices = sizeof(exercices)/sizeof(Exercice);

    if (argc != 2)
        usage(argv[0], NULL);
    if ((argv[1][0] != '-') && ((argv[1][0] < exercices[0].extension) || (argv[1][0] > exercices[nbExercices-1].extension)))
        usage(argv[0], "lettre incorrecte");

    for (int i = 0; i < nbExercices; i++)
    {
        if ((argv[1][0] == exercices[i].extension) || (argv[1][0] == '-'))
        {
            header(exercices[i].titre);
            exercices[i].fonction();
        }
    }

    return EXIT_SUCCESS;
}
