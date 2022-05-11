#include <stdio.h>
#include <stdlib.h>

// Donc à part montrer la différence entre déclaration
// et définition, ce code est n'importe quoi

// déclarer afficheN
// todo

void afficheN(char *msg, int n);

// déclarer afficheN
// todo

void afficheN(char *msg, int n);

// définir afficheN
// todo

void afficheN(char *msg, int n){
	for (int i=0; i<n; i++)
	{
		printf("%s\n", msg);
	}
}

// déclarer afficheN
// todo

void afficheN(char *msg, int n);

int main()
{
    // déclarer afficheN
    // todo

    void afficheN(char *msg, int n);

    // appeler afficheN pour afficher 3 fois "Bonjour"
    // todo

    afficheN("Bonjour Monde !", 5);
    
    return EXIT_SUCCESS;
}