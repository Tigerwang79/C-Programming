/*
 * Exercice 1
 *
 * Il s'agit de manipuler les chaînes de caractères en C
 * Il y a une fonction par question
 *
 * Les endroits où l'on attend une réponse sont signalés par un :
 *     // ====== TODO ==========
 *
 * note : Une chaîne de caractères n'est a priori qu'un simple tableau
 *        de caractères, mais avec une subtilité : la chaîne se
 *        termine par une case supplémentaire contenant le caractère
 *        de code ASCII 0 que l'on note '\0'.
 *        note : bien que techniquement 0 et '\0' soient la même
 *               chose, ils ne le sont conceptuellement pas ; un
 *               entier et un caractères ne sont pas interchangeables
 * note : un peu de vocabulaire
 *        - un tableau de caractères contenant le mot "chat" est un
 *          un tableau de 4 cases contenant 'c', 'h', 'a' et 't'
 *          C'est d'ailleurs un abus de langage de dire qu'un tableau
 *          contient un mot.
 *        - une chaîne de caractères contenant le mot "chat" est un
 *          un tableau de 5 cases contenant 'c', 'h', 'a', 't' et '\0'
 *          la longueur de la chaîne est 4 et la taille du tableau 5
 *        - bref la difficulté est de penser à gérer cette case
 *          supplémentaire sous peine de débordement de tableau
 * note : on ne fait pas d'allocation dynamique dans cet exercice
 */

#define _XOPEN_SOURCE 500  // pour strdup
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes


/**************************************************************************
 * Question 1a
 * différence entre caractère, chaîne de caratères mutable ou non
 * Une variable mutable est une variable qu'on peut modifier
 * Donc une variable non mutable est une constante
 * c'est un exercice très technique et propre au C
 *
 * note : lorsqu'on utilise un pointeur il y a deux entités :
 *   - le pointeur
 *   - la zone mémoire pointée
 *   Chaque entité (ou les deux) peut être constante ou non
 */
void exo_1a()
{
    // voici une série de déclarations correctes
    char c = 'A';
    char *s1 = "chien";
    char s2[] = "chiot";
    char t[] = {'c', 'h', 'o', 'u', 'x'};

    //On a pas de retour chariot au tableau t ce qui implique qu'il n'y a pas d'espacement entre
    //les deux tableaux chiot et choux.

    // Afficher avec printf les 4 variables, chacune avec un code
    // séparé

    printf("%c\n",c);
    printf("%s\n",s1);
    printf("%s\n",s2);
    printf("%s\n",t);
    printf("\n");

    // ====== TODO ==========

    // La fonction strlen permet de récupérer la longueur d'une chaîne.
    // Si cela a un sens, utiliser cette fonction sur c, s1, s2 et t
    // et expliquer les comportements

    //On ne peux prendre c car la fonction strlen prend en paramètre une chaîne de caractère or
    // c n'est juste qu'un caractère

    printf("%ld\n",strlen(s1));
    printf("%ld\n",strlen(s2));
    printf("%ld\n",strlen(t));
    printf("\n");

    // ====== TODO ==========

    // Quelle est la différence en s1 et s2 ?
    
    // S1 est un pointeur sur un tableau et s2 un tableau de char
    
    // ====== TODO ==========

    // Modifier la 4me lettre de s1 (le 'e') et afficher la nouvelle
    // chaîne ainsi que sa longueur.
    // Cela marche-t-il ? La réponse est non, pourquoi ?

    //s1[3]='i';
    //printf("%ld\n",strlen(s1));
    printf("%s\n",s1);
    printf("\n");

    // Comme s1 est un pointeur il l'initialise comme une une constante qui ne peut donc pas être
    // par défaut modifié
    
    // ====== TODO ==========

    // Modifier la 4me lettre de s2 (le 'o') et afficher la nouvelle
    // chaîne ainsi que sa longueur.
    // Cela marche-t-il ?  La réponse est oui, pourquoi ?

    s2[3]='i';
    printf("%s\n",s2);
    printf("\n");

    // s2 est un tableau simple on peut modifier toutes les cases du tableau
    
    // ====== TODO ==========

    // Combien de cases (si cela a un sens) ont les 4 variables
    // c a 1 case
    // s1 5 cases (pour chaque caractère) + 1 (pour le \0)
    // de même pour s2
    // t a 5 cases + les 5+1 de s2
    
    // ====== TODO ==========

    // Remplacer la 3me lettre (le i) de s2 par le caractère NUL (i.e '\0').
    // Afficher le nouveau contenant ainsi que la longueur.
    // Combien de cases a le tableau s2 ?

    s2[2]='\0';
    printf("%s\n",s2);
    printf("\n");

    // s2 a 2+1 cases dans son tableau
    
    // ====== TODO ==========

    // peut-on appeler strlen sur une chaîne constante ? C'est à dire :

    int l = strlen("champ");
    printf("%d\n",l);
    
    // si oui quel est le résultat ?

     // Oui et le résultat est 5
    
    // ====== TODO ==========

    printf("\n");
}

