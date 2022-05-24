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

// définir les taxes avec des constantes et non define
typedef double CHF;

// Taxe de base
const CHF TAXE_BASE_CAMIONNETTE = 700;
const CHF TAXE_BASE_VOITURE = 400;

// Taxe specifique
const CHF COEFF_TAXE_VOL_TRANSP_CAM = 10;
const CHF TAXE_CRITERES1_STAND = 50; // TODO nom plus cohérent à trouver
const CHF COEFF_TAXE_CYLINDREE_STAND = .05;
const CHF TAXE_PUISSANCE_HDG = 200;
const CHF TAXE_POIDS_BASE_HDG = 300;
const CHF COEFF_TAXE_POIDS_HDG = 20;

#endif //PRG2_L2_TAXES_H
