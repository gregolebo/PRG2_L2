/*
 -----------------------------------------------------------------------------------
 Nom du fichier : affichage.h
 Auteur(s)      : Céline Roger, Grégoire Guyot et Pablo Urizar
 Date creation  : 31.05.2022
 Description    : Fichier d'en-tête contenant les définitions des fonctions permettant l'affichage des différents
                  modules
 Remarque(s)    : -
 Compilateur    : Mingw-w64 gcc 8.1.0
 -----------------------------------------------------------------------------------
*/

#ifndef PRG2_L2_AFFICHAGE_H
#define PRG2_L2_AFFICHAGE_H

#include "vehicule.h"

void afficherParking(Vehicule *parking, size_t tailleParking);

void afficherVehicule(const Vehicule *vehicule);

void afficherTaxe(const Vehicule *vehicule);

void afficherStatType(const Vehicule *parking, size_t tailleParking, Critere type);

#endif //PRG2_L2_AFFICHAGE_H
