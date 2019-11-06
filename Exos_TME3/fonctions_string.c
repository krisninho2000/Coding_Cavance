#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "devel.h"

void *dupliquer_str(const void *src) {
  char *isrc = (char *)src;
  char *idst;
  idst = (char *)malloc(100 * sizeof(char));
  if (idst == NULL) {
    affiche_message("Erreur d'allocation");
    return NULL;
  }
  idst = strcpy(idst, isrc);
  return (void *)idst;
}

void copier_str(const void *src, void *dst) {
  strcpy(dst, src);
}

void detruire_str(void *data) {
  free(data);
}

void afficher_str(const void *data) {
  char *idata=(char *)data;
  printf("%s\n",idata);
}

int comparer_str(const void *a, const void *b) {
  char *ia = (char *)a;
  char *ib = (char *)b;
  return (*ia > *ib) - (*ia < *ib);
}

int ecrire_str(const void *data, FILE *f) {
  const char *idata = (const char *)data;
  return fprintf(f, "%s\n", idata);
}

void *lire_str(FILE *f) {
  char copy[100];

  char r = fscanf(f, "%s", copy);
  if (r < 1) return NULL;

  char *pi = (char *)malloc(100 * sizeof(char));
  strcpy(pi, copy);
  return pi;
}