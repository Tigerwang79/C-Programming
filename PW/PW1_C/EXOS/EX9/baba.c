#include <stdio.h>
#include <stdlib.h>


float summ(float a, float b)
{
	return a+b;
}

int main()
{
	float a = 1.12032002;
	float b = 2.02127003;

	printf("Résultat de la somme est >>%f<<\n", summ(a,b));

	return EXIT_SUCCESS;
}