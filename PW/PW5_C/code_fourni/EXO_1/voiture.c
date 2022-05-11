#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <myassert.h>

#include "voiture.h"


struct T_Voiture{
	char *marque;
	int annee_fabrication;
	int kilometrage;
	char **immatriculations;
}


Voiture creer(const char *marque, int annee_fabrication, int kilometrage, char **immatriculations)
{
	assert(strcmp(marque, "") != 0);
	assert(kilometrage >= 0);

	Voiture self = malloc(sizeof(struct T_Voiture));

	self->marque = malloc((strlen(marque)+1) * sizeof(char));
	strcpy(self->marque, marque);
	self->kilometrage;

	return self;
}


void detruire(Voiture *self)
{
	free((*self)->marque);
	free(*self);
	*self = NULL;
}


void setMarque(Voiture self, const char *marque)
{
	assert(strcmp(marque, "") != 0);

	if (marque == self->marque)
		return;

	free(self->marque);
	self->marque = strdup(marque);
}


const char * getMarque(const_Voiture self)
{
	return self->marque;
}


void affiche(const_Voiture self)
{
	printf("-----------------------\n");
	printf("- Marque : %s\n", self->marque);
	printf("- Annee de fabrication : %d\n", );
	printf("- Kilometrage : %d \n", );
}