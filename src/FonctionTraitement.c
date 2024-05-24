#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fonctionTraitement.h"

void chiffrement_cesar(char message[], int cle, int Dechiffrement) {
    int i;
    for(i = 0; message[i] != '\0'; ++i) {
        if(isalpha(message[i])) {
            if(islower(message[i])) {
                message[i] = (((message[i] - 'a') + cle) % 26) + 'a';
            } else {
                message[i] = (((message[i] - 'A') + cle) % 26) + 'A';
            }
        }
    }
    if (Dechiffrement != 1) {
        printf("Le message chiffré en utilisant la clef %d : %s\n", cle, message);
        int choix;
        printf("Choisissez le type de fichier :\n");
        printf("1. Fichier texte (.txt)\n");
        printf("2. Fichier CSV (.csv)\n");
        scanf("%d", &choix);

        FILE *fp;
        if (choix == 1) {
            fp = fopen("result.txt", "a+");
            if (fp == NULL) {
                perror("Erreur à l'ouverture du fichier result.txt");
                return;
            }
            fprintf(fp, "Le message chiffré en utilisant la clef %d : %s\n", cle, message);
            fclose(fp);
            printf("Résultat écrit dans le fichier result.txt\n");
        } else if (choix == 2) {
            fp = fopen("result.csv", "a+");
            if (fp == NULL) {
                perror("Erreur à l'ouverture du fichier result.csv");
                return;
            }
            fprintf(fp, "clef;message;traitement\n");
            fprintf(fp, "%d;%s;;chiffrement cesar\n", cle, message);
            fclose(fp);
            printf("Résultat écrit dans le fichier result.csv\n");
        } else {
            printf("Choix invalide. Aucun fichier n'a été écrit.\n");
        }
    }
}

void dechiffrement_cesar(char message[], int cle, int Dechiffrement) {
    Dechiffrement = 1;
    chiffrement_cesar(message, 26 - cle, Dechiffrement);
    printf("Le message déchiffré en utilisant la clef %d : %s\n", cle, message);
    int choix;
    printf("Choisissez le type de fichier :\n");
    printf("1. Fichier texte (.txt)\n");
    printf("2. Fichier CSV (.csv)\n");
    scanf("%d", &choix);

    FILE *fp;
    if (choix == 1) {
        fp = fopen("result.txt", "a+");
        if (fp == NULL) {
            perror("Erreur à l'ouverture du fichier result.txt");
            return;
        }
        fprintf(fp, "Le message déchiffré en utilisant la clef %d : %s\n", cle, message);
        fclose(fp);
        printf("Résultat écrit dans le fichier result.txt\n");
    } else if (choix == 2) {
        fp = fopen("result.csv", "a+");
        if (fp == NULL) {
            perror("Erreur à l'ouverture du fichier result.csv");
            return;
        }
        fprintf(fp, "clef;message;traitement\n");
        fprintf(fp, "%d;%s;;dechiffrement cesar\n", cle, message);
        fclose(fp);
        printf("Résultat écrit dans le fichier result.csv\n");
    } else {
        printf("Choix invalide. Aucun fichier n'a été écrit.\n");
    }
}

void chiffrement_vigenere(char message[], char cle2[]) {
    int i;
    size_t j;  // Changez le type de j en size_t pour correspondre au type de retour de strlen
    for(i = 0, j = 0; message[i] != '\0'; ++i, ++j) {
        if(j == strlen(cle2)) {
            j = 0;
        }
        if(isalpha(message[i])) {
            if(islower(message[i])) {
                message[i] = (((message[i] - 'a') + (cle2[j] - 'a')) % 26) + 'a';
            } else {
                message[i] = (((message[i] - 'A') + (cle2[j] - 'A')) % 26) + 'A';
            }
        }
    }
    printf("Le message chiffré en utilisant la clef %s : %s\n", cle2, message);
    int choix;
    printf("Choisissez le type de fichier :\n");
    printf("1. Fichier texte (.txt)\n");
    printf("2. Fichier CSV (.csv)\n");
    scanf("%d", &choix);

    FILE *fp;
    if (choix == 1) {
        fp = fopen("result.txt", "a+");
        if (fp == NULL) {
            perror("Erreur à l'ouverture du fichier result.txt");
            return;
        }
        fprintf(fp, "Le message chiffré en utilisant la clef %s : %s\n", cle2, message);
        fclose(fp);
        printf("Résultat écrit dans le fichier result.txt\n");
    } else if (choix == 2) {
        fp = fopen("result.csv", "a+");
        if (fp == NULL) {
            perror("Erreur à l'ouverture du fichier result.csv");
            return;
        }
        fprintf(fp, "clef;message;Traitement\n");
        fprintf(fp, "%s;%s;;chiffrement Vigenere\n", cle2, message);
        fclose(fp);
        printf("Résultat écrit dans le fichier result.csv\n");
    } else {
        printf("Choix invalide. Aucun fichier n'a été écrit.\n");
    }
}

