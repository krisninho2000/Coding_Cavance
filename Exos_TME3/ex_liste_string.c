#include <stdlib.h>
#include "liste.h"
#include "devel.h"
#include "fonctions_string.h"
#include <string.h>

int main(void) {
  
  // Création et allocation des string principaux

  char *word1;
  char *word2;
  char *word3;

  word1 = (char *)malloc(100 * sizeof(char));
  word2 = (char *)malloc(100 * sizeof(char));
  word3 = (char *)malloc(100 * sizeof(char));

  word1 = strcpy(word1, "Hello World");
  word3 = strcpy(word3, "Pizza and Tacos");

  // Utilisation des fonctions de duplication et copie

  char *word4 = dupliquer_str(word1);
  copier_str(word1, word2);

  // Affichage des string

  afficher_str(word1);
  afficher_str(word2);
  afficher_str(word3);
  afficher_str(word4);
  printf("\n");

  // Comparaison des éléments string

  printf("%d\n", comparer_str(word1, word2));
  printf("%d\n", comparer_str(word1, word3));
  printf("\n");

  // Ecriture dans des fichiers

  FILE *docw;
  docw = fopen("fichier_ecriture_string.txt", "w+");

  char *word5;
  word5 = (char *)malloc(100 * sizeof(char));

  word5 = strcpy(word5, "Nachos");

  afficher_str(word5);
  printf("\n");

  int i = ecrire_str(word5, docw);

  fclose(docw);

  // Lecture dans des fichiers

  FILE *docr;
  docr = fopen("fichier_ecriture_string.txt", "r+");

  char *word6 = lire_str(docr);

  fclose(docr);

  afficher_str(word6);

  // Suppression des éléments

  printf("\n");
  detruire_str(word1);
  detruire_str(word2);
  detruire_str(word3);
  detruire_str(word4);
  detruire_str(word5);
  detruire_str(word6);

  printf("Suppression effectuée\n\n");
  
  return 0;
}
