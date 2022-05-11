#include <string.h>

// todo

#include "ImageMono.h"

void init(ImageMono *self, int largeur, int hauteur, const char *couleur)
{
	self->largeur = largeur;
	self->hauteur = hauteur;
	strcpy(self->couleur, couleur);
}

int getLargeur(const ImageMono *self)
{
	return self->largeur;
}

int getHauteur(const ImageMono *self)
{
	return self->hauteur;
}

const char *getCouleur(const ImageMono *self)
{
	return self->couleur;
}

void setCouleur(ImageMono *self, const char *couleur)
{
	strcpy(self->couleur, couleur);
}