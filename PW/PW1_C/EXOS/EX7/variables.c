#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	char *nom_shell = argv[1];
	char *value = getenv(argv[1]);

	if (argc != 2)			//Cas où l'utilisateur oublie de passer un paramètre
	{
		printf("Variable d'environnement shell : %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (value == NULL)
	{
		printf("La variable d'environnement %s ne possède pas de valeur\n", nom_shell);
	}
	else
	{
		printf("La variable d'environnement %s a pour valeur : %s \n", nom_shell, value);
	}

	return EXIT_SUCCESS;
}