/**************************************************************************
 * Question 1b
 * Affectation de chaînes
 */

void exo_1b()
{
    const char *s1 = "chien";
    char s2[] = "chiot";
    
    // le but est de recopier une chaîne dans une autre
    // on veut donc faire des affectations (les deux lignes
    // ci-dessus sont des initialisations et non des affectations)
    
    // cas s1
    // l'instruction suivante est-elle correcte et pourquoi ? Si oui
    // que fait-elle ? (la réponse est oui)
    printf("s1 avant : %s\n", s1);
    s1 = "cheval";
    printf("s1 après : %s\n", s1);

    // Elle remplace le mot sur lequel pointe s1
    
    // ====== TODO ==========
    
    // cas s2
    // l'instruction suivante est-elle correcte et pourquoi ?
    // (la réponse est non)
    // s2 = "rat";

    // que faut-il faire pour changer la valeur du tableau ?

    //Il faut faire une boucle while qui va venir changer la valeur du tableau s2	
    int i = 0;
    while(s2[i] != '\0'){  
    s2[i]='d';
    i++;
    }    
    printf("%s\n",s2);

    // on doit modifier le contenu case par case
    
    // ====== TODO ==========
    
    // cas s2 (suite)
    // l'instruction suivante est-elle correcte et pourquoi ? (la réponse
    // est toujours non pour les mêmes raisons)
    // s2 = "cheval";
    // Pourquoi ne peut-on changer la valeur du tableau pour y mettre ce mot ?

    // le mot cheval est plus grand d'une case que le mot chien
    
    // ====== TODO ==========
}

/**************************************************************************
 * Question 1c
 * palindrome ?
 */

// Écrire ici une fonction "isPalin" qui indique si la chaîne passée en
// paramètre est un palindrome (i.e. si la chaîne est identique qu'on
// la lise de gauche à droite ou de droite à gauche)
// note : la déclaration d'une chaîne en paramètre de fonction est
//        généralement
//              "char *"           si la chaîne est modifiée par la fonction
//           ou "const char *"     sinon
// ====== TODO ==========

void isPalin(const char *palin)
{
  int i;
  bool b=true;
  int a = strlen(palin)/2;
  for(i=0; i<a && b==true; i++)
    {
      if(palin[i] != palin[strlen(palin)-1-i])
	   {
	       b=false;
	   }
    }
  if(b)
      printf("C'est un palindrome !!\n");
  else
      printf("Ce n'est pas un palindrome..\n");
}

// Écrire ici une fonction "isPalinTab" qui indique si le tableau de
// caractères passé en paramètre est un palindrome
// rappel : un tableau de caractères n'est pas terminé par '\0'
// note : la déclaration d'un tableau en paramètre de fonction est
//        généralement
//              "char t[]"           si le tableau est modifié par la fonction
//           ou "const char t[]"     sinon

// ====== TODO ==========

void isPalinTab(char t[])
{
  isPalin(t+'\0');
}


