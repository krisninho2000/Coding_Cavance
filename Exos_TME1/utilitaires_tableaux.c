#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void echanger_elem_tab(int tab[], int i, int j)
	{
	int t = tab[i];
	tab[i] = tab[j];
	tab[j] = t;
	}

int tab_trie(int tab[], int n)
	{
	int i;
	for (i = 1; i < n; i++)
		if( tab[i] < tab[i-1])
			return 0;
	return 1;
	}

int *nouveau_tableau(int n) {
	int *tab = malloc(n * sizeof(int));
	return tab;
}

int *detruire_tableau(int *t) {
	free(t);
	return NULL;
}

#define LIGNE_MAX 9999

//Fonction supplémentaire non référenciée dans le fichier en format .h

int compter_lignes(char *nomFichier){
	FILE *pFi;
	int nbL=0;
	char c;
	
	pFi=fopen(nomFichier, "r");
	if(pFi==NULL){
		fprintf(stderr, "compter_lignes:: Ne peut ouvrir %s\nEXITING\n", nomFichier);
		exit(1);
	}

	while((c=fgetc(pFi))!=EOF)
		if(c=='\n')
			nbL++;

	fclose(pFi);
	return nbL;
}

int *lire_tableau(char *nomFichier, int *p_nbVal) {

	FILE *pFi;
	*p_nbVal = compter_lignes(nomFichier);
	
	int *tab = nouveau_tableau(*p_nbVal);
	int i;
	
	pFi=fopen(nomFichier, "r");

	if (pFi==NULL) {
		fprintf(stderr, "compter_lignes:: Ne peut ouvrir %s\nEXITING\n", nomFichier);
		exit(1);
	}
	
	for (i = 0; i < *p_nbVal; i++) {
		fscanf(pFi,"%d",&tab[i]);
	}
	
	fclose(pFi);

	return tab;
}


void ecrire_tableau(char *nomFichier, int *tab, int n) {
	
	int i;

	FILE *pFi = fopen(nomFichier, "w");

	for (i = 0; i < n; i++) {
		fprintf(pFi, "%d\n", tab[i]);
	}

	fclose(pFi);
}

void afficher_tab(int tab[], int n) {
	int i = 0;
	int r = 0;
	for (i = 0; i < n; i++) {
		printf("%d\t",tab[i]);
		r++;
		if (r == 10) {
			printf("\n");
			r = 0;
		}
	}
	printf("\n\n");
}