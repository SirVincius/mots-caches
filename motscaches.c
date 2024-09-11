#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "motscaches.h"

void valider_nombre_arguments (int nombre_arguments) {
   if ( nombre_arguments != 2 ) {
      fprintf(stderr, "Erreur, nombre d'arguments invalide.\n");
      exit(1);
   }
}

FILE* ouvrir_fichier (char *fichier ) {
   FILE *file = fopen( fichier, "r" );
   if ( file == NULL ) {
      fprintf(stderr, "Erreur, échec de lecture du fichier.\n");
      exit(1);
   }
   return file;
}

void creer_grille(Grille *grille, FILE* fichier) {
   for ( int i = 0; i < TAILLE_GRILLE; i++ ) { 
        for ( int j = 0; j < TAILLE_GRILLE; j++) {
            grille->grille[i][j] = fgetc(fichier);
        }
        fgetc(fichier); //Supprime le retour de ligne.
    }

}

void creer_liste_mots(Grille *grille, FILE *fichier) {
   char mot[TAILLE_MOTS];
   int compte = 0;
   while (fscanf(fichier, "%s", mot) != EOF) {
      strcpy(grille->liste_de_mots[compte], mot);
      compte++;
   }
   grille->nombre_de_mots = compte;
}

void initialiser_solutionnaire(Grille *grille) {
   for ( int i = 0; i < TAILLE_GRILLE; i++ ) { 
        for ( int j = 0; j < TAILLE_GRILLE; j++) {
            grille->solutionnaire[i][j] = true;
        }
    }
}

bool comparer_lettres(const char lettre_mot_liste, const char lettre_mot_grille) {
   return ( lettre_mot_liste == lettre_mot_grille );
}

bool valider_indice(const int indice) {
   return ( indice < 0 || indice > TAILLE_GRILLE -1 );
}

void resoudre_mot ( Grille *grille, const char *mot ) {
   for ( int i = 0; i < TAILLE_GRILLE; i++ ) {
      for ( int j = 0; j < TAILLE_GRILLE; j++) {
         if ( mot[0] == grille->grille[i][j] ) {
            Case case_ = { j, i };
            resoudre_multidirection(grille, &case_, mot);
         }
      }
   }
}

bool valider_longueur_droite ( const Case *case_, const char *mot ) {
   int indice = case_->x + strlen(mot);
   return ( indice <= TAILLE_GRILLE );
}

bool valider_longueur_gauche ( const Case *case_, const char *mot ) {
   int indice = case_->x - strlen(mot) + 1;
   return ( indice >= 0 );
}

bool valider_longueur_bas ( const Case *case_, const char *mot ) {
   int indice = case_->y + strlen(mot);
   return ( indice <= TAILLE_GRILLE );
}

bool valider_longueur_haut ( const Case *case_, const char *mot ) {
   int indice = case_->y - strlen(mot) + 1;
   return ( indice >= 0 );
}

bool comparer_droite (const Grille *grille, const Case *case_, const char *mot) {
   int x = case_->x;
   int y = case_->y;
   bool mot_trouve = true;
   for ( int i = 0; i < strlen(mot); i++ ) {
      if ( mot[i] != grille->grille[y][x + i] )
         mot_trouve = false;
   }
   return mot_trouve;
}

bool comparer_gauche (const Grille *grille, const Case *case_, const char *mot) {
    int x = case_->x;
    int y = case_->y;
    bool mot_trouve = true;
    for ( int i = 0; i < strlen(mot); i++ ) { 
        if ( mot[i] != grille->grille[y][x - i] )
            mot_trouve = false;
    }
    return mot_trouve;
}

bool comparer_haut (const Grille *grille, const Case *case_, const char *mot) {
    int x = case_->x;
    int y = case_->y;
    bool mot_trouve = true;
    for ( int i = 0; i < strlen(mot); i++ ) { 
        if ( mot[i] != grille->grille[y - i][x] )
            mot_trouve = false;
    }
    return mot_trouve;
}

bool comparer_bas (const Grille *grille, const Case *case_, const char *mot) {
    int x = case_->x;
    int y = case_->y;
    bool mot_trouve = true;
    for ( int i = 0; i < strlen(mot); i++ ) { 
        if ( mot[i] != grille->grille[y + i][x] )
            mot_trouve = false;
    }
    return mot_trouve;
}



void resoudre_droite (Grille *grille, const Case *case_, const char *mot) {
   if ( valider_longueur_droite (case_, mot) && comparer_droite ( grille, case_, mot)) {
   for ( int i = 0; i < strlen(mot); i++ )
      grille->solutionnaire[case_->y][case_->x + i] = false;
   }
}

void resoudre_gauche (Grille *grille, const Case *case_, const char *mot) {
   if ( valider_longueur_gauche (case_, mot) && comparer_gauche ( grille, case_, mot)) {
   for ( int i = 0; i < strlen(mot); i++ )
      grille->solutionnaire[case_->y][case_->x - i] = false;
   }
}

void resoudre_haut (Grille *grille, const Case *case_, const char *mot) {
   if ( valider_longueur_haut (case_, mot) && comparer_haut ( grille, case_, mot)) {
   for ( int i = 0; i < strlen(mot); i++ )
      grille->solutionnaire[case_->y - i][case_->x] = false;
   }
}

void resoudre_bas (Grille *grille, const Case *case_, const char *mot) {
   if ( valider_longueur_bas (case_, mot) && comparer_bas ( grille, case_, mot)) {
   for ( int i = 0; i < strlen(mot); i++ )
      grille->solutionnaire[case_->y + i][case_->x] = false;
   }
}

void resoudre_multidirection (Grille *grille, const Case *case_, const char *mot) {
   resoudre_droite (grille, case_, mot);
   resoudre_gauche (grille, case_, mot);
   resoudre_haut (grille, case_, mot);
   resoudre_bas (grille, case_, mot);
}

void resoudre ( Grille *grille ) {
   for ( int i = 0; i < grille->nombre_de_mots; i++ ) {
      resoudre_mot (grille, grille->liste_de_mots[i]);
   }
}

void afficher_reponse ( Grille *grille) {
   int indice = 0;
   for ( int i = 0; i < TAILLE_GRILLE; i++ ) {
      for ( int j = 0; j < TAILLE_GRILLE; j++ ) {
         if ( grille->solutionnaire[i][j] ) 
            grille->reponse[indice++] = grille->grille[i][j];
      }
   }
   grille->reponse[indice] = '\0';
   printf("%s\n", grille->reponse);
}

int main (int argc, char *argv[]) {
   valider_nombre_arguments( argc );
   FILE *file = ouvrir_fichier(argv[1]);
   Grille grille;
   creer_grille(&grille, file);
   creer_liste_mots(&grille, file);
   initialiser_solutionnaire(&grille);
   resoudre(&grille);
   afficher_reponse(&grille);
   return 0;
}
