#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "devel.h"
#include "liste.h"
#include "fonctions_2entiers.h"
#include "fonctions_string.h"

void compte(void *data, void *optarg) {

  /* Je ne sais pas si il est nécessaire de faire tout ca
  // Comptage du nombre de lignes dans le fichier

  FILE *pFi;
	int nbL=0;
	char c;
	
	pFi=fopen("french_za", "r");
	if(pFi==NULL){
		fprintf(stderr, "compter_lignes:: Ne peut ouvrir %s\nEXITING\n", "fichier_za");
		exit(1);
	}

	while((c=fgetc(pFi))!=EOF)
		if(c=='\n')
			nbL++;

	fclose(pFi);

  */

  // Récupération de la liste

  //printf("good1\n\n");

  PListe liste = optarg;

  //printf("good2\n\n");

  // Lecture du dictionnaire

  FILE *doc;
  doc = fopen(data, "r+");

  char *word = (char *)malloc(100 * sizeof(char));
  char *c = (char *)malloc(sizeof(char));
  int i = 0;

  while ((*c=fgetc(doc)) != EOF) {
    if (strcmp(c, "\n")) {
      strcat(word, c);
    }

    else {
      PElement p_elem = liste->elements;
      int len_word = strlen(word);

      //printf("good3\n\n");

      if (p_elem->data == NULL) {
        Double_int *d = (Double_int *)malloc(sizeof(Double_int));
        d->a = len_word;
        d->b = 1;

        PElement new_elem = malloc(sizeof(Element));
        new_elem->data = d;
        new_elem->suivant = NULL;

        //printf("good4\n\n");

        liste->elements = new_elem;

        //printf("good5\n\n");
      }

      else {
        Double_int *elemc = (Double_int *)malloc(sizeof(Double_int));
        elemc->a = len_word;

        //printf("good6\n\n");

        int cond = 0;
        while (p_elem) {
          //printf("good7\n\n");

          if ((comparer_2int(p_elem->data, elemc) == 0) && (cond == 0)) {
            //printf("good8\n\n");
            Double_int *increm = p_elem->data;
            increm->b = increm->b + 1;
            cond++;
          }

          //printf("good9\n\n");

          p_elem = p_elem->suivant;
        }

        //printf("good10\n\n");

        free(elemc);

        if ((p_elem == NULL) && (cond == 0)) {
          Double_int *d = (Double_int *)malloc(sizeof(Double_int));
          d->a = len_word;
          d->b = 1;

          PElement new_elem = malloc(sizeof(Element));
          new_elem->data = d;
          new_elem->suivant = liste->elements;

          //printf("good11\n\n");

          liste->elements = new_elem;

          //printf("good12\n\n");
        }
      }

      strcpy(word, "");
      i++;
      printf("%d\n",i);
    }
  }

  fclose(doc);
}

int main(void) {

  // Partie creation de liste vide

  PListe pointeur_liste = malloc(sizeof(PListe));
  PElement pointeur_elem = malloc(sizeof(Element));
  pointeur_elem->data = NULL;
  pointeur_elem->suivant = NULL;

  pointeur_liste->elements = pointeur_elem;

  compte("french_za", pointeur_liste);

  PElement elemv = pointeur_liste->elements;
  while (elemv) {
    Double_int *dint = elemv->data;
    printf("Longueur du mot = %d\nNombre de mots = %d\n\n",dint->a,dint->b);
    elemv = elemv->suivant;
  }
  
  return 0;
}
