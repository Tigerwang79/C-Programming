#ifndef IMAGE_MONO
#define IMAGE_MONO

//##
//## Donc on ne gère pas ici la taille de la chaîne
//## Les commentaires commençant par //## sont pédagogiques
//## Les autres commentaires font partie intégrante du code
//## Note : les commentaires dans un .h ne concernent que l'utilisateur
//##        du module et donc ne doivent pas être des commentaires décrivant
//##        l'implémentation (ce type de commentaires sont dans le fichier .c).
//##        Par exemple on explicitera le domaine de validité d'un paramètre.
//## Note : il est primordial de mettre le mot-clé "const" quand un paramètre
//##        n'est pas modifié par une fonction.
//##

//## première remarque a priori surprenante :
//## - la définition de la structure de doit pas être ici
//## En effet c'est un choix d'implémentation qui ne regarde pas
//## l'utilisateur.
//## Exemple : c'est le problème du concepteur de savoir s'il stocke
//##      la largeur et la hauteur dans deux variables séparées ou
//##      dans un tableau à 2 cases ; et surtout il doit pouvoir le
//##      changer dans impacter l'utilisateur ou même sans que
//##      celui-ci soit au courant
//##
//## Ceci dit, supprimer la définition de la structure dans le .h n'est
//## pas chose simple. Nous verrons ultérieurement comment faire
//## avec l'abstraction pointeur.

#define N 100
typedef struct
{
    int largeur, hauteur;
    char couleur[N];
} ImageMono;


// "constructeur"
// - largeur et hauteur doivent être positifs
// - la couleur ne doit pas être vide
// Ne pas respecter ces directives peut conduire à des erreurs d'exécution
//## Tous ces commentaires apportent une information utile à l'utilisateur,
//## notamment les conséquences s'il ne respecte pas les restrictions.
//## Le fait que les valeurs erronées ne soit pas gérées par le module
//## n'est pas une faute de programmation, c'est un choix ; c'est ce qu'on
//## appelle la programmation par contrat.
//## Note : on a fait le choix de passer en paramètre (par pointeur) la
//##        structure à initialiser ; cela aussi pu être le retour de la
//##        fonction (avec un petite perte d'efficacité)
void init(ImageMono *self, int largeur, int hauteur, const char *couleur);

int getLargeur(const ImageMono *self);
int getHauteur(const ImageMono *self);
// la largeur et la hauteur ne peuvent pas être modifiées après
// l'initialisation, d'où l'absence des setters

const char * getCouleur(const ImageMono *self);
// la couleur ne doit pas être vide
void setCouleur(ImageMono *self, const char *couleur);

#endif
