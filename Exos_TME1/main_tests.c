#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "utilitaires_tableaux.h"
#include "tris.h"


int main() {

  //Partie de création locale d'un tableau

  int n = 15;
  int *tab = nouveau_tableau(n);
  int i = 0;

  for (i = 0; i < n; i++) {
    tab[i] = rand()%10;
  }

  afficher_tab(tab, 15);

  //Partie de création via lecture d'un tableau pour 10 valeurs
  int n2 = 10;
  int *na = &n2;
  int *tab2 = lire_tableau("10_valeurs.txt", na);

  afficher_tab(tab2, 10);

  //Partie de création d'un tableau puis écriture dans un fichier pour 100 valeurs

  int n3 = 100;
  int *tab3 = nouveau_tableau(n3);
  int k;

  for (k = 0; k < n3; k++) {
    tab3[k] = rand()%100;
  }

  afficher_tab(tab3, n3);

  ecrire_tableau("100_valeurs.txt", tab3, 100);

  //Partie de tri des tableaux

  int tableau[] = {5,4,3,2,1};
  int tableauSize = sizeof (tableau) / sizeof (tableau[0]);
  printf("Longueur de tableau = %d\n\n",tableauSize);
  afficher_tab(tableau, tableauSize);
  tri_a_bulle(tableau, tableauSize);
  afficher_tab(tableau, tableauSize);

  return 0;
}
