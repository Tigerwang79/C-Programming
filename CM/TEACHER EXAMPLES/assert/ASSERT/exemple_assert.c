// décommentez pour neutraliser les assert
// on peut aussi compiler avec l'option -DNDEBUG
//#define NDEBUG

#include <stdio.h>
#include <stdlib.h>

#include <assert.h>
#include "myassert.h"

void demo_assert()
{
    printf("avant assert ok\n");
    assert(1 == 1);
    printf("après assert ok\n");
    printf("avant assert pas ok\n");
    assert(1 == 0);
    printf("après assert pas ok\n");
}

void demo_myassert()
{
    printf("avant assert ok\n");
    myassert(1 == 1, "myassert : pb 1 == 1");
    printf("après assert ok\n");
    printf("avant assert pas ok\n");
    myassert(1 == 0, "myassert : pb 1 == 0");
    printf("après assert pas ok\n");
}


int main()
{
    // choisir un des deux appels
    //demo_assert();
    demo_myassert();
    
    return EXIT_SUCCESS;
}
