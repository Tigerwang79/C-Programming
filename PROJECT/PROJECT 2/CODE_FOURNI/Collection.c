/********************************************************************
 * Module de Collection : corps
 * Auteurs : Salihi Valdrin, Pierre Guillaume.
 ********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "Collection.h"
#include "myassert.h"


//------ Mettre des commentaires à chaque fonction ------//


// La structure de notre liste doublement chaînés non circulaire
typedef struct lstdouble
{
	struct lstdouble *suiv, *prec;
	Voiture voiture;
} *t_ldouble;


// La structure de notre Collection
struct CollectionP
{
	int nbVoitures;
	t_ldouble lstVoiture;
	bool estTriee;
};


/*----------*
 * Fonction utilisé pour les listes doublements chaînées
 *----------*/


// La fonction permettant de rembobiner notre liste
t_ldouble lrewind(t_ldouble l)
{
	if(l != NULL)
	{
		while(l->prec != NULL)
		{
			l = l->prec;
		}
	}
	
	return l;
}


// La fonction permettant de parcourir la liste 
t_ldouble atEnd(t_ldouble l)
{
	if(l != NULL)
	{
		while(l->suiv != NULL)
		{
			l = l->suiv;
		}
	}
	return l;
}


// L'initialsation de la liste et des éléments qu'elle est censé contenir
t_ldouble init()
{
	t_ldouble l;
	l = malloc(sizeof(struct lstdouble));

   	l->suiv = NULL;
	l->prec = NULL;
	l->voiture = NULL;

	return l;
}


/*----------*
 * initialisation de la structure
 *----------*/


// Création de la collection
Collection col_creer()
{
	
	Collection self;
	self = malloc(sizeof(struct CollectionP));
	self->nbVoitures = 0;
	self->lstVoiture = NULL;
	self->estTriee = true;
	myassert_func(self != NULL, "col non creer", "Collection.c", "col_creer", 93); // 1er assert dans la fonction si la collection a bien été crée
	return self;
}


// Création de copie de la collection
Collection col_creerCopie(const_Collection source)
{
	int nbrVoitures = col_getNbVoitures(source);
	Collection self = col_creer();	// On vient ici se servir de la fonction précédente déjà créer "col_creer()"
	t_ldouble l = lrewind(source->lstVoiture);
	myassert_func(self != NULL, "col non creer", "Collection.c", "col_creerCopie", 104);	// 2nd assert pour vérifier ici si la copie de collection est bien crée
	myassert_func(l != NULL, "liste double non creer", "Collection.c", "col_creerCopie", 105);	// 3eme assert pour vérifier si la liste doublement chaînés est crée
	
	for (int i = 0; i < nbrVoitures; i++)
	{
		col_addVoitureSansTri(self, l->voiture);  // On va utiliser ici la fonction permettant d'ajouter les voitures sans tri "col_addVoitureSansTri"
		l = l->suiv;
	}
	self->estTriee = source->estTriee;
	return self;
}


// Fonction qui va détruire notre collection
void col_detruire(Collection *pself)
{
	col_vider(*pself);  // On va utiliser pour cela la fonction suivante "col_vider" qui elle même fera appel à une autre fonction pour pouvoir vider notre collection de voiture
	free(*pself);		// Utilisation du free pour libérer l'espace alloué
	*pself = NULL;
	myassert_func(pself != NULL, "pself n'est pas null", "Collection.c", "col_detruire", 123);  // 4eme assert pour tester si notre pself a bien été détruit
}


// Fonction permettant de vider la liste de voitures de notre collection
void col_vider(Collection self)
{
	int len = col_getNbVoitures(self);

	for(int i = 0; i < len; i++)
	{
		col_supprVoitureSansTri(self, 0);  // Appel de la fonction "col_supprVoitureSansTri" pour supprimer la liste de voitures
	}
	self->lstVoiture = NULL;
	myassert_func(self->lstVoiture == NULL, "list double n'est pas null", "Collection.c", "col_vider", 137);   // 5eme assert pour vérifier que la liste est bien vidé 
}


/*----------*
 * accesseurs
 *----------*/


// Fonction servant à récupérer le nombre de voitures dans la collection
int col_getNbVoitures(const_Collection self)
{
	return self->nbVoitures;
}


// Fonction permettant de récupèrer une copie de la voiture
Voiture col_getVoiture(const_Collection self, int pos)
{
	t_ldouble liste = lrewind(self->lstVoiture);
	Voiture car;

	for (int i = 0; i < pos; i++)
	{
		liste = liste->suiv;
	}
	car = voi_creerCopie(liste->voiture);
	return car;
}


// Fonction d'ajout de voiture sans tri dans la collection
void col_addVoitureSansTri(Collection self, const_Voiture voiture)
{
	self->nbVoitures++;
	t_ldouble l = self->lstVoiture;
	l = atEnd(l);

	if(l == NULL)
	{
		l = init();
		l->voiture = voi_creerCopie(voiture);
	}
	else
	{
		l->suiv = init();
		l->suiv->voiture = voi_creerCopie(voiture);
		l->suiv->prec = l;
	}
	if(self->nbVoitures > 1)
	{
        self->estTriee = false;
    }
	self->lstVoiture = l;
}


