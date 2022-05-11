#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void relais()
{
	bool condition = true;

	while (condition)			//Tant que notre condition est vrai l'on va inscrire les caractères un à un sur stdin grâce à fgetc
	{
		int letter = fgetc(stdin);

		if (letter == EOF)		//Lorsque notre caractère sera égal à EOF alors on break
		{
			break;
		}
		fputc(letter, stdout);	//Enfin on va recopier les caractères sur la sortie standard grâce à fputc
	}
}


int main()
{
	relais();

	return EXIT_SUCCESS;
}