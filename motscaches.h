#include <stdio.h>
#include <stdbool.h>

#define TAILLE_GRILLE 12                                                       
#define TAILLE_MOTS TAILLE_GRILLE + 1
#define TAILLE_LISTE_MOTS 50
#define TAILLE_REPONSE 30



/**
 *
 *  Structure représentant une grille de mots cachés
 *
 *  grille : la grille de lettre
 *  liste_de_mots : la liste des mots
 *  solutionnaire : une grille de même dimension que la grille de mots mais
 *  contenant des false ou des true si les lettres de la grille de mots ont
 *  respectivement été trouvées ou non.
 *  reponse : la réponse finale
 *  nombre_de_mots : le nombre de mots à trouver dans la grille
 *
 */

typedef struct {
   char grille [TAILLE_GRILLE] [TAILLE_GRILLE];           
   char liste_de_mots [TAILLE_LISTE_MOTS] [TAILLE_MOTS];  
   bool solutionnaire [TAILLE_GRILLE] [TAILLE_GRILLE]; 
   char reponse [TAILLE_REPONSE];
   int nombre_de_mots;
} Grille;



/**
 *
 *  Une structure représentant une case d'une grille
 *
 *  x : la coordonnée horizontale de la case
 *  y : la coordonéee verticale de la case
 *
 */

typedef struct {
   int x;
   int y;
} Case;



/**
 *
 *  Ouvre un fichier et retourne un pointeur vers un stream
 *
 *  *fichier : le fichier à ouvrir
 *  
 *  return : un pointeur vers le stream contenant les informations d'une
 *  grille
 *
 */

FILE* ouvrir_fichier(char *fichier);



/**
 *
 *  Génère la grille de mot d'une grille
 *
 *  *grille : un pointeur vers la grille
 *  *fichier : un pointeur vers un stream ou lire les données
 *
 */

void creer_grille(Grille *grille, FILE *fichier);



/**
 *
 *  Génère la liste de mots d'une grille
 *
 *  *grille : un pointeur vers la grille
 *  *fichier : un pointeur vers un stream ou lire les données
 *
 */

void creer_liste_mots(Grille *grille, FILE *fichier);



/**
 *
 *  Initialise toutes les case de la grille du solutionnaire à true
 *
 *  *grille : un pointeur vers la grille
 *
 */

void initialiser_solutionnaire(Grille *grille);



/**
 *
 *  Compare deux lettre
 *
 *  mot_liste : la première lettre d'un mot à trouver
 *  mot_grille : une lettre de la grille de mots
 *
 *  return : true si les lettres sont égales, sinon false
 *
 */

bool comparer_lettres(const char mot_liste, const char mot_grille);



/**
 *
 *  Vérifie que l'indice d'une lettre ne dépasse pas les bornes d'une grille
 *
 *  indice : l'indice à vérifier
 *
 *  return : true si l'indice est à l'intérieur des bornes, sinon false
 *
 */

bool valider_indice(const int indice);



/**
 *
 *  Cherche un mot dans la grille de mot et met les valeurs correspondates
 *  du solutionnaire à false
 *
 *  *grille : un pointeur vers la grille dans laquelle chercher
 *  *mot : un pointeur vers le mot à trouver
 *
 */

void resoudre_mot ( Grille *grille, const char *mot );




/**
 *
 *  Vérifie si un mot dépasse la borne droite d'une grille de mots à partir
 *  d'une case de la grille
 *
 *  *case_ : un pointeur vers la case correspondant à la première lettre du mot
 *  *mot : un pointeur vers le mot à trouver
 *
 *  return : true si le mot ne dépasse pas les bornes, sinon false
 *
 */

bool valider_longueur_droite ( const Case *case_, const char *mot );



 /**
 *
 *  Vérifie si un mot dépasse la borne gauche d'une grille de mots à partir
 *  d'une case de la grille
 *
 *  *case_ : un pointeur vers la case correspondant à la première lettre du mot
 *  *mot : un pointeur vers le mot à trouver
 *
 *  return : true si le mot ne dépasse pas les bornes, sinon false
 *
 */

bool valider_longueur_gauche ( const Case *case_, const char *mot ); 



/**
 *
 *  Vérifie si un mot dépasse la borne en bas d'une grille de mots à partir
 *  d'une case de la grille
 *
 *  *case_ : un pointeur vers la case correspondant à la première lettre du mot
 *  *mot : un pointeur vers le mot à trouver
 *
 *  return : true si le mot ne dépasse pas les bornes, sinon false
 *
 */

bool valider_longueur_bas ( const Case *case_, const char *mot ); 



/**
 *
 *  Vérifie si un mot dépasse la borne en haut d'une grille de mots à partir
 *  d'une case de la grille
 *
 *  *case_ : un pointeur vers la case correspondant à la première lettre du mot
 *  *mot : un pointeur vers le mot à trouver
 *
 *  return : true si le mot ne dépasse pas les bornes, sinon false
 *
 */