void exo_1c()
{
    // appeler isPalin avec "esope reste ici et se repose" puis
    // avec "esoperesteicietserepose"
    // ====== TODO ==========

  isPalin("esope reste ici et se repose");
  isPalin("esoperesteicietserepose");

    // appeler isPalinTab avec un tableau qui n'est pas un palindrome
    // puis avec un palindrome ("etlamarinevaveniramalte" ou "eluparcettecrapule")
    // ====== TODO ==========

  char t[]="table";
  isPalinTab(t);
  char d[]="eluparcettecrapule";
  isPalinTab(d);   
}


/**************************************************************************
 * Question 1d
 * retournement d'une chaîne (image miroir)
 */

// écrire ici une fonction mirror qui transforme la chaîne passée
// en paramètre en son miroir
// ====== TODO ==========

char *mirror(char *s)
{
  char *s_aux = NULL;
  int n = strlen(s);
  if((s_aux = malloc(++n * sizeof(*s_aux))))
	{
	  for(int i=0; i<n; i++)
	    {
	    s_aux[i] = s[n-2-i];
	    s_aux[n-1] = '\0';
	    }
	}
  return s_aux;
}


void exo_1d()
{
    char *s = "il fait beau !";

    printf("Voici la chaîne avant retournement : %s (%ld)\n", s, strlen(s));
    // appeler ici la fonction mirror   
    // ====== TODO ==========

    s=mirror(s);    
    printf("Voici la chaîne après retournement : %s (%ld)\n", s, strlen(s));
}


/**************************************************************************
 * Question 1e
 * version personnelle de strlen
 */

// écrire ici une fonction "mystrlen " qui calcule la longueur
// d'une chaîne (autrement dit qui fait la même chose que strlen)
// ====== TODO ==========

int mystrlen(const char* s)
{
  int i;
  i=0;
  while(s[i] != '\0')
    ++i;
  return i;
}


void exo_1e()
{
    // décommenter une seule ligne
    const char *s = "il fait beau !";
    //const char *s = "aa";
    //const char *s = "aa\n";

    printf("Voici la chaîne : %s\n", s);

    // appeler ici mystrlen et strlen, et afficher le résultat
    // ====== TODO ==========

    int result = mystrlen(s);

    printf("%i\n", result);
}


/**************************************************************************
 * Question 1f
 * version personnelle de strcpy
 */

// écrire ici une fonction mystrcpy qui fait la même chose que strcpy
// note : on suppose toujours, dans ce genre de fonction, que le tableau
// qui reçoit le résultat est déjà alloué et a une taille suffisante
// ====== TODO ==========


void mystrcpy(char *destination, const char *source)
{
  int i;
  int n = strlen(source);
  for(i=0; i<n; i++)
    {
      destination[i] = source[i];
    }
}
  

void exo_1f()
{
    const int MAX = 1000;
    char source[] = "il fait chaud !";
    char cible1[MAX];
    char cible2[MAX];
    


    // Remarque : lorsqu'on copie une chaîne dans un autre tableau,
    // il faut s'assurer que le tableau cible contient suffisament de cases.
    // D'ailleurs combien en faut-il au minimum ?
    // ====== TODO ==========

    // on doit avoir au minimum le même nombre de case que le tableau d'origine.
    
    
    // Que se passe-t-il s'il y en a moins ?
    // ====== TODO ==========

    // cela créera une erreur lors de l'exécution du programme
    
    
    // Et s'il y en a plus ?    
    // ====== TODO ==========

    // rien de particulier à part la mémoire alloué pour rien à l'autre partie inutilisée du tableau
    
    // En l'occurrence, les tableaux ciblés sont a priori sur-dimensionnés,
    // ce qui n'est pas une solution valide ; nous verrons des
    // solutions correctes avec l'allocation dynamique

    // recopiez la source dans cible1 avec strcpy
    // ====== TODO ==========
    strcpy(cible1, source);
    // recopiez la source dans cible2 avec mystrcpy
    // ====== TODO ==========
    mystrcpy(cible2, source);

    // afficher les deux résultats avec leurs longueurs
    // ====== TODO ==========
    printf("Chaîne source : %s (taille %ld)\n", source, strlen(source));
    printf("Chaîne cible1 : %s (taille %ld)\n", cible1, strlen(cible1));
    printf("Chaîne cible2 : %s (taille %ld)\n", cible2, strlen(cible2));
}


