#include <stdio.h>
#include <stdlib.h>

#include "limites.h"

int main()
{
    const char *s;

    // on exécute le code création
    s = getLimites();
    printf("%s\n", s);

    // on récupère l'objet déjà créé
    s = getLimites();
    printf("%s\n", s);

    return EXIT_SUCCESS;
}
