#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "arbre_binaire.h"
#include "fonctions_entiers.h"

int main(void) {
  srand(time(NULL));

  // Création d'un arbre
  PArbreBinaire arbre1 = creer_arbre("", dupliquer_int, copier_int, detruire_int, afficher_int, comparer_int, ecrire_int, lire_int);

  // On lui attribue des valeurs et des arbres à l'arbre arbre1
  int i;
  for (i = 0; i < 10; i++) {
    int j = rand()%100;
    ajouter_abr(arbre1, &j);
  }
  
  // On affiche l'arbre arbre1
  printf("\n");
  afficher_ab_infixe(arbre1);
  printf("\n\n");

  // Ecriture de l'arbre arbre1 dans un fichier .txt
  ecrire_ab(arbre1, "Writing_trees.txt");
  
  return 0;
}