/**************************************************************************
 * Question 1g
 * strncpy : utilisation
 */

// juste pour initialiser un tableau avec des lettres identiques
// on parle bien de tableau de caractères et non de chaîne
void exo_1g_init(char tab[], int l, char lettre)
{
    for (int i = 0; i < l; i++)
        tab[i] = lettre;
}

void exo_1g()
{
    char source[] = "bonjour";
    const int LONGUEUR = strlen(source);
    // au fait quelle est la différence entre
    //     strlen(source) et strlen("source") ?
    // ====== TODO ==========
    // source prend ce qu'il y a dans la variable source
    //"source" prend le mot "source"

    char cible1[LONGUEUR - 1];
    char cible2[LONGUEUR];
    char cible3[LONGUEUR + 1];
    char cible4[LONGUEUR + 2];

    exo_1g_init(cible1, LONGUEUR - 1, 'a');
    exo_1g_init(cible2, LONGUEUR, 'b');
    exo_1g_init(cible3, LONGUEUR + 1, 'c');
    exo_1g_init(cible4, LONGUEUR + 2, 'd');

    // appeler strncpy sur source et cible1 avec LONGUEUR-1 en paramètre
    // et afficher cible1 avec sa longueur
    // vérifier si tout est correct et expliquer
    // ====== TODO ==========
    strncpy(cible1,source,LONGUEUR - 1 );
    printf("Chaîne cible1 : %s (taille %ld)\n", cible1, strlen(cible1));
    //il manque le r car on a enlevé la derniere lettre de Bonjour
    // idem avec avec cible2 et LONGUEUR
    // ====== TODO ==========
    strncpy(cible2,source,LONGUEUR );
    printf("Chaîne cible2 : %s (taille %ld)\n", cible2, strlen(cible2));
    // idem avec avec cible3 et LONGUEUR+1
    // ====== TODO ==========
    strncpy(cible3,source,LONGUEUR + 1 );
    printf("Chaîne cible3 : %s (taille %ld)\n", cible3, strlen(cible3));
    // idem avec avec cible4 et LONGUEUR+2
    // ====== TODO ==========
    strncpy(cible4,source,LONGUEUR + 2 );
    printf("Chaîne cible4 : %s (taille %ld)\n", cible4, strlen(cible4));
}


/**************************************************************************
 * Question 1h
 * strcmp : utilisation
 * La fonction strcmp fait bien plus qu'indiquer si deux chaînes
 * sont égales, elle indique également laquelle est la plus "petite"
 * dans l'ordre lexicographique.
 */

void exo_1h()
{
    // voici un ensemble de chaînes à comparer
    char *essais[][2] =
        {
            {"chat", "chat"},
            {"chat", "chien"},
            {"chien", "chat"},
            {"chat", "chaton"},
            {"souris", "elephant"},
            {"souris", "élephant"},
            {"anticonstitutionnellement", "zoo"},
            {"145", "237"},
            {"1453", "22"},
            {"+23", "-23"}
        };
    int nbCouples = sizeof(essais) / sizeof(*essais);

    for (int i = 0; i < nbCouples; i++)
    {
        // appeler strcmp sur essais[i][0] et essais[i][1]
        // et afficher le résultat (en indiquant également "plus petit" "égale"
        // ou "plus grand")
        // ====== TODO ==========
      int a = strcmp(essais[i][0],essais[i][1]);
      if(a == NULL){
	printf("%s est egale a %s\n",essais[i][0],essais[i][1]);
      }else if(a>0){
	printf("%s plus grande que %s\n",essais[i][0],essais[i][1]);
      }else if(a<0){
	printf("%s plus petit que %s\n",essais[i][0],essais[i][1]);
      }
    }
}

