/*
 ---------------------------------------------------------------------------------------------------------------------
 Nom du fichier : calculs.c
 Auteur(s)      :
 Date creation  :
 Description    :
 Remarque(s)    :
 Compilateur    : Mingw-w64 gcc 8.1.0
 ---------------------------------------------------------------------------------------------------------------------
*/

#include "calculs.h"
#include <math.h>

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
    if (*(double*) x > *(double*) y) {
        return 1;
    } else if (*(double*) x == *(double*) y) {
        return 0;
    } else {
        return -1;
    }
}

// si n est impair, la mediane est la (N + 1) / 2 ème valeur
// si n est pair, la mediane est la moyenne des (N/2) ème et (N+1/2) ème valeurs
double mediane(const double tab[], size_t n) {
    double mediane = 0;
    qsort(tab, n, sizeof(double),compareDouble);
    if(n % 2) {
        mediane = tab[n / 2];
    } else {
        mediane = (tab[(n - 1) / 2] + tab[n / 2]) / 2;
    }
    return mediane;
}

double ecartType(const double tab[], size_t n) {
    double sommeCarres = 0, ecartType = 0;
    for(size_t i = 0; i < n; ++i) {
        sommeCarres += pow(tab[i] - moyenne(tab, n), 2);
    }
    ecartType = sqrt(sommeCarres / (double) (n - 1));
    return ecartType;
}

