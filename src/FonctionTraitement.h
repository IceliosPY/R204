#ifndef TRAITEMENT_H
#define TRAITEMENT_H

void chiffrement_cesar(char message[], int cle, int Dechiffrement);
void dechiffrement_cesar(char message[], int cle, int Dechiffrement);
void chiffrement_vigenere(char message[], char cle2[]);
void dechiffrement_vigenere(char message[], char cle2[]);
int verificationChiffreETlettre(char message[], int autorisation);
int verificationCleLettre(char cle2[], int autorisation);
int verificationChiffreUniquement(char message[], int autorisation);

#endif