void dechiffrement_vigenere(char message[], char cle2[]) {
    int i;
    size_t j;  // Changez le type de j en size_t pour correspondre au type de retour de strlen
    for(i = 0, j = 0; message[i] != '\0'; ++i, ++j) {
        if(j == strlen(cle2)) {
            j = 0;
        }
        if(isalpha(message[i])) {
            if(islower(message[i])) {
                message[i] = (((message[i] - 'a') - (cle2[j] - 'a') + 26) % 26) + 'a';
            } else {
                message[i] = (((message[i] - 'A') - (cle2[j] - 'A') + 26) % 26) + 'A';
            }
        }
    }
    printf("Le message déchiffré en utilisant la clef %s : %s\n", cle2, message);
    int choix;
    printf("Choisissez le type de fichier :\n");
    printf("1. Fichier texte (.txt)\n");
    printf("2. Fichier CSV (.csv)\n");
    scanf("%d", &choix);

    FILE *fp;
    if (choix == 1) {
        fp = fopen("result.txt", "a+");
        if (fp == NULL) {
            perror("Erreur à l'ouverture du fichier result.txt");
            return;
        }
        fprintf(fp, "Le message déchiffré en utilisant la clef %s : %s\n", cle2, message);
        fclose(fp);
        printf("Résultat écrit dans le fichier result.txt\n");
    } else if (choix == 2) {
        fp = fopen("result.csv", "a+");
        if (fp == NULL) {
            perror("Erreur à l'ouverture du fichier result.csv");
            return;
        }
        fprintf(fp, "clef;message;Traitement\n");
        fprintf(fp, "%s;%s;;dechiffrement Vigenere\n", cle2, message);
        fclose(fp);
        printf("Résultat écrit dans le fichier result.csv\n");
    } else {
        printf("Choix invalide. Aucun fichier n'a été écrit.\n");
    }
}

int verificationCleLettre(char cle2[], int autorisation) {
    int i, error = 0;

    for (i = 0; cle2[i] != '\0'; i++) {
        if (isdigit(cle2[i]) || !isalpha(cle2[i])) {
            error = 1;
            break;
        }
    }

    if (error) {
        printf("Erreur : la clé contient un/des chiffre(s).\n");
        autorisation = 0;
    } else {
        autorisation = 1;
    }

    return autorisation;
}

int verificationChiffreETlettre(char message[], int autorisation) {
    int i, error = 0;

    // Vérifier si le message contient que des lettres et des chiffres
    for (i = 0; message[i] != '\0'; i++) {
        if (!isalnum(message[i]) && message[i] != '\n') {
            error = 1;
            break;
        }
    }

    if (error) {
        printf("Erreur : le message contient un/des caractère(s) spécial(aux) ou un chiffre.\n");
        autorisation = 0;
    } else {
        autorisation = 1;
    }
    return autorisation;
}

int verificationChiffreUniquement(char message[], int autorisation) {
    int i, error = 0;

    // Vérifier le message ne contient AUCUN chiffre
    for (i = 0; message[i] != '\0'; i++) {
        if (isdigit(message[i])) {
            error = 1;
            break;
        }
    }

    if (error) {
        printf("Erreur : le message contient un/des chiffre(s).\n");
        autorisation = 0;
    } else {
        autorisation = 1;
    }
    return autorisation;
}
