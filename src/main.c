#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fonctionTraitement.h"
#include "GPGGA.h"
#include "menu.h"

// Prototypes des fonctions
void menu_principal();
void fonctionnalite_cesar();
void fonctionnalite_GPGGA();

int main() {
    menu_principal();
    return 0;
}

void menu_principal() {
    int choix = 0;

    while (1) {
        printf("Menu principal\n");
        printf("(1) - Fonctionnalité César\n");
        printf("(2) - Fonctionnalité GPGGA\n");
        printf("(3) - Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        // Consommer le caractère de nouvelle ligne laissé par scanf
        while (getchar() != '\n');

        switch (choix) {
            case 1:
                fonctionnalite_cesar();
                break;
            case 2:
                fonctionnalite_GPGGA();
                break;
            case 3:
                printf("Quitter le programme.\n");
                return;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    }
}

void fonctionnalite_cesar() {
    int revenir = 1;
    int Nb_retour = 0;

    while (revenir == 1) {
        menu_message();
        printf("Voulez-vous revenir ? (1/0)\n");
        printf("Votre choix : ");
        scanf("%d", &revenir);
        // Consommer le caractère de nouvelle ligne laissé par scanf
        while (getchar() != '\n');
        Nb_retour++;
    }
}

void fonctionnalite_GPGGA() {
    char trames[100];
    int n;
    char* trame;

    printf("Trame : ");
    fgets(trames, sizeof(trames), stdin);
    // Retirer le caractère '\n' de fgets
    trames[strcspn(trames, "\n")] = 0;

    if (strlen(trames) > 15) {
        n = strlen(trames);
        trame = (char *)calloc(n + 1, sizeof(char));  // +1 pour le caractère nul

        strncat(trame, trames, n);
        if (est_GPGGA(trame)) {
            time_GPGGA(trame);
            coord_GPGGA(trame);
        } else {
            printf("Ceci n'est pas une trame GPS de type GPGGA\n");
        }

        free(trame);
    }

    n = strlen("$GPGGA,180502.00,5041.7342,N,00311.786,E,1,07,1.19,122,M,,,,0000*0E");
    trame = (char *)calloc(n + 1, sizeof(char));
    strncpy(trame, "$GPGGA,180502.00,5041.7342,N,00311.786,E,1,07,1.19,122,M,,,,0000*0E", n);
    printf("\n");
    if (est_GPGGA(trame)) {
        time_GPGGA(trame);
        coord_GPGGA(trame);
    } else {
        printf("Ceci n'est pas une trame GPS de type GPGGA\n");
    }
    free(trame);

    n = strlen("$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47");
    trame = (char *)calloc(n + 1, sizeof(char));
    strncpy(trame, "$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47", n);
    printf("\n");
    if (est_GPGGA(trame)) {
        time_GPGGA(trame);
        coord_GPGGA(trame);
    } else {
        printf("Ceci n'est pas une trame GPS de type GPGGA\n");
    }
    free(trame);

    n = strlen("$GPGGA,010203.456,2541.1234,S,15323.9876,E,1,06,2.5,100.0,M,12.0,M,,*78");
    trame = (char *)calloc(n + 1, sizeof(char));
    strncpy(trame, "$GPGGA,010203.456,2541.1234,S,15323.9876,E,1,06,2.5,100.0,M,12.0,M,,*78", n);
    printf("\n");
    if (est_GPGGA(trame)) {
        time_GPGGA(trame);
        coord_GPGGA(trame);
    } else {
        printf("Ceci n'est pas une trame GPS de type GPGGA\n");
    }
    free(trame);

    n = strlen("$GPGGA,064036.289,4836.5375,N,00740.9373,E,1,04,3.2,200.2,M,,,,0000*0E");
    trame = (char *)calloc(n + 1, sizeof(char));
    strncpy(trame, "$GPGGA,064036.289,4836.5375,N,00740.9373,E,1,04,3.2,200.2,M,,,,0000*0E", n);
    printf("\n");
    if (est_GPGGA(trame)) {
        time_GPGGA(trame);
        coord_GPGGA(trame);
    } else {
        printf("Ceci n'est pas une trame GPS de type GPGGA\n");
    }
    free(trame);
}