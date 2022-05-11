#ifndef IMAGE_MONO
#define IMAGE_MONO

// todo

#define N 100

typedef struct
{
	int largeur, hauteur;
	char couleur[N];
}ImageMono;

void init(ImageMono *self, int largeur, int hauteur, const char *couleur);
int getLargeur(const ImageMono *self);
int getHauteur(const ImageMono *self);
const char *getCouleur(const ImageMono *self);
void setCouleur(ImageMono *self, const char *couleur);

#endif
