#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "myassert.h"

#include "Voiture.h"


int stat_getNbInitialisation;
int stat_nbImmatriculations;
int stat_AnneeMin;
int stat_AnneeMax;


// Structure
struct VoitureP
{
	const char *marque;
	int annee;
	int kilometrage;
	int nbImmatriculations;
	const char **immatriculations;
};


// Statistique
int voi_stat_getNbInitialisations()
{
	return stat_getNbInitialisation;
}


int voi_stat_getNbImmatriculations()
{
	return stat_nbImmatriculations;
}


int voi_stat_getAnneeMin()
{
	return stat_AnneeMin;
}


int voi_stat_getAnneeMax()
{
	return stat_AnneeMax;
}


// Constructeurs, Destructeur, Autre
Voiture voi_creer(const char *marque, int annee, int kilometrage, int nbImmatriculations, const char *immatriculations[])
{
	Voiture self = malloc(sizeof(struct VoitureP));
	self->marque = malloc((strlen(marque)+1) *sizeof(char));
	strcpy(self->marque, marque);
	self->annee = annee;
	self->kilometrage = kilometrage;
	self->nbImmatriculations = nbImmatriculations;
	self->immatriculations = malloc((nbImmatriculations+1) *sizeof(char));

	for (int i = 0; i < self->nbImmatriculations; i++)
	{
		self->immatriculations[i] = malloc (10 * sizeof(char));
		strcpy((self->immatriculations[i]), immatriculations[i]);
		stat_nbImmatriculations ++;
	}
	stat_getNbInitialisation ++;
	if (annee > stat_AnneeMax)
	{
		stat_AnneeMax = annee;
	}
	else if (annee < stat_AnneeMin)
	{
		stat_AnneeMin = annee;
	}
	return self;
}


Voiture voi_creerCopie(const_Voiture source)
{
	Voiture dest = malloc(sizeof(Voiture));
	dest->marque = malloc((strlen(source->marque)+1) *sizeof(char));
	strcpy(dest->marque, source->marque);
	dest->annee = source->annee;
	dest->kilometrage = source->kilometrage;
	dest->nbImmatriculations = source->nbImmatriculations;
	dest->immatriculations = malloc((source->nbImmatriculations+1) *sizeof(char));

	for (int i = 0; i < source->nbImmatriculations; i++)
	{
		strcpy((&dest->immatriculations[i]), (&source->immatriculations[i]));
		stat_nbImmatriculations ++;
	}
	stat_getNbInitialisation;
	return dest;
}


// À partir d'un fichier écrit par voi_ecrireFichier
Voiture voi_creerFromFichier(FILE *fd)
{
	Voiture self = malloc(sizeof(struct VoitureP));
	return self;
}


void voi_detruire(Voiture *pself)
{
	free(((*pself)->marque));
	for (int i = 0; i < (*pself)->nbImmatriculations; i++)
	{
		free((*pself)->immatriculations[i]);
		stat_nbImmatriculations --;
	}
	stat_getNbInitialisation --;
	free(*pself);
	*pself = NULL;
}


void voi_swap(Voiture v1, Voiture v2)
{
	Voiture tmp = v1;
	v1 = v2;
	v2 = tmp;
}


// Accesseurs
void voi_getMarque(const_Voiture self, char *marque)
{
	strcpy(marque, self->marque);
}


int voi_getAnnee(const_Voiture self)
{
	return self->annee;
}


int voi_getKilometrage(const_Voiture self)
{
	return self->kilometrage;
}


void voi_setKilometrage(Voiture self, int kilometrage)
{
	self->kilometrage = kilometrage;
}


int voi_getNbImmatriculations(const_Voiture self)
{
	return self->nbImmatriculations;
}


void voi_getImmatriculation(const_Voiture self, int pos, char *immatriculations)
{
	strcpy(immatriculations, &(self->immatriculations[pos]));
}


void voi_addImmatriculation(Voiture self, const char *immatriculations)
{
	self->nbImmatriculations++;
	self->immatriculations = realloc(self->immatriculations, self->nbImmatriculations *sizeof(char));
	self->immatriculations[self->nbImmatriculations-1] = malloc(10 * sizeof(char));
	strcpy((self->immatriculations[self->nbImmatriculations-1]), immatriculations);
	stat_nbImmatriculations ++;
}


// Affichage
void voi_afficher(const_Voiture self)
{
	printf("- Marque : %s\n", self->marque);
	printf("- Annee : %d\n", self->annee);
	printf("- Kilometrage : %d\n", self->kilometrage);
	printf("- Nbr Immatriculations : %d\n", self->nbImmatriculations);

	for (int i = 0; i < self->nbImmatriculations; i++)
	{
		printf("- Immatriculations %d : %s\n", i, self->immatriculations);
	}
}


// Entrées-Sorties
void voi_ecrireFichier(const_Voiture self, FILE *fd)
{
	int len = strlen(self->marque);
    fwrite(&len,sizeof(int),1,fd);

    fwrite(self->marque,sizeof(char),len+1,fd);
    fwrite(&(self->annee),sizeof(int),1,fd);
    fwrite(&(self->kilometrage),sizeof(int),1,fd);
    fwrite(&(self->nbImmatriculations),sizeof(int),1,fd);

    for(int i = 0 ; i < self->nbImmatriculations; i++)
    {
        len = strlen(&(self->immatriculations[i]));
        fwrite(&(len),sizeof(int),1,fd);
        fwrite(&(self->immatriculations[i]),sizeof(char),len+1,fd);
    }
}


void voi_lireFichier(Voiture self, FILE *fd)
{
	int len = strlen(self->marque)+1;
	fread(self->marque, sizeof(char), len, fd);
	fread(&(self->kilometrage), sizeof(int), 1, fd);
	fread(&(self->annee), sizeof(int), 1, fd);
	fread(&(self->nbImmatriculations), sizeof(int), 1, fd);

	for (int i = 0; i < self->nbImmatriculations; i++)
	{
		int l = strlen(&(self->immatriculations[i]));
		fread(&l, sizeof(int), 1, fd);
		fread(&(self->immatriculations[i]), sizeof(char), l, fd);
	}
}