// Fonction d'ajout de voiture avec tri dans la collection
void col_addVoitureAvecTri(Collection self, const_Voiture voiture)
{
    self->lstVoiture = lrewind(self->lstVoiture);
    Voiture car = voi_creerCopie(voiture);
    t_ldouble col = init();
    //vamyassert_func(l != NULL, "l déjà initialisé", "Collection.c", "col_addVoitureAvecTri", 200);   // 6eme assert pour vérifier que la liste n'a pas déjà été initialisé

    if (self->lstVoiture == NULL)
    {
        col->prec = NULL;
        col->suiv = NULL;
        col->voiture = car;
        self->lstVoiture = col;
    }
    else
    {
        while(voi_getAnnee(self->lstVoiture->voiture) < voi_getAnnee(voiture) && self->lstVoiture->suiv != NULL)
        {
            self->lstVoiture = self->lstVoiture->suiv;
        }
        if (self->lstVoiture->prec == NULL)
        {
            col->prec = NULL;
        }
        else
        {
            col->prec = self->lstVoiture->prec;
            self->lstVoiture->prec->suiv = col;
        }
        col->voiture = car;
        col->suiv = self->lstVoiture;
        self->lstVoiture->prec = col;
    }
    self->nbVoitures++;
}


// Fonction de suppression de voiture sans tri
void col_supprVoitureSansTri(Collection self, int pos)
{
	t_ldouble l = lrewind(self->lstVoiture);
	t_ldouble tmp = NULL;
	
	for(int i = 0; i < pos; i++){
		l = l->suiv;
	}


	voi_detruire(&(l)->voiture);
	if(l->prec != NULL){
		tmp = l->prec;
		l->prec->suiv = l->suiv;
	}
	if(l->suiv != NULL){
		tmp = l->suiv;
		l->suiv->prec = l->prec;
	}
	self->nbVoitures--;
	free(l);
	self->lstVoiture = tmp;

}


// Fonction de suppression de voiture avec tri
void col_supprVoitureAvecTri(Collection self, int pos){

	t_ldouble l = lrewind(self->lstVoiture);
	t_ldouble tmp = NULL;
	
	for(int i = 0; i < pos; i++){
		l = l->suiv;
	}


	voi_detruire(&(l)->voiture);
	if(l->prec != NULL){
		tmp = l->prec;
		l->prec->suiv = l->suiv;
	}
	if(l->suiv != NULL){
		tmp = l->suiv;
		l->suiv->prec = l->prec;
	}
	self->nbVoitures--;
	free(l);
	self->lstVoiture = tmp;
}


// Fonction de tri de la collection
void col_trier(Collection self)
{
    if (self!=NULL)
    {
        if(!(self->estTriee))
        {
            for(int i = 0 ; i < self->nbVoitures ; i++)
            {
                self->lstVoiture = lrewind(self->lstVoiture);
                for(int j=0; j < self->nbVoitures - i - 1; j++)
                {
                    if(voi_getAnnee(self->lstVoiture->voiture) > voi_getAnnee(self->lstVoiture->suiv->voiture))
                    {
                        voi_swap(self->lstVoiture->voiture, self->lstVoiture->suiv->voiture);
                    }
                    self->lstVoiture = self->lstVoiture->suiv;
                }
            }
            self->estTriee = true;
        }
    }
}


/*----------*
 * méthode secondaire d'affichage
 *----------*/


// Fonction de l'affichage de notre collection
void col_afficher(const_Collection self)
{

	int nbrVoitures = col_getNbVoitures(self);
	t_ldouble liste = lrewind(self->lstVoiture);

	for (int i = 0; i < nbrVoitures; i++)
	{
			voi_afficher(liste->voiture);
			liste = liste->suiv;
	}
}


/*----------*
 * entrées-sorties fichiers
 * note : le paramètre est un fichier déjà ouvert
 *----------*/


// Fonction d'écriture de la collection dans le fichier 
void col_ecrireFichier(const_Collection self, FILE *fd)
{
	Collection c = col_creerCopie(self);
	int len = col_getNbVoitures(c);
	fwrite(&(self)->nbVoitures, sizeof(int), 1, fd);
	fwrite(&(self)->estTriee, sizeof(bool), 1, fd);
	t_ldouble l = c->lstVoiture;

	for (int i = 0; i < len; i++)
	{
		voi_ecrireFichier(l->voiture, fd);
		l = l->suiv;
	}
}


// Fonction de lecture de la collection dans le fichier
void col_lireFichier(Collection self, FILE *fd)
{
	int len = col_getNbVoitures(self);
	fread(&(self)->nbVoitures, sizeof(int), 1, fd);
	fread(&(self)->estTriee, sizeof(bool), 1, fd);
	t_ldouble l = self->lstVoiture;

	for (int i = 0; i < len; i++)
	{
		voi_lireFichier(l->voiture, fd);
		l = l->suiv;
	}
}