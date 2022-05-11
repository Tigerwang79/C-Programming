#include <stdio.h>
#include <stdlib.h>

//## Indépendamment des warnings, seul l'appel à la fonction static g échoue.
//##    on note que c'est une erreur d'édition de liens et non de compilation.
//## Si on commente l'appel à g, alors f est bien appelée bien qu'elle
//## ne soit pas déclarée.

int main()
{
    f();
    g();
    
    return EXIT_SUCCESS;
}
