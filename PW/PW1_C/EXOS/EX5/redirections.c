#include <stdio.h>
#include <stdlib.h>


int main()
{
	int x;		//Création de la variable permettant par la suite de stocker l'entier du programme

	printf("printf\n");
    fprintf(stdout, "fprintf avec stdout\n");
	fprintf(stderr, "fprintf avec stderr\n");

	printf("Inserer un entier -> ");
	scanf("%d", &x);	//Fonction récupérant la donnée de la variable saisi au préalable
	printf("%d\n", x);	//Affichage de l'entier

	return EXIT_SUCCESS;
}