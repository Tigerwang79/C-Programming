#include <stdio.h>
#include <stdlib.h>

// todo : écrire les fonctions moins1 et moins2 à cet endroit du fichier
// code fourni en fin de fichier pour éviter de tout retaper
// la compilation avec "gcc -g -Wall -Wextra -pedantic -std=c99" ne
//     doit afficher aucun warning

int moins1(int n);

int moins2(int n);

int moins1(int n){
    if (n <= 1){
        return n;
    }
    n -= 1;
    return moins2(n);
}

int moins2(int n){
    if (n <= 1){
        return n;
    }
    n -= 2;
    return moins1(n);
}

int main()
{
    int r = moins2(9);
    printf("%d\n", r);
    
    return EXIT_SUCCESS;
}