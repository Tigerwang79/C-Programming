#ifndef BIBLIO_H
#define BIBLIO_H

// A priori une déclaration toute simple
// Mais la chaine n'est pas déclarée en const
// On se doute bien que la fonction ne modifie pas la chaîne, mais
// lorsqu'on compile main.c, on ne peut pas le savoir.
// Dans le doute, le compilateur fait la pire des hypothèses, il considère
// que la fonction modifie la chaîne.
void affiche(char *s);

#endif
