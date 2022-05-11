//GROUPE : Guillaume PIERRE Valdrin SALIHI
#ifndef MASTER_WORKER_H
#define MASTER_WORKER_H

// On peut mettre ici des éléments propres au couple master/worker :
//    - des constantes pour rendre plus lisible les comunications
//    - des fonctions communes (écriture dans un tube, ...)


typedef struct
{
    char *name;
    int fd;
} OnePipe;

typedef struct {
    OnePipe MtoW;
    OnePipe WtoM;
} Descriptors;

/*
 * création et destruction des tubes
 */
void c_createPipes(int numPipe, int numService, Descriptors *pipes);
void c_destroyPipes(Descriptors *pipes);

/*
 * ouverture et fermeture des tubes
 */
void m_openPipes(const char *nameMtoW, const char *nameWtoM, Descriptors *pipes);
void w_openPipes(const char *nameMtoW, const char *nameWtoM, Descriptors *pipes);

void m_closePipes(Descriptors *pipes);
void w_closePipes(Descriptors *pipes);

/*
 * surcharge des envois et réceptions (pour gérer les erreurs)
 */
void m_writeData(Descriptors *pipes, const void *buf, size_t size);
void w_writeData(Descriptors *pipes, const void *buf, size_t size);
void m_readData(Descriptors *pipes, void *buf, size_t size);
void w_readData(Descriptors *pipes, void *buf, size_t size);


#endif
