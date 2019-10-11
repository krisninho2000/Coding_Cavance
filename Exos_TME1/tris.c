#include <stdio.h>
#include <stdlib.h>

#include "utilitaires_tableaux.h"

void echangerCases(int *tab, int i, int j) {
    int temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}

void tri_minimum(int *tab, int l) {
    int i = 0;
    //L'élément k permet de se situer dans le tableau après chaque tri effectué
    int k = 0;
    while (i < l) {
        for (i = k; i < l; i++) {
            if (tab[k] > tab[i]) echangerCases(tab, k, i);
        }
        k++;
        i = k;
    }
}

void tri_a_bulle(int *tab, int l) {
    int i = 0;
    int k = 1;
    //L'élément k permet de connaitre le nombre de cases déja arrangées à la fin
    while (k < l) {
        for (i = 0; i < (l - k); i++) {
            if (tab[i] > tab[i+1]) echangerCases(tab, i, i+1);
        }
        k++;
    }
}

void quicksort(int *tab, int first, int last) {
    if (first < last) {

        int pivot = first;
        int i = first;
        int j = last;

        while (i < j) {
            while ((tab[i] <= tab[pivot]) && (i < j)) i++;
            while (tab[j] > tab[pivot]) j--;

            if (i < j) {
                echangerCases(tab, i, j);
            }
        }

        echangerCases(tab, pivot, j);

        quicksort(tab,first,j-1);
        quicksort(tab,j+1,last);
    }
}