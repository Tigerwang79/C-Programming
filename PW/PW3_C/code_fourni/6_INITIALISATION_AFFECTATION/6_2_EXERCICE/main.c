#include <stdio.h>
#include <stdlib.h>

// définir ici une variable non static

int a;

// définir ici une variable static

static int b;

void f()
{
    // définir ici une variable static

    static int c;

    // définir ici une variable non static

    int d;

    // afficher les deux variables

    printf("%d - %d\n", c, d);
}

int main()
{
    // définir ici une variable non static

    int e;

    // afficher les 3 variables visibles du main

    printf("%d - %d - %d\n", a, b, e);

    f();
    
    return EXIT_SUCCESS;
}


/*Explication :
- Les variables concernées par des warnings du compilateur sont les variables non static 'd' et 'e'.
- Ce sont les variables 'a','b' et 'c'. 
- Oui c'est celui attendu.*/