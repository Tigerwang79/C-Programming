// pour des problèmes de compilation
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "exo9_comm.h"

// création d'une file IPC
static int my_msgget()
{
    // TODO création de la file

    return -1;   // il faut retourner l'id de la file
}

// envoi d'un entier
void my_msgsndInt(int msgId, int v)
{
    // TODO envoyer l'entier v avec le type MSG_INT_TYPE
}

// envoi d'un caractère
void my_msgsndChar(int msgId, char v)
{
    // TODO envoyer le caractère v avec le type MSG_CHAR_TYPE
}

// suppression de la file
static void my_msgDestroy(int msgId)
{
    // TODO description de la file
}


int main()
{
    int msgId;

    // création file
    msgId = my_msgget();
    sleep(1);

    // on envoie différentes valeurs
    my_msgsndInt(msgId, 1);
    my_msgsndInt(msgId, 2);
    my_msgsndChar(msgId, 'A');
    sleep(1);
    my_msgsndInt(msgId, 3);
    my_msgsndInt(msgId, 4);
    my_msgsndChar(msgId, 'B');
    my_msgsndChar(msgId, 'C');
    sleep(2);
    my_msgsndChar(msgId, 'D');
    my_msgsndInt(msgId, 5);
    my_msgsndChar(msgId, '.');    // fin suite char
    my_msgsndInt(msgId, 6);
    my_msgsndInt(msgId, 7);
    sleep(1);
    my_msgsndInt(msgId, -1);      // fin suite int

    // on détruit la file
    // Attention, il faudrait être sûr que les deux autres
    // processus n'utilise plus la file, et pour cela
    // il faudrait un sémaphore
    // On fait plus simple : c'est l'utilisateur qui donne l'ordre
    // de destruction
    printf("Appuyez sur \"Entrée\" pour détruire la file.\n");
    printf("--> ");
    getchar();

    my_msgDestroy(msgId);

    printf("Fin de l'émetteur\n");
    
    return EXIT_SUCCESS;
}
