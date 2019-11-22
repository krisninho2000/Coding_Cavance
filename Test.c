#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int main() {
    typedef struct pointeur {
        int *p1;
        float *p2;
        char *pikachu;
    } Pointeur;

    Pointeur *poin1;
    poin1 = (Pointeur *)malloc(sizeof(Pointeur));
    
    typedef struct solide {
        int pi;
        float pika;
        char smeargle;
    } Solide;

    Solide s1;

    char *word1;
    word1 = (char *)malloc(100 * sizeof(char));
    strcpy(word1, "pikachuuuuuuuuuuu");

    int *i1;
    i1 = (int *)malloc(sizeof(int));
    *i1 = 3;

    char *word2;
    word2 = (char *)malloc(100 * sizeof(char));
    strcpy(word2, "nerf joker");
    
    poin1->p1 = i1;

    s1.pi = *i1;

    printf("%d et %d\n",*poin1->p1,s1.pi);

    typedef struct _article { 
    unsigned int ref;
    char *nom;
    unsigned int quantite;
    float pu; /* prix unitaire */
    } Article;

    Article a1;
    unsigned int i = 8798146;
    printf("%u \n", i);
}