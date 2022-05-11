#include <stdlib.h>
#include <stdio.h>
#include "operation.h"

int NbOpePlus = 0;
int NbOpeMoins = 0;

int plus(int a, int b)
{
	NbOpePlus += 1;
	if (NbOpePlus % 7 == 0)
	{
		a += 1;
	}
	return a+b;
}

int moins(int a, int b)
{
	NbOpeMoins += 1;
	return a-b;
}

int getNbOperations()
{
	printf("- Nombre d'appels plus : %d\n", NbOpePlus);
	printf("- Nombre d'appels moins : %d\n", NbOpeMoins);
	return NbOpePlus + NbOpeMoins;
}