// pour des problèmes de compilation
#define _XOPEN_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>


// mettre les bons includes

int main()
{
    // ici il faut déclarer un sémaphore (en mode IPC_PRIVATE) de deux cases
    // et donc on ne le détruit pas
	
	for (int i = 0; i < 2; i++)
	{
		semget(IPC_PRIVATE, IPC_CREAT, 0641);
	}
    return EXIT_SUCCESS;
}
