#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void titre(const char *s);


// ========================================================================
// pointeur non constant, objet pointé non constant
void a()
{
    titre("char *");
    
    char s1[] = "un";
    char s2[] = "deux";
    char * p = s1;        // p pointe sur la 1re case de s1

    // aucun const => on peut modifier l'objet pointé (i.e. s1)
    p[0] = '!';
    printf("%s %s\n", s1, s2);

    // aucun const => on peut modifier le pointeur
    p = s2;    // p pointe sur la 1re case de s2 
    
    // aucun const => on peut modifier l'objet pointé (i.e. maintenant s2)
    p[0] = '!';
    printf("%s %s\n", s1, s2);
}

// ========================================================================
// pointeur non constant, objet pointé constant
void b()
{
    titre("const char *");
    
    char s1[] = "un";
    char s2[] = "deux";
    const char * p = s1;        // p pointe sur la 1re case de s1

    // *p est const => on ne peut pas modifier l'objet pointé
    //p[0] = '!';
    printf("%s (%s) %s\n", s1, p, s2);
    
    // p n'est pas const => on peut modifier le pointeur
    p = s2;
    
    // mais on ne peut toujours pas modifier l'objet pointé
    //p[0] = '!';
    printf("%s %s (%s)\n", s1, s2, p);
}

// ========================================================================
// pointeur constant, objet pointé non constant
void c()
{
    titre("char * const");
    
    char s1[] = "un";
    char s2[] = "deux";
    char * const p = s1;        // p pointe sur la 1re case de s1

    // *p n'est pas const => on peut modifier l'objet pointé
    p[0] = '!';
    printf("%s %s\n", s1, s2);

    // p est const => on ne peut pas modifier le pointeur
    //p = s2;
    
    p[1] = '?';
    printf("%s %s\n", s1, s2);
}

// ========================================================================
// pointeur constant, objet pointé constant
void d()
{
    titre("const char * const");
    
    printf("Cumul des deux exercices précédents\n");
}

// ========================================================================
void e()
{
    titre("ajouter un const");
    
    char s1[] = "un";
    const char * s2 = s1;

    s1[0] = 'U';   // ok
    //s2[0] = 'N';   // non, et pourtant s2 et s1 c'est la même chose
    printf("%s %s\n", s1, s2);
}

// ========================================================================
// à utiliser avec précaution
void f()
{
    titre("casser un const");
    
    char s1[] = "un";
    const char * p = s1;        // p pointe sur la 1re case de s1
    char *p2;                   // p2 non initialisé, adresse aléatoire

    //p[0] = '!';
    //p2 = p;
    p2 = (char *) p;            // p2 pointe aussi sur la 1re case de s1
    printf("%s\n", s1);
    p2[0] = '!';                // avec p2 on peut modifier l'objet pointé
    printf("%s\n", s1);
}

// ========================================================================
void g()
{
    titre("récapitulatif");
    
    printf("Ce qui est constant, c'est l'expression après le mot-clé const\n");
    printf("    const char *p\n");
    printf("              \\__/    -> *p est const, i.e. l'objet pointé, mais pas le pointeur\n");
    printf("    char * const p\n");
    printf("                \\_/   -> p est const, i.e. le pointeur, mais pas l'objet pointé\n");
    printf("    const char * const p\n");
    printf("                      \\_/   ->    p est const, i.e. le pointeur\n");
    printf("              \\_________/   -> et *p est const, i.e. l'objet pointé\n");
    
    printf("\n");
    printf("L'instruction :\n");
    printf("    char *s = \"chat\";\n");
    printf("est une aberration.\n");
    printf("L'instruction correcte est :\n");
    printf("    const char *s = \"chat\";\n");
}



// ========================================================================

static void usage(const char *exeName, const char *message)
{
    fprintf(stderr, "usage : %s <lettre>\n", exeName);
    if (message != NULL)
        fprintf(stderr, "message : %s\n", message);
    exit(EXIT_FAILURE);
}

static void titre(const char *s)
{
    const int LG = 60;
    int taille = strlen(s);
    
    for (int i = 0; i < LG+4; i++)
        putchar('-');
    putchar('\n');

    printf("- %s", s);
    for (int i = 0; i < LG+1-taille; i++)
        putchar(' ');
    printf("-\n");
    
    for (int i = 0; i < LG+4; i++)
        putchar('-');
    putchar('\n');
}

int main(int argc, char * argv[])
{
    if (argc != 2)
        usage(argv[0], NULL);

    void (*fonctions[])() = {a, b, c, d, e, f, g};
    int nbFonctions = sizeof(fonctions)/sizeof(*fonctions);

    if ((argv[1][0] < 'a') || (argv[1][0] >= 'a'+nbFonctions))
        usage(argv[0], "lettre hors intervalle");
    
    for (int i = 0; i < nbFonctions; i++)
    {
        if (argv[1][0] == 'a'+i)
        {
            fonctions[i]();
            break;
        }
    }

    return EXIT_SUCCESS;
}