/**************************************************************************
 * Question 1i
 * strcmp : version personnelle
 */

// écrire ici une fonction mystrcmp équivalente à strcmp
// proposez un code optimisé, même si c'est au détriment de la lisibilité
// ====== TODO ==========
int mystrcmp(char* mot1, char* mot2){
  int i,k,l;
  int tailleM1= strlen(mot1);
  int tailleM2= strlen(mot2);
  k=0;
  l=0;
  for(i=0;i<tailleM1;i++){
    k+=mot1[i];
  }
  for(i=0;i<tailleM2;i++){
    l+=mot2[i];
  }
  if(k==l){
    return NULL;
  }else{
    return k-l;
  }

}

void exo_1i()
{
    // reprendre l'exercice précédent avec mystrcmp et vérifier
    // que les résultats sont les mêmes
    // ====== TODO ==========
    char *essais[][2] =
        {
            {"chat", "chat"},
            {"chat", "chien"},
            {"chien", "chat"},
            {"chat", "chaton"},
            {"souris", "elephant"},
            {"souris", "élephant"},
            {"anticonstitutionnellement", "zoo"},
            {"145", "237"},
            {"1453", "22"},
            {"+23", "-23"}
        };
    int nbCouples = sizeof(essais) / sizeof(*essais);

    for (int i = 0; i < nbCouples; i++)
    {
      int a = mystrcmp(essais[i][0],essais[i][1]);
      if(a==NULL){
	printf("%s est egale a %s\n",essais[i][0],essais[i][1]);
      }else if(a>0){
	printf("%s plus grande que %s\n",essais[i][0],essais[i][1]);
      }else if(a<0){
	printf("%s plus petit que %s\n",essais[i][0],essais[i][1]);
      }
    }
 
}



/**************************************************************************
 * Question 1j
 * strcat : utilisation
 * La fonction strcat permet de contacténer une chaîne à une autre
 * La difficulté est de s'assurer que le tableau contenant la chaîne
 * à allonger est suffisament grand
 */

void exo_1j()
{
    // on surdimensionne les tableaux pour éviter la gestion mémoire
    char s1[1000] = "il fait beau";
    char s2[1000] = " et chaud";

    // afficher s1 et s2 et leurs longueurs
    // ====== TODO ==========
    printf("Chaîne s1 : %s (taille %ld)\n", s1, strlen(s1));
    printf("Chaîne s2 : %s (taille %ld)\n", s2, strlen(s2));
    // contaténer s2 à la fin de s1
    // ====== TODO ==========
    strcat(s1,s2);
    // afficher s1 et sa longueur
    // ====== TODO ==========
    printf("Chaîne s1 : %s (taille %ld)\n", s1, strlen(s1));
}


/**************************************************************************
 * Question 1k
 * strstr : utilisation
 * La fonction strstr permet de rechercher une sous-chaîne dans une chaîne
 */

void exo_1k()
{
    // décommenter une seule ligne
  const char * s[2] = { "Il fait beau et chaud", "beau" };//Sous_chaine[8]
    //const char * s[2] = { "Il fait beau et chaud", "i" };//Sous_chaine[0]
    //const char * s[2] = { "Il fait beau et chaud", "au" };//Sous_chaine[10][18]
    //const char * s[2] = { "Il fait beau et chaud", "au " };//Sous_chaine[10]
    //const char * s[2] = { "Il fait beau et chaud", "aud" };//Sous_chaine[18]
    //const char * s[2] = { "Il fait beau et chaud", "froid" };//Pas sous_chaine
    //const char * s[2] = { "Il fait beau et chaud", "x" };//Pas sous_chaine

    // Indiquer si s[1] est une sous-chaîne de s[0]
    // ====== TODO ==========
    printf("%s\n", strstr(s[0],s[1]));
  
    // Plus compliqué : si s[1] est une sous-chaîne de s[0], indiquer
    // à quelle position se trouve cette sous-chaîne
    // ====== TODO ==========
}

    

