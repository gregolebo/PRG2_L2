/*
 -----------------------------------------------------------------------------------
 Nom du fichier : calculs.h
 Auteur(s)      : Grégoire Guyot, Céline Roger, Pablo Urizar
 Date creation  : 26.05.2022
 Description    : Fichier d'en-tête contenant toutes les définitions des fonctions
                  de calculs nécessaires pour l'analyse des taxes de véhicules
 Remarque(s)    : - 
 Compilateur    : Mingw-w64 gcc 8.1.0
 -----------------------------------------------------------------------------------
*/

#ifndef PRG2_L2_CALCULS_H
#define PRG2_L2_CALCULS_H

#include <stdio.h>
#include <stdlib.h>
#include "vehicule.h"

double somme(const double tab[], size_t n);

double moyenne(const double tab[], size_t n);

double mediane(const double tab[], size_t taille);

double ecartType(const double tab[], size_t n);

int compareDouble(const void* x, const void* y);

size_t compteurType(const Vehicule* parking, size_t tailleParking, Critere type);

int compareTaxes(const void* x, const void* y);

#endif //PRG2_L2_CALCULS_H
