#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fonctionTraitement.h"
#include "menu.h"

void menu_message() {
    char message[100];
    int autorisation = 0;
    int Dechiffrement = 0;
    int cle;
    char cle2[100];
    int choix = 0;
    int ChoixTraitement;
    int ChoixClef;
    int ChoixTypeMessage;

    // Menu pour le type de message
    printf("Quel est le type de votre message ? : \n");
    printf("(1) - Lettres \n");
    printf("(2) - Lettres AVEC alphanumérique (en cours de développement) \n");
    printf("(3) - Chiffres (en cours de développement) \n");
    printf("(4) - Quitter \n");
    printf("Quel est votre choix ? : ");
    scanf("%d", &ChoixTypeMessage);

    if (ChoixTypeMessage == 4) {
        return;
    }

    if (ChoixTypeMessage == 1) {
        getchar();  // Consommer le caractère '\n' laissé par scanf

        while (autorisation != 1) {
            printf("Veuillez entrer le message à chiffrer/déchiffrer : ");
            fgets(message, sizeof(message), stdin);
            autorisation = verificationChiffreETlettre(message, autorisation);
            if (autorisation == 1) {
                autorisation = verificationChiffreUniquement(message, autorisation);
            }
        }

        printf("Votre message : %s\n", message);
        printf("Choisissez le format de votre clef\n");
        printf("(1) : Clef avec chiffres\n");
        printf("(2) : Clef avec lettres\n");
        printf("(3) : Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &ChoixClef);

        switch (ChoixClef) {
            case 1:
                printf("Saisie de la clef\n");
                printf("Type de clef : Chiffre\n");
                printf("Votre message : %s\n", message);
                printf("Veuillez entrer la clef de chiffrement : ");
                scanf("%d", &cle);
                break;

            case 2:
                printf("Saisie de la clef\n");
                printf("Type de clef : Lettres\n");
                printf("Votre message : %s\n", message);
                autorisation = 0;
                while (autorisation != 1) {
                    getchar();
                    printf("Veuillez entrer la clef de chiffrement : ");
                    scanf("%s", cle2);
                    autorisation = verificationCleLettre(cle2, autorisation);
                }
                break;

            case 3:
                return;

            default:
                printf("Choix invalide. Retour au menu principal.\n");
                return;
        }

        // Choix du type de chiffrement/déchiffrer
        printf("Que voulez-vous faire ?\n");
        if (ChoixClef == 1) {
            printf("Type de clef : Chiffre\n");
            printf("Votre message : %s\n", message);
            printf("- Méthodes disponibles -\n");
            printf("(1) César\n");
            printf("(2) Option indisponible\n");
            printf("(3) Quitter\n");
            printf("Votre choix : ");
            scanf("%d", &choix);
            if (choix == 2) {
                printf("Option indisponible\n");
                choix = 3;
            }
        } else if (ChoixClef == 2) {
            printf("Type de clef : Lettres\n");
            printf("Votre message : %s\n", message);
            printf("- Méthodes disponibles -\n");
            printf("(1) Option indisponible\n");
            printf("(2) Vigenère\n");
            printf("(3) Quitter\n");
            printf("Votre choix : ");
            scanf("%d", &choix);
            if (choix == 1) {
                printf("Option indisponible\n");
                choix = 3;
            }
        }

        switch (choix) {
            case 1:
                printf("Type de clef : Chiffre\n");
                printf("Votre message : %s\n", message);
                printf("Votre Clef : %d\n", cle);
                printf("Voulez-vous chiffrer ou déchiffrer ?\n");
                printf("(1) : Chiffrer\n");
                printf("(2) : Déchiffrer\n");
                printf("(3) : Quitter\n");
                printf("Votre choix : ");
                scanf("%d", &ChoixTraitement);
                if (ChoixTraitement == 1) {
                    chiffrement_cesar(message, cle, Dechiffrement);
                } else if (ChoixTraitement == 2) {
                    dechiffrement_cesar(message, cle, Dechiffrement);
                }
                break;

            case 2:
                printf("Type de clef : Lettres\n");
                printf("Votre message : %s\n", message);
                printf("Votre Clef : %s\n", cle2);
                printf("Voulez-vous chiffrer ou déchiffrer ?\n");
                printf("(1) : Chiffrer\n");
                printf("(2) : Déchiffrer\n");
                printf("(3) : Quitter\n");
                printf("Votre choix : ");
                scanf("%d", &ChoixTraitement);
                if (ChoixTraitement == 1) {
                    chiffrement_vigenere(message, cle2);
                } else if (ChoixTraitement == 2) {
                    dechiffrement_vigenere(message, cle2);
                }
                break;

            case 3:
                break;
        }
    }
}