/**************************************************************************
 * Question 1l
 * sprintf ou commenter formater une chaîne
 * cette fonction est exactement la même que printf, si ce n'est
 * qu'au lieu d'être affiché à l'écran, le résultat est mis
 * dans une chaîne
 */

void exo_1l()
{
    const int MAX = 10000;
    char s[MAX];

    int n = 3;
    // mettre dans s la phrase : "Il y a <n> pingouins" où <n> doit être
    // remplacé par la valeur de n
    // ====== TODO ==========
    sprintf(s,"Il y a %d pingouins\n",n);
    printf("vérif : %s\n", s);

    // mettre dans s la table de multiplication jusqu'à n
    // par exemple si n contient 4, s contiendra (retour chariot compris) :
    //       n   1  2  3  4
    //       1   1  2  3  4
    //       2   2  4  6  8
    //       3   3  6  9 12
    //       4   4  8 12 16
    // ====== TODO ==========
    int i,j;
    for(i=0;i<=n;i++){
      for(j=0;j<=n;j++){
	if(i==0 && j==0){
	  sprintf(s,"n   ");
	}else if(i==0){
	  sprintf(s,"%2d ",j);
	}else if(j==0){
	  sprintf(s,"%2d ",i);
	}else
	sprintf(s,"%2d ",i*j);
      }
      sprintf(s,"\n");

    }
    printf("vérif : %s\n", s);
}


/**************************************************************************
 * Question 1m
 * du bon usage des fonctions
 *
 */
void exo_1m()
{
    const int MAX = 10000;
    char s[MAX];

    // Pourquoi ce code est incorrect, i.e. ne fonctionne pas ?
    // On veut ajouter la lettre 'a' à la fin de la chaîne autant
    // de fois qu'il y a de caractères dans la chaîne.
    // ex : si s = "AAA" alors s devient "AAAaaa"
    // ex : si s = "azer" alors s devient "azeraaaa"
    // Corriger le code
    // ====== début TODO ==========
    strcpy(s, "AAA");
    unsigned int length = strlen(s);
    for (unsigned int i = 0; i < length; i++)
    {
        strcat(s, "a");
    }
    //ça ne marche pas parce que strlen(s)augmente en meme temps que s et donc un a une boucle quasi infinie
    
    // ====== fin TODO ==========
    printf("vérif : %s\n", s);

    // Pourquoi ce code, bien que donnant le bon résultat, est incorrect ?
    // on remplace tous les espaces par des points
    strcpy(s, "il fait beau ou chaud");
    // ====== début TODO ==========
    for (unsigned int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
            s[i] = '.';
    }
    //Se code est incorrect car non seulement le on declare et initialisa i dans le for mais on utilise strlen au lieu d'une variable
    
    // ====== fin TODO ==========
    printf("vérif : %s\n", s);
}



/**************************************************************************
 * Question 1n
 * strcmp : utilisation le retour
 * == ou strcmp ?
 *
 * Dans tous les cas testés, il est conseillé de faire un schéma
 * de la mémoire.
 * On se concentre uniquement sur ==, car la fonction strcmp renverra
 * systématiquement vrai
 */

