/*
 ---------------------------------------------------------------------------------------------------------------------
 Nom du fichier : taxes.h
 Auteur(s)      :
 Date creation  :
 Description    :
 Remarque(s)    :
 Compilateur    : Mingw-w64 gcc 8.1.0
 ---------------------------------------------------------------------------------------------------------------------
*/

#ifndef PRG2_L2_TAXES_H
#define PRG2_L2_TAXES_H
#include <inttypes.h>
#include "voitures.h"

/*
// Taxes de base
#define TAXE_BASE_CAMIONNETTE 700
#define TAXE_BASE_VOITURE 400

// Taxes specifiques
#define COEFF_TAXE_VOL_TRANSP_CAM 10
#define TAXE_CRITERES1_STAND 50
#define COEFF_TAXE_CYLINDREE_STAND 0.05
#define TAXE_PUISSANCE_HDG 200
#define TAXE_POIDS_BASE_HDG 300
#define COEFF_TAXE_POIDS_HDG 20

// Seuils de taxation
#define SEUIL_CYLINDREE 1400 // [cm3]
#define SEUIL_REJET_CO2 130 // [g/km]
#define SEUIL_PUISSANCE 250 // [CV]
*/

typedef double CHF;

// Fonctions de calcul de taxes
CHF taxeAnnuelle(const Vehicule* vehicule);

// définir les taxes avec des constantes et non define
typedef double CHF;

// Taxe de base
static const CHF TAXE_BASE_CAMIONNETTE = 700;
static const CHF TAXE_BASE_VOITURE = 400;

// Taxe specifique
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

#endif //PRG2_L2_TAXES_H
