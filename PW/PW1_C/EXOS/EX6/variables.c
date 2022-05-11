#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[], char *env[])
{
	int i;

	printf("%d arguments passé en ligne de commande\n", argc-1);
	for (int i = 0; i < argc-1; ++i)		//Parcours de l'ensemble des paramètres de la fonction
	{
		printf(" * %s\n", argv[i]);			//Affichage de chacun des arguments sous forme de liste
	}
	printf("\n");

	printf("Le contenu du tableau env");
	i = 0;
	while (env[i] != NULL)					//Boucle tant qu'il reste des variables d'environnement alors ==>
	{
		printf(" * %s\n", env[i]);			//==>On les affiches
		i++;
	}
	printf("\n");

	return EXIT_SUCCESS;
}