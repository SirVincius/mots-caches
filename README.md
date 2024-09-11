Description
-
Ce projet permet de lire une grille de mots cachés ainsi qu'une liste de mots dans un fichier, de solutionner la grille et d'imprimer la réponse.

Ce projet est présenté à Mr. **Serge Dogny** dans le cadre du cours **"Construction et maintenance de logiciels - INF3135"** à l'**UQAM**.

[Sujet du travail](https://ena01.uqam.ca/mod/folder/view.php?id=3183636)

Auteur
-
Vincent Brunelle ( BRUV28018509 )

Fonctionnement
-
1. Clôner le dépôt
2. Déplacez-vous dans le dépôt
3. Tapez la commande `$ make`
4. Tapez la commande `./motscaches nom_du_fichier`

Cible
-
* link : Lie les fichier .o et crée l'exécutable
* compile : Compile les fichiers .c
* test : Lance la suite de tests
* clean : Supprime l'exécutable et les fichiers .o

Tests
-
Pour lancer la suite de test il suffit de taper la commande `$ make test`

Dépendances
-
* GCC ( Pour la compilation )
* Bats [Bats](https://github.com/bats-core/bats-core) ( Pour les tests )
