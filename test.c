#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

// Fonctions liées au cours 3

int main() {
    char nom[ ] = "david" ;
    char nomtest[] = "xxxxx";
    char nom2[ 7 ]= "goliath" ;

    char nom3 [ ] = "david\0goliath" ;
    printf( "nom2=%s\n" ,nom2 ) ; 
    printf( "nom3=%s\n" ,nom3 ) ;

    if (strlen(nom) == strlen(nom2)) printf("yes\n");
    else printf("no\n");

    char word[] = "";

    strcpy (word, nom3);
    printf("%s\n",word);
}

