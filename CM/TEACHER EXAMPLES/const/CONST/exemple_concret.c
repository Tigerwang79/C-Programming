/*
 * Le fait d'avoir des pointeurs désignant la même zone mémoire
 * n'a de réel intérêt que dans le passage de paramètres
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// s pointe sur la même zone mémoire que le mot du main
// mais sans droit de modification
void affiche(const char *s)
{
    printf("==>%s\n", s);
}

// s pointe sur la même zone mémoire que le mot du main
// et avec droit de modification
void inverse(char *s)
{
    int length = strlen(s);
    for (int i= 0; i < length/2; i++)
    {
        char c = s[i];
        s[i] = s[length-i-1];
        s[length-i-1] = c;
    }
}

int main()
{
    char mot[] = "bonjour";
    
    affiche(mot);
    inverse(mot);
    affiche(mot);
    
    return EXIT_SUCCESS;
}
