// pour des problèmes de compilation
#define _XOPEN_SOURCE

#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#include "myassert.h"

#include "Semaphore.h"

struct SemaphoreP
{
    int nbSem;
    int semId;
};

/****
 * constructeurs, destructeurs
 ****/

// pensez éventuellement à factoriser le code commun aux constructeurs

Semaphore sema_creerPrivate(int nbSem, int droits)
{
    // TODO
    return NULL;
}

Semaphore sema_creerNouveau(const char *filename, int idProj, int droits, int nbSem)
{
    // TODO
    return NULL;
}

Semaphore sema_creerExistant(const char *filename, int idProj, int nbSem)
{
    // TODO
    return NULL;
}


void sema_detruireSansSupression(Semaphore *self)
{
    // TODO
}

void sema_detruireAvecSupression(Semaphore *self)
{
    // TODO
}



/****
 * initialisation, accesseurs
 ****/
unsigned short sema_getVal(constSemaphore self, int pos)
{
    myassert((pos >= 0) && (pos < self->nbSem), "numero semaphore");

    // TODO
    return -1;
}

void sema_setVal(Semaphore self, int pos, unsigned short val)
{
    myassert((pos >= 0) && (pos < self->nbSem), "numero semaphore");

    // TODO
}

void sema_getVals(constSemaphore self, int nbSem, unsigned short vals[])
{
    myassert(nbSem == self->nbSem, "nombre semaphores");

    // TODO
}

void sema_setVals(Semaphore self, int nbSem, const unsigned short  vals[])
{
    myassert(nbSem == self->nbSem, "nombre semaphores");

    // TODO
}


/****
 * opérations basiques
 ****/

// pensez éventuellement à factoriser le code commun aux opérations

void sema_prendre(Semaphore self, int pos)
{
    // TODO
}

void sema_vendre(Semaphore self, int pos)
{
    // TODO
}

void sema_attendre(Semaphore self, int pos)
{
    // TODO
}


/****
 * opérations à peine moins basiques
 ****/
void sema_diminue(Semaphore self, int pos, int delta)
{
    myassert(delta > 0, "delta doit etre > 0");
    
    // TODO
}

void sema_augmente(Semaphore self, int pos, int delta)
{
    myassert(delta > 0, "delta doit etre > 0");

    // TODO
}

void sema_modifie(Semaphore self, int pos, int delta)
{
    // TODO
}
