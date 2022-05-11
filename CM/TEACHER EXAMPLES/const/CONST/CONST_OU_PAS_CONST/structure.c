#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static void usage(const char *exeName, const char *message)
{
    fprintf(stderr, "usage : %s\n", exeName);
    if (message != NULL)
        fprintf(stderr, "message : %s\n", message);
    exit(EXIT_FAILURE);
}

#define N 10
struct Image
{
    unsigned char pixels[N*N];
};

// =================================================================
void init(struct Image *im)
{
    for (int i = 0; i < N*N; i++)
        im->pixels[i] = 0;
}

// =================================================================
unsigned char computeMoyenne(const struct Image *im)
{
    int moyenne = 0;
        
    for (int i = 0; i < N*N; i++)
        moyenne += im->pixels[i];
    moyenne /= N*N;
    
    return moyenne;
}

// =================================================================
void set(struct Image *im, int i, int j, unsigned char gray)
{
    im->pixels[i*N+j] = gray;
}

// =================================================================
int main(int argc, char * argv[])
{
    if (argc != 1)
        usage(argv[0], NULL);

    struct Image image;
    unsigned m;

    init(&image);
    m = computeMoyenne(&image);
    printf("m = %3d\n", m);
    m = computeMoyenne(&image);
    printf("m = %3d\n", m);
    set(&image, 3, 4, 255);
    m = computeMoyenne(&image);
    printf("m = %3d\n", m);

    return EXIT_SUCCESS;
}
