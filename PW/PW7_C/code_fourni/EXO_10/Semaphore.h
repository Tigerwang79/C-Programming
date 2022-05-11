#ifndef SEMAPHORE_H
#define SEMAPHORE_H

struct SemaphoreP;
typedef struct SemaphoreP *Semaphore;
typedef const struct SemaphoreP *constSemaphore;

/****
 * constructeurs et destructeur
 * surtout ne pas oublier de détruire le sémaphore pour ne pas
 * saturer le système
 * les sémaphores sont initialisés à 0 par défaut
 ****/
// création sémaphore IPC_PRIVATE
Semaphore sema_creerPrivate(int nbSem, int droits);
// création : le sémaphore ne doit pas exister sur le système
Semaphore sema_creerNouveau(const char *filename, int idProj, int droits, int nbSem);
// récupérer un sémaphore existant
Semaphore sema_creerExistant(const char *filename, int idProj, int nbSem);

// destructeur sans suppression sur le système
void sema_detruireSansSupression(Semaphore *self);
// destructeur avec suppression sur le système
void sema_detruireAvecSupression(Semaphore *self);

/****
 * initialisation, accesseurs
 ****/
unsigned short sema_getVal(constSemaphore self, int pos);
void sema_setVal(Semaphore self, int pos, unsigned short val);
void sema_getVals(constSemaphore self, int nbSem, unsigned short vals[]);
void sema_setVals(Semaphore self, int nbSem, const unsigned short  vals[]);

/****
 * opérations basiques
 ****/
// tentative de faire -1 sur le sémaphore
void sema_prendre(Semaphore self, int pos);

// +1 sur le sémaphore
void sema_vendre(Semaphore self, int pos);

// attente que le sémaphore passe à 0
void sema_attendre(Semaphore self, int pos);

/****
 * opérations à peine moins basiques
 ****/
// équivalent de prendre avec une valeur pouvant être > 1
// delta est bien > 0, et on essaie de retrancher delta au sémaphore
void sema_diminue(Semaphore self, int pos, int delta);

// équivalent de vendre avec une valeur pouvant être > 1
// on ajoute delta au sémaphore
void sema_augmente(Semaphore self, int pos, int delta);

// équivant à :
//    si delta < 0 : sema_diminue(self, -delta);
//    si delta = 0 : sema_attendre(self);
//    si delta > 0 : sema_augmente(self, delta);
void sema_modifie(Semaphore self, int pos, int delta);


#endif
