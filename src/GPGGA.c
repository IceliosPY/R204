#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "GPGGA.h"


/*Je vérifie si la trame commence bien par $GPGGA*/
int est_GPGGA(char *trame){
    
    
    char* table;
    char* dif;
    char* zero;
    int n = strchr(trame,',')-trame;
    long unsigned int i;
    double boolean1;
    double boolean2;

    table = (char *)calloc(n,sizeof(char));
    strncat(table,trame,n);
    boolean1= strcmp("$GPGGA",table);
        
        
    trame = &(*(trame+n+1));
    
    free(table);
    
    n = 6;
    
    
    table = (char *)calloc(n,sizeof(char));
    
    strncat(table,trame,n);
    dif = (char *)calloc(n,sizeof(char));
    sprintf(dif,"%ld",strtol(table,NULL,10));
    
    zero = (char *)calloc(strlen(table)-strlen(dif),sizeof(char));
    for (i= 0; i<strlen(table)-strlen(dif);i++){
        strcat(zero,"0");
    }

    strcat(zero,dif);

    boolean2 = strcmp(zero,table);
    printf("%s\n",zero);
    printf("%s\n",table);

    free(zero);
    free(table);
    free(dif);
    return boolean1 ==0 && boolean2 == 0;
    
    
}

/*Je récupère le temps dans la trame*/

void time_GPGGA(char *trame){
    
    char* table;
    int n = strchr(trame,',')-trame;
    table = (char *)calloc(n,sizeof(char));
    trame = &(*(strchr(trame,',')+1));
    free(table);

    /*Le temps est écrit comme suit : HHMMSS
    Donc après avoir récupérer les heures, je saute de 2 bits pour obtenir les minutes
    et je saute jusqu'à atteindre la prochaine virgule pour obtenir les secondes.*/
    n = 2;
    table = (char *)calloc(n,sizeof(char));
    strncat(table,trame,n);
    printf("The time of the trame is : %sh",table);
    trame = &(*(trame+n));
    free(table);


    n = 2;
    table = (char *)calloc(n,sizeof(char));
    strncat(table,trame,n);
    printf("%sm",table);
    trame = &(*(trame+n));
    free(table);


    n = strchr(trame,',')-trame;
    table = (char *)calloc(n,sizeof(char));
    strncat(table,trame,n);
    printf("%ss\n",table);
    free(table);
    

    
}

/*Je récupère les coordonnées dans la trame*/
void coord_GPGGA(char *trame){
    char* table;
    /*Cette variable (resultat) permettra de calculer les secondes*/
    double resultat;
    int n = 2;
    table = (char *)calloc(n,sizeof(char));
    trame = &(*(strchr(trame,',')+1));
    trame = &(*(strchr(trame,',')+1));
    strncat(table,trame,n);
    printf("The latitude is : %s°",table);
    trame = &(*(trame+n));
    free(table);

    n = 2;
    table = (char *)calloc(n,sizeof(char));
    strncat(table,trame,n);
    printf("%s'",table);
    trame = &(*(trame+n+1));
    
    free(table);
    n = strchr(trame,',')-trame;
    table = (char *)calloc(n,sizeof(char));
    strncat(table,trame,n);

    resultat = ((double)strtol(table,NULL,10)*60)/(pow(10,n));
    printf("%.2f ", resultat);
    
    
    



    
    trame = &(*(strchr(trame,',')+1));
    free(table);

    n = strchr(trame,',')-trame;
    table = (char *)calloc(n,sizeof(char));
    strncat(table,trame,n);
    printf("%s \n", table);
    trame = &(*(strchr(trame,',')+1));
    free(table);
    
    n = 3;
    table = (char *)calloc(n,sizeof(char));
    strncat(table,trame,n);
    printf("The longitude is : %s°",table);
    trame = &(*(trame+n));
    free(table);

    n = 2;
    table = (char *)calloc(n,sizeof(char));
    strncat(table,trame,n);
    printf("%s'",table);
    trame = &(*(trame+n+1));
    free(table);
    

    n = strchr(trame,',')-trame;
    table = (char *)calloc(n,sizeof(char));
    strncat(table,trame,n);
    
    resultat = ((double)strtol(table,NULL,10)*60)/(pow(10,n));
    printf("%.2f ", resultat);
    trame = &(*(strchr(trame,',')+1));
    free(table);

    n = strchr(trame,',')-trame;
    table = (char *)calloc(n,sizeof(char));
    strncat(table,trame,n);
    printf("%s \n", table);
}
