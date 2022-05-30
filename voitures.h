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

static const char* const TYPE_VEHICULE_STR[] = {"camionnette", "voiture"};
static const char* const TYPE_VOITURE_STR[]  = {"standard", "haut-de-gamme"};

typedef struct {
    uint16_t cylindree; // [cm3]
    uint16_t rejetCo2; // [g/km]
} SpecVoitureStandard;

typedef struct {
    uint16_t puissance; // [CV]
} SpecVoitureHautGamme;

typedef union {
    SpecVoitureStandard voitureStandard;
    SpecVoitureHautGamme voitureHautGamme;
} SpecificitesVoiture;

typedef struct {
    uint16_t poids; // [kg]
    TypeVoiture typeVoiture;
    SpecificitesVoiture specVoiture;
} SpecVoiture;

typedef struct {
    double volumeTransport; // [m3]
} SpecCamionnette;

typedef union {
    SpecCamionnette camionnette;
    SpecVoiture voiture;
} CategorieVehicule;

typedef struct {
    Plaque plaque;
    Marque marque;
    TypeVehicule typeVehicule;
    CategorieVehicule categorieVehicule;
} Vehicule;

// Constructeurs différents véhicules
Vehicule camionnette(Plaque plaque, Marque marque, double volTransport);
Vehicule voitureStandard(Plaque plaque, Marque marque, uint16_t poids, uint16_t cylindree, uint16_t rejetCo2);
Vehicule voitureHautGamme(Plaque plaque, Marque marque, uint16_t poids, uint16_t puissance);

#endif //PRG2_L2_VOITURES_H
