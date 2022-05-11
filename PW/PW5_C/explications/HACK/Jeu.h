#ifndef JEU_H
#define JEU_H

struct JeuP;
typedef struct JeuP * Jeu;
typedef const struct JeuP * const_Jeu;

Jeu creer(const char *titre, int prix);
void detruire(Jeu *self);

void setPrix(Jeu self, int prix);
int getPrix(const_Jeu self);

void setTitre(Jeu self, const char *titre);
const char * getTitre(const_Jeu self);

void affiche(const_Jeu self);

#endif
