#include "Collection.h"


struct CollectionP
{
	int nbVoitures;
	Voiture *voitures;
	bool estTriee;
};


Collection col_creer()
{
	Collection self;
	self = malloc(sizeof(struct CollectionP));
	self->nbVoitures = 0;
	self->voitures = NULL;
	self->estTriee = true;

	return self;
}


Collection col_creerCopie(const_Collection source)
{
	int i;
	self = col_creer();
	self->voitures = malloc(source->nbVoitures *sizeof(Voiture));
	for (int i = 0; i < source->nbVoitures; i++)
	{
		self->voitures[i] = source->voitures[i];
	}
	self->nbVoitures = source->nbVoitures;
	self->estTriee = source->estTriee;
	return self;
}


void col_detruire(Collection *pself)
{
	for (int i = 0; i < pself->nbVoitures; i++)
	{
		voi_detruire(&(*pself)->voi_tab[i]);
	}
	free((*pself)->voitures);
	free(*pself);
	*self = NULL;
}


void col_vider(Collection self)
{
	for(int i = 0; i < self->nbVoitures; i++)
		free(self->VoitureCollection[i] = 0);
	self->nbVoitures = 0;
	self->estTriee = true;
}


int col_getNbVoitures(const Collection self)
{

}


Voiture col_getVoiture(const_Collection self, int pos)
{

}


void col_addVoitureSansTri(Collection self, const_Voiture voiture)
{
	self->nbVoitures ++;
	self->voitures = realloc(self->voitures, self->nbVoitures *sizeof(Voiture));

	self->voitures[self->nbVoitures - 1] = voi_creerCopie(voiture);
	if(self->nbVoitures > 1)
		self->estTriee = false;
}


void col_addVoitureAvecTri(Collection self, const_Voiture voiture)
{
    if(self->estTriee)
    {
        int i = 0;
        int j = 0;
        
        while(voi_getAnnee(self->voitures[i]) > voi_getAnnee(voiture) && i< self->nbVoitures)
        {
            i++;
        }
        self->nbVoitures ++;
        self->voitures = realloc(self->voitures, self->nbVoitures *sizeof(Voiture));
        for(j = self->nbVoitures; j > i ; j--)
        {
            self->voitures[j] = voi_creerCopie(self->voitures[j-1]);
        }
        self->voitures[i] = voi_creerCopie(voiture);
    }
    else
    {
        printf("Liste non triée\n");
        col_addVoitureSansTri(self,voiture);
    }
}


void col_supprVoitureSansTri(Collection self, int pos)
{
	self->voitures[pos] = self->voitures[self->nbVoitures-1];
	self->nbVoitures --;
	self->voitures = realloc(self->voitures, self->nbVoitures *sizeof(Voiture));
	self->estTriee = false;		
}


void col_supprVoitureAvecTri(Collection self, int pos)
{
	if(self->estTriee)
	{
		voi_detruire(self->voitures[pos]);
		for(int i = pos+1; i < self->nbVoitures; i++)
		{
			self->voitures[i-1] = self->voitures[i];
		}
		self->nbVoitures --;
		self->voitures = realloc(self->voitures, self->nbVoitures *sizeof(Voiture));
	}
	else
	{
		col_supprVoitureSansTri(self,pos);
	}
}


void col_trier(Collection self)
{
	int len = self->nbVoitures;
	for (int i = 0; i < len-1; ++i)
	{
		if(voi_getAnnee(self->voitures[i]) > voi_getAnnee(self->voitures[i+1]))
		{
			voi_swap(self->voitures[i], self->voitures[i+1]);
		}
	}
}


void col_afficher(const_Collection self)
{
	printf("La Collection contient la liste suivante : %d\n", self->nbVoitures);
	for (int i = 0; i < self->nbVoitures; i++)
	{
		voi_afficher(self->voitures[i]);
	}
}


void col_ecrireFichier(const_Collection self, FILE *fd)
{

}


void col_lireFichier(Collection self, FILE *fd)
{

}