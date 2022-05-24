/*
 ---------------------------------------------------------------------------------------------------------------------
 Nom du fichier : voitures.h
 Auteur(s)      :
 Date creation  :
 Description    :
 Remarque(s)    :
 Compilateur    : Mingw-w64 gcc 8.1.0
 ---------------------------------------------------------------------------------------------------------------------
*/
#ifndef PRG2_L2_VOITURES_H
#define PRG2_L2_VOITURES_H

#include <inttypes.h>

typedef const char* Marque;
typedef const char* Plaque;

typedef enum {CAMIONETTE, VOITURE} TypeVehicule;
typedef enum {STANDARD, HAUT_GAMME} TypeVoiture;

const char* const TYPE_VEHICULE_STR[] = {"camionnette", "voiture"};
const char* const TYPE_VOITURE_STR[] = {"standard", "haut-de-gamme"};



typedef struct {
    uint16_t cylindree; // [cm3]
    uint16_t rejetCo2; // [g/km]
} VoitureStandard;

typedef struct {
    uint16_t puissance; // [CV]
} VoitureHautGamme;

typedef union {
    VoitureStandard voitureStandard;
    VoitureHautGamme voitureHautGamme;
} SpecificitesVoiture;

typedef struct {
    uint16_t poids; // [kg]
    SpecificitesVoiture specVoiture;
} Voiture;

typedef struct {
    double volumeTransport; // [m3]
} Camionnette;

typedef union {
    Camionnette camionnette;
    Voiture voiture;
} CategorieVehicule;

typedef struct {
    Plaque plaque;
    Marque marque;
    CategorieVehicule categorieVehicule;
} Vehicule;



#endif //PRG2_L2_VOITURES_H
