#include <stdlib.h>
#include "liste.h"
#include "devel.h"
#include "fonctions_entiers.h"

int main(void) {

  int i1 = 1;
  int i2 = 22;
  int i3 = 333;

  int *i4 = dupliquer_int(&i1);

  int i5;
  copier_int(&i2, &i5);

  // Affichage des entiers

  afficher_int(&i1);
  afficher_int(&i2);
  afficher_int(&i3);
  afficher_int(i4);
  afficher_int(&i5);


  /* La destruction marche correctement

  detruire_int(&i5);

  afficher_int(&i5);
  */

  // Comparaison d'entiers

  int i6 = comparer_int(&i2, &i5);
  afficher_int(&i6);

  // Ecriture et lecture de fichiers

  FILE *fichier;
  fichier = fopen("fichier_ecriture_int.txt", "w+");

  int ecriture = ecrire_int(&i1, fichier);
  afficher_int(&ecriture);

  fclose(fichier);

  FILE *fichier2;
  fichier2 = fopen("fichier_ecriture_int.txt", "r+");

  afficher_int(lire_int(fichier2));

  fclose(fichier2);

  return 0;
}
