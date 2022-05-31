/*
 ---------------------------------------------------------------------------------------------------------------------
 Nom du fichier : taxes.h
 Auteur(s)      : Céline Roger, Grégoire Guyot et Pablo Urizar
 Date creation  : 31.05.2022
 Description    : Fichier d'en-tête contenant toutes les fonctions permettant le calcul des taxes annuelles dues par
                  les véhicules pour stationner dans le parking
 Remarque(s)    : -
 Compilateur    : Mingw-w64 gcc 8.1.0
 ---------------------------------------------------------------------------------------------------------------------
*/

#ifndef PRG2_L2_TAXES_H
#define PRG2_L2_TAXES_H

#include <inttypes.h>
#include "vehicule.h"

typedef double CHF;

// Taxes de base
static const CHF TAXE_BASE_CAMIONNETTE = 700;
static const CHF TAXE_BASE_VOITURE = 400;

// Taxes spécifiques
static const CHF COEFF_TAXE_VOL_TRANSP_CAM = 10;
static const CHF TAXE_CRITERES1_STAND = 50; // TODO nom plus cohérent à trouver
static const CHF COEFF_TAXE_CYLINDREE_STAND = .05;
static const CHF TAXE_PUISSANCE_HDG = 200;
static const CHF TAXE_POIDS_BASE_HDG = 300;
static const CHF COEFF_TAXE_POIDS_HDG = 20;

// Seuils de taxation
static const uint16_t SEUIL_CYLINDREE = 1400; // [cm3]
static const uint16_t SEUIL_REJET_CO2 = 130; // [g/km]
static const uint16_t SEUIL_PUISSANCE = 250; // [CV]

// Fonctions de calcul de taxes
CHF taxeAnnuelle(const Vehicule* vehicule);
double* calculTaxe(const Vehicule* tabTrie, size_t taille);

#endif //PRG2_L2_TAXES_H
