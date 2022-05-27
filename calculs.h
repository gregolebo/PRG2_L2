/*
 ---------------------------------------------------------------------------------------------------------------------
 Nom du fichier : calculs.h
 Auteur(s)      :
 Date creation  :
 Description    :
 Remarque(s)    :
 Compilateur    : Mingw-w64 gcc 8.1.0
 ---------------------------------------------------------------------------------------------------------------------
*/
#ifndef PRG2_L2_CALCULS_H
#define PRG2_L2_CALCULS_H

#include <stdio.h>
#include <stdlib.h>

// Faire fonctions somme, moyenne, médiane et écart-type
double somme(const double tab[], size_t n);
double moyenne(const double tab[], size_t n);
double mediane(const double tab[], size_t n);
double ecartType(const double tab[], size_t n);
int compareDouble(const void* x, const void* y);
#endif //PRG2_L2_CALCULS_H

double somme(const double tab[], size_t n) {
    double somme = 0;
    for(size_t i = 0; i < n; ++i) {
        somme += tab[i];
    }
    return somme;
}

double moyenne(const double tab[], size_t n) {
    return somme(tab, n) / (double)n;
}

int compareDouble(const void* x, const void* y) {
    if (*(double*) x > *(double*) y) return 1;
    if (*(double*) x == *(double*) y) return 0;
    if (*(double*) x < *(double*) y) return -1;
}

// si n est impair, la mediane est la (N + 1) / 2 ème valeur
// si n est pair, la mediane est la moyenne des (N/2) ème et (N+1/2) ème valeurs
double mediane(const double tab[], size_t n) {
    double mediane = 0;
    qsort(tab, n, sizeof(double),compareDouble);

    if(n % 2)
        mediane = tab[n + 1 / 2];


}
