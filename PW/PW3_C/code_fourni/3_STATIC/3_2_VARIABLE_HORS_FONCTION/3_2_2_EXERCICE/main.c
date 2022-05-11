#include <stdlib.h>
#include <stdio.h>

extern int g;
extern int s;

int main()
{
	printf("%d\n", g);
	printf("%d\n", s);

	return EXIT_SUCCESS;
}