bool valider_longueur_haut ( const Case *case_, const char *mot );



/**
 *
 *  Vérifie si chaque lettre d'un mot correspond à chaque lettre d'une grille
 *  à partir d'une case de la grille vers la droite
 *
 *  *grille : un pointeur vers la grille
 *  *case_ : un pointeur vers la case correspondant à la première lettre du mot
 *  *mot : un pointeur vers le mot à trouver
 *
 *  return : true si toutes les lettres correspondent, sinon false
 *
 */

bool comparer_droite (const Grille *grille, const Case *case_, const char *mot);



/**
 *
 *  Vérifie si chaque lettre d'un mot correspond à chaque lettre d'une grille
 *  à partir d'une case de la grille vers la gauche
 *
 *  *grille : un pointeur vers la grille
 *  *case_ : un pointeur vers la case correspondant à la première lettre du mot
 *  *mot : un pointeur vers le mot à trouver
 *
 *  return : true si toutes les lettres correspondent, sinon false
 *
 */

bool comparer_gauche (const Grille *grille, const Case *case_, const char *mot);



/**
 *
 *  Vérifie si chaque lettre d'un mot correspond à chaque lettre d'une grille
 *  à partir d'une case de la grille vers le haut
 *
 *  *grille : un pointeur vers la grille
 *  *case_ : un pointeur vers la case correspondant à la première lettre du mot
 *  *mot : un pointeur vers le mot à trouver
 *
 *  return : true si toutes les lettres correspondent, sinon false
 *
 */

bool comparer_haut (const Grille *grille, const Case *case_, const char *mot);



/**
 *
 *  Vérifie si chaque lettre d'un mot correspond à chaque lettre d'une grille
 *  à partir d'une case de la grille vers le bas
 *
 *  *grille : un pointeur vers la grille
 *  *case_ : un pointeur vers la case correspondant à la première lettre du mot
 *  *mot : un pointeur vers le mot à trouver
 *
 *  return : true si toutes les lettres correspondent, sinon false
 *
 */

bool comparer_bas (const Grille *grille, const Case *case_, const char *mot);



/**
 *
 *  Met toutes les valeurs des case correspondant à un mot à false dans le
 *  solutionnaire d'un mot trouvé vers la droite
 *
 *  *grille : un pointeur vers la grille
 *  *case_ : un pointeur vers la case correspondant à la première lettre du mot
 *  *mot : un pointeur vers le mot à trouver
 *
 */

void resoudre_droite (Grille *grille, const Case *case_, const char *mot);



/**
 *
 *  Met toutes les valeurs des case correspondant à un mot à false dans le
 *  solutionnaire d'un mot trouvé vers la gauche
 *
 *  *grille : un pointeur vers la grille
 *  *case_ : un pointeur vers la case correspondant à la première lettre du mot
 *  *mot : un pointeur vers le mot à trouver
 *
 */

void resoudre_gauche (Grille *grille, const Case *case_, const char *mot);



/**
 *
 *  Met toutes les valeurs des case correspondant à un mot à false dans le
 *  solutionnaire d'un mot trouvé vers le haut
 *
 *  *grille : un pointeur vers la grille
 *  *case_ : un pointeur vers la case correspondant à la première lettre du mot
 *  *mot : un pointeur vers le mot à trouver
 *
 */

void resoudre_haut (Grille *grille, const Case *case_, const char *mot);



/**
 *
 *  Met toutes les valeurs des case correspondant à un mot à false dans le
 *  solutionnaire d'un mot trouvé vers le bas
 *
 *  *grille : un pointeur vers la grille
 *  *case_ : un pointeur vers la case correspondant à la première lettre du mot
 *  *mot : un pointeur vers le mot à trouver
 *
 */

void resoudre_bas (Grille *grille, const Case *case_, const char *mot);



/**
 *
 *  Résout un mot dans toutes les directions
 *
 *  *grille : un pointeur vers la grille
 *  *case_ : un pointeur vers la case correspondant à la première lettre du mot
 *  *mot : un pointeur vers le mot à trouver
 *
 */

void resoudre_multidirection (Grille *grille, const Case *case_, const char *mot);



/**
 *
 *  Résout un mot
 *
 *  *grille : un pointeur vers la grille
 *  *mot : un pointeur vers le mot à trouver
 *
 */

void resoudre_mot ( Grille *grille, const char *mot );



/**
 *
 *  Résout une grille en entier
 *
 *  *grille : un pointeur vers la grille à résoudre
 *
 */

void resoudre ( Grille *grille );



/**
 *
 *  Affiche la réponse d'une grille
 *
 *  grille : un pointeur vers la grille
 *
 */

void afficher_reponse ( Grille *grille);
