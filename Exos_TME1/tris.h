#ifndef __TRIS__
#define __TRIS__ 

/*****************************************************************************/
/* Ensemble de fonctions facilitant le tri de tableaux d entiers.   */
/*****************************************************************************/

/*****************************************************************************/
/* Echange le contenu entre les cases i et j du tableau "tab".  */
/*****************************************************************************/
void echangerCases(int *tab, int i, int j);

/*****************************************************************************/
/* Effectue un tri du tableau "tab" par la méthode du minimum.  */
/*****************************************************************************/
void tri_minimum(int *tab, int l);

/*****************************************************************************/
/* Effectue un tri du tableau "tab" par la méthode du tri à bulle.  */
/*****************************************************************************/
void tri_a_bulle(int *tab, int l);

/*****************************************************************************/
/* Effectue un tri récursif du tableau "tab" selon la méthode du quicksort.  */
/* L'élémemt "first" est toujours égal à 0.  */
/* L'élémemt "last" est toujours égal à la longueur du tableau "tab" -1.  */
/*****************************************************************************/
void quicksort(int *tab, int first, int last);

#endif