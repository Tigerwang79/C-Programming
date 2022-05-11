// pour des problèmes de compilation
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "exo9_comm.h"

// récupérer la file IPC
static int my_msgget()
{
    // TODO récupérer la file

    return -1;   // il faut retourner l'id de la file
}

// lecture d'un message
int my_msgrvcInt(int msgId)
{
    // TODO recevoir un message de type MSG_INT_TYPE

    return -1;   // il faut retourner l'entier lu
}


int main()
{
    int msgId;

    // récupération de la file
    msgId = my_msgget();

    // réception des valeurs
    while (true)
    {
        int v = my_msgrvcInt(msgId);
        if (v == -1)
            break;
        printf("J'ai reçu %d\n", v);
    }

    // pas de destruction de la file

    printf("Fin du récepteur d'entiers\n");
    
    return EXIT_SUCCESS;
}
