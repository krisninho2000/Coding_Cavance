#include <stdlib.h>
#include <stdio.h>
#include "devel.h"

#include "fonctions_2entiers.h"

void *dupliquer_2int(const void *src) {
  Double_int *isrc = (Double_int *)src;
  Double_int *idst;

  idst = (Double_int *)malloc(sizeof(Double_int));
  if (idst == NULL) {
    affiche_message("Erreur d'allocation");
    return NULL;
  }

  Double_int newvalues;
  newvalues.a = isrc->a;
  newvalues.b = isrc->b;
  *idst = newvalues;

  return (void *)idst; 
}

void copier_2int(const void *src, void *dst) {
  Double_int *isrc = (Double_int *)src;
  Double_int *idst = (Double_int *)dst;

  *idst = *isrc;
}

void detruire_2int(void *data) {
  free(data);
}

void afficher_2int(const void *data) {
  Double_int *value = (Double_int *)data;
  int a = value->a;
  int b = value->b;

  printf("Valeur de a = %d. Valeur de b = %d\n",a,b);
}

int comparer_2int(const void *a, const void *b) {
  Double_int *d1 = (Double_int *)a;
  Double_int *d2 = (Double_int *)b;

  int va1 = d1->a;
  int va2 = d2->a;

  return (va1 > va2)-(va1 < va2); 
}

int ecrire_2int(const void *data, FILE *f) {
  const Double_int *idata = (const Double_int *)data;

  int a = idata->a;
  int b = idata->b;

  return fprintf(f, "%d %d",a,b);
}

void * lire_2int(FILE *f) {
  int a, b;
  int r = fscanf(f, "%d %d",&a,&b);

  if (r < 1) return NULL;

  Double_int *pdi = (Double_int *)malloc(sizeof(Double_int));
  Double_int newvalues;
  newvalues.a = a;
  newvalues.b = b;

  *pdi = newvalues;
  return pdi;
}
