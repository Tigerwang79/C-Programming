#include <stdio.h>
#include <stdlib.h>
// todo
#include "ImageMono.h"


int main()
{
	ImageMono img;

	init(&img, 20, 30, "bleue");
	setCouleur(&img, "Vert");
	printf("[L=%d, H=%d, C=%s]\n", getLargeur(&img), getHauteur(&img), getCouleur(&img));

    return EXIT_SUCCESS;
}
