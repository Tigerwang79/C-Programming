#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    printf("nbre arguments : %d\n", argc);
    for (int i = 0; i < argc; i++)
        printf("arg %2d : \"%s\"\n", i, argv[i]);
    return EXIT_SUCCESS;
}
