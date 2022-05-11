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
char my_msgrvcChar(int msgId)
{
    // TODO recevoir un message de type MSG_CHAR_TYPE

    return '.';   // il faut retourner le caractère lu
}


int main()
{
    int msgId;

    // récupération de la file
    msgId = my_msgget();

    // réception des valeurs
    while (true)
    {
        char v = my_msgrvcChar(msgId);
        if (v == '.')
            break;
        printf("J'ai reçu %c\n", v);
    }

    // pas de destruction de la file

    printf("Fin du récepteur de char\n");
    
    return EXIT_SUCCESS;
}
