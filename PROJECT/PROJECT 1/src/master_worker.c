//GROUPE : Guillaume PIERRE Valdrin SALIHI
#if defined HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdlib.h>
#include <stdio.h>

#include "myassert.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "master_worker.h"

/*
 * création et destruction des tubes
 */
static void createPipe(const char *basename, int numPipe, int numService,
                       const char *msg, OnePipe *onePipe
                      )
{
    int nameLength;

    nameLength = snprintf(NULL, 0, "%s_%d_%d", basename, numPipe, numService);
    onePipe->name = malloc((nameLength + 1) * sizeof(char));
    sprintf(onePipe->name, "%s_%d_%d", basename, numPipe, numService);
    onePipe->fd = -1;

    int ret = mkfifo(onePipe->name, 0600);
    myassert(ret == 0, msg);
}


void c_createPipes(int numPipe, int numService, Descriptors *pipes)
{
    createPipe("pipeMasterToWorker", numPipe, numService,
               "création tube MtoW", &(pipes->MtoW));
    createPipe("pipeWorkerToMaster", numPipe, numService,
               "création tube WtoM", &(pipes->WtoM));
}


static void destroyPipe(const char *msg, OnePipe *onePipe)
{
    int ret;
    
    ret = unlink(onePipe->name);
    myassert(ret == 0, msg);
    free(onePipe->name);
    onePipe->name = NULL;
}

void c_destroyPipes(Descriptors *pipes)
{
    destroyPipe("destruction tube MtoW", &(pipes->MtoW));
    destroyPipe("destruction tube WtoM", &(pipes->WtoM));
}


/*
 * ouverture et fermeture d'un tube
 */
static void openPipe(const char *name, int flag, const char *msg,
                     OnePipe *onePipe
                    )
{
    onePipe->name = strdup(name);
    onePipe->fd = open(onePipe->name, flag);
    myassert(onePipe->fd != -1, msg);
}


void m_openPipes(const char *nameMtoW, const char *nameWtoM, Descriptors *pipes)
{
    openPipe(nameMtoW, O_WRONLY,
             "master ouverture tube MtoW", &(pipes->MtoW));
    openPipe(nameWtoM, O_RDONLY,
             "master ouverture tube WtoM", &(pipes->WtoM));
}


void w_openPipes(const char *nameMtoW, const char *nameWtoM, Descriptors *pipes)
{
    openPipe(nameMtoW, O_RDONLY,
             "worker ouverture tube MtoW", &(pipes->MtoW));
    openPipe(nameWtoM, O_WRONLY,
             "worker ouverture tube WtoM", &(pipes->WtoM));
}


static void closePipe(const char *msg, OnePipe *onePipe)
{
    int ret;
    
    free(onePipe->name);
    onePipe->name = NULL;
    ret = close(onePipe->fd);
    myassert(ret == 0, msg);
    onePipe->fd = -1;
}


void m_closePipes(Descriptors *pipes)
{
    closePipe("master fermeture tube MtoW", &(pipes->MtoW));
    closePipe("master fermeture tube WtoM", &(pipes->WtoM));
}


void w_closePipes(Descriptors *pipes)
{
    closePipe("worker fermeture tube MtoW", &(pipes->MtoW));
    closePipe("worker fermeture tube WtoM", &(pipes->WtoM));
}

/*
 * surcharge des envois et réceptions (pour gérer les erreurs)
 */
static void writeData(OnePipe *onePipe, const void *buf, size_t size,
                      const char *msg)
{
    ssize_t ret = write(onePipe->fd, buf, size);
    myassert(ret != -1, msg);
    myassert((size_t)ret == size, msg);
}


void m_writeData(Descriptors *pipes, const void *buf, size_t size)
{
    writeData(&(pipes->MtoW), buf, size, "master écriture vers worker");
}


void w_writeData(Descriptors *pipes, const void *buf, size_t size)
{
    writeData(&(pipes->WtoM), buf, size, "worker écriture vers master");
}


static void readData(OnePipe *onePipe, void *buf, size_t size,
                      const char *msg)
{
    ssize_t ret = read(onePipe->fd, buf, size);
    myassert(ret != -1, msg);
    myassert((size_t)ret == size, msg);
}


void m_readData(Descriptors *pipes, void *buf, size_t size)
{
    readData(&(pipes->WtoM), buf, size, "master lecture de worker");
}


void w_readData(Descriptors *pipes, void *buf, size_t size)
{
    readData(&(pipes->MtoW), buf, size, "worker lecture de master");
}

// fonctions éventuelles proposées dans le .h
