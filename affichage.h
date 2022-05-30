/*
 ---------------------------------------------------------------------------------------------------------------------
 Nom du fichier : affichage.h
 Auteur(s)      :
 Date creation  :
 Description    :
 Remarque(s)    :
 Compilateur    : Mingw-w64 gcc 8.1.0
 ---------------------------------------------------------------------------------------------------------------------
*/

#ifndef PRG2_L2_AFFICHAGE_H
#define PRG2_L2_AFFICHAGE_H

#include "vehicule.h"

void afficherParking(Vehicule* parking, size_t tailleParking);

void afficherVehicule(const Vehicule* vehicule);

void afficherTaxe(const Vehicule* vehicule);

void afficherStatType(const Vehicule* parking, size_t tailleParking, Critere type);

#endif //PRG2_L2_AFFICHAGE_H
