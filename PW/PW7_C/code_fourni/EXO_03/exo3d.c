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
    // et on le détruit cette fois-ci
	int id;

	for (int i = 0; i < 2; i++)
	{
		id = semget(IPC_PRIVATE, IPC_CREAT, 0641);
		semctl(id, 0, IPC_RMID);
	}
    return EXIT_SUCCESS;
}