void exo_1n()
{
    // Pourquoi faut-il utiliser strcmp et non == pour comparer 2 chaînas ?
    // ====== TODO ==========
    // Car == n'est pas aussi fiable que strcmp
  
    // illustration 1
    char t1a[] = "chaton";
    char *t1b = "chaton";
    if (t1a == t1b)
        printf("vrai");
    else
        printf("faux");
    printf(" : un [] et un char *\n");
    // Expliquez
    // ====== TODO ==========
    //Faux car on compare un tableau et un pointeur

    // illustration 2
    char t2a[] = "chaton";
    char t2b[] = "chaton";
    if (t2a == t2b)
        printf("vrai");
    else
        printf("faux");
    printf(" : deux []\n");
    // Expliquez
    // ====== TODO ==========
    // Faux car se sont 2 tableau
    
    // illustration 3
    char *t3a = "chaton";
    char *t3b = "chaton";
    if (t3a == t3b)
        printf("vrai");
    else
        printf("faux");
    printf(" : deux char *\n");
    // Expliquez
    // ====== TODO ==========
    //Vrais car se sont deux pointeurs pointant vers un meme mot

    // illustration 4
    char *t4a = "chaton";
    char *t4b = t4a;
    if (t4a == t4b)
        printf("vrai");
    else
        printf("faux");
    printf(" : deux char *\n");
    // Expliquez
    // ====== TODO ==========
    //Vrais car se sont deux pointeurs dont l'un des deux pointe vers l'autre
    
    // illustration 5
    char t5a[] = "chaton";
    char *t5b = t5a;
    if (t5a == t5b)
        printf("vrai");
    else
        printf("faux");
    printf(" : un [] et un char *\n");
    // Expliquez
    // ====== TODO ==========
    // vrais car le pointeur pointe sur le meme mot quele char*

    // illustration 6
    char *t6a = strdup("chaton");
    char *t6b = strdup("chaton");
    if (t6a == t6b)
        printf("vrai");
    else
        printf("faux");
    printf(" : deux char * avec malloc\n");
    // Expliquez
    // ====== TODO ==========
    //
}


/*
 * fin des exercices
 * vous pouvez regarder le code ci-dessous, mais il ne fait pas
 * partie des exercices à faire.
 */


// pour afficher la répétition d'une chaîne
static void header_repeat(const char *s, int n, bool withReturn)
{
    for (int i = 0; i < n; i++)
        printf("%s", s);
    if (withReturn)
        printf("\n");
}

// pour afficher un joli titre encadré
static void header(const char *title)
{
    const int LINE_LENGTH = 75;
    int titleLength = strlen(title);

    printf("\n");
    header_repeat("=", LINE_LENGTH, true);
    printf("= %s", title);
    header_repeat(" ", LINE_LENGTH - titleLength - 4, false);
    printf(" =\n");
    header_repeat("=", LINE_LENGTH, true);
}

// fonction d'erreur
static void usage(const char *exe, const char *msg)
{
    fprintf(stderr,"usage : %s -\n", exe);
    fprintf(stderr,"   ou : %s <lettre>\n", exe);
    fprintf(stderr," - pour lancer toutes les fonctions\n");
    fprintf(stderr," une lettre pour lancer une seule fonction\n");
    if (msg != NULL)
        fprintf(stderr,"message : %s\n", msg);
    exit(EXIT_FAILURE);
}

// the main
int main(int argc, char * argv[])
{
    typedef struct
    {
        char extension;
        void (*fonction)();
        char *titre;
    } Exercice;

    Exercice exercices[] = 
    {
        {'a', exo_1a, "Exercice a"},
        {'b', exo_1b, "Exercice b"},
        {'c', exo_1c, "Exercice c"},
        {'d', exo_1d, "Exercice d"},
        {'e', exo_1e, "Exercice e"},
        {'f', exo_1f, "Exercice f"},
        {'g', exo_1g, "Exercice g"},
        {'h', exo_1h, "Exercice h"},
        {'i', exo_1i, "Exercice i"},
        {'j', exo_1j, "Exercice j"},
        {'k', exo_1k, "Exercice k"},
        {'l', exo_1l, "Exercice l"},
        {'m', exo_1m, "Exercice m"},
        {'n', exo_1n, "Exercice n"}
    };
    const int nbExercices = sizeof(exercices)/sizeof(Exercice);

    if (argc != 2)
        usage(argv[0], NULL);
    if ((argv[1][0] != '-') && ((argv[1][0] < exercices[0].extension) || (argv[1][0] > exercices[nbExercices-1].extension)))
        usage(argv[0], "lettre incorrecte");
    for (int i = 0; i < nbExercices; i++)
    {
        if ((argv[1][0] == exercices[i].extension) || (argv[1][0] == '-'))
        {
            header(exercices[i].titre);
            exercices[i].fonction();
        }
    }

    return EXIT_SUCCESS;
}
