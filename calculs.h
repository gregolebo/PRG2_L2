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
#include "vehicule.h"


double somme(const double tab[], size_t n);

double moyenne(const double tab[], size_t n);

double mediane(const double tab[], size_t n);

double ecartType(const double tab[], size_t n);

int compareDouble(const void* x, const void* y);

size_t compteurType(const Vehicule* parking, size_t tailleParking, Critere type);

#endif //PRG2_L2_CALCULS_H


