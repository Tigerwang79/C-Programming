#include <stdio.h>
#include <stdlib.h>

// définir ici une constante non static (sans l'initialiser)

const int a;

// définir ici une constante static (sans l'initialiser)

static const int b;

void f()
{
    // définir ici une constante static (sans l'initialiser)

    static const int c;

    // définir ici une constante non static (sans l'initialiser)

    const int d;

    // essayez de changer ces deux constantes

    /*c = -50;
    d = 100;*/

    // afficher les deux constantes

    printf("%d - %d\n", c, d);
}

int main()
{
    // définir ici une constante non static (sans l'initialiser)

    const int e;

    // afficher les 3 constantes visibles du main

    printf("%d - %d - %d\n", a, b, e);

    // essayez de changer ces trois constantes

    /*a = 10;
    b = -20;
    e = 50;*/

    f();
    
    return EXIT_SUCCESS;
}

/*Explication :
- Les constantes concernées par un warning sont les variables non-globale et non-static 'd' 'e'.
- Elle n'a pas d'intérêt car l'attribut static rend la variable visible que dans la fonction où elle est appelée mais ne se réinitialise pas à chaque appel de la fonction.
- On est bloqué par le compilateur lors d'un changement de valeur aux constantes.*/