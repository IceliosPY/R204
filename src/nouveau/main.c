#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GPGGA.h"



int main(){
    
    char trames[100];
    int n;
    char* trame;
    
    printf("Trame : ");
    fgets(trames, sizeof(trames), stdin);


    if (strlen(trames)-1> 15){

    n = strlen(trames);
    trame = (char *)calloc(n,sizeof(char));
    
    strncat(trame,trames,n);
    if (est_GPGGA(trame)){
        
            time_GPGGA(trame);
            coord_GPGGA(trame);
        }
    else {
        
        printf("Ceci n'est pas une trame GPS de type GPGGA");
        }

    free(trame);
    }
    
    n = strlen("$GPGGA,180502.00,5041.7342,N,00311.786,E,1,07,1.19,122,M,,,,0000*0E");
    trame = (char *)calloc(n,sizeof(char));

    strncat(trame,"$GPGGA,180502.00,5041.7342,N,00311.786,E,1,07,1.19,122,M,,,,0000*0E", n);
    
    
    printf("\n");
    
    if (est_GPGGA(trame)){
        time_GPGGA(trame);
        coord_GPGGA(trame);
    }
    else {
        printf("Ceci n'est pas une trame GPS de type GPGGA");
        }
    free(trame);
    

    n = strlen("$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47");
    trame = (char *)calloc(n,sizeof(char));
    strncat(trame,"$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47", n);
    printf("\n");
    if (est_GPGGA(trame)){
        time_GPGGA(trame);
        coord_GPGGA(trame);
    } else {
        printf("Ceci n'est pas une trame GPS de type GPGGA");
        }
    free(trame);

    n = strlen("$GPGGA,010203.456,2541.1234,S,15323.9876,E,1,06,2.5,100.0,M,12.0,M,,*78");
    trame = (char *)calloc(n,sizeof(char));
    strncat(trame,"$GPGGA,010203.456,2541.1234,S,15323.9876,E,1,06,2.5,100.0,M,12.0,M,,*78", n);
    printf("\n");
    if (est_GPGGA(trame)){
        time_GPGGA(trame);
        coord_GPGGA(trame);
    }
    else {
        printf("Ceci n'est pas une trame GPS de type GPGGA");
        }
    free(trame);

    n = strlen("$GPGGA,064036.289,4836.5375,N,00740.9373,E,1,04,3.2,200.2,M,,,,0000*0E");
    trame = (char *)calloc(n,sizeof(char));
    strncat(trame,"$GPGGA,064036.289,4836.5375,N,00740.9373,E,1,04,3.2,200.2,M,,,,0000*0E", n);
    printf("\n");
    if (est_GPGGA(trame)){
        time_GPGGA(trame);
        coord_GPGGA(trame);
    }
    else {
        printf("Ceci n'est pas une trame GPS de type GPGGA");
        }
    free(trame);
    return 0;


    
}

