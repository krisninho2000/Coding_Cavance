#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ecosys.h"

#define NB_PROIES 20
#define NB_PREDATEURS 20
#define T_WAIT 40000


// Parametres globaux de l'ecosysteme (externes dans le ecosys.h)

float p_ch_dir=0.01;
float d_proie=1;
float d_predateur=1;
float p_manger=0.2;
float p_reproduce=0.01;
float energie=50.0;


int main(void) {

  srand(time(NULL));
	
  Animal *liste_proie = NULL;
  Animal *liste_predateur = NULL;
  int nb_proies = NB_PROIES, nb_predateurs = NB_PREDATEURS;
  
  int n = 0;
  int g = 10;

  for (n = 0; n < nb_proies; n++) {
    ajouter_animal(rand()%10, rand()%10, &liste_proie);
  }

  for (n = 0; n < nb_predateurs; n++) {
    ajouter_animal(rand()%SIZE_X ,rand()%SIZE_Y, &liste_predateur);
  }


	/* Ecrire     usleep(T_WAIT); pour ralentir l'affichage*/

  for (n = 0; n < g; n++){
    afficher_ecosys(liste_proie, liste_predateur);
    rafraichir_proies(&liste_proie);
    reproduce(&liste_proie);
  }

  return 0;
}

