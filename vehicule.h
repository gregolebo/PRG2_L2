/*
-----------------------------------------------------------------------------------
 Nom du fichier : vehicule.h
 Auteur(s)      : Grégoire Guyot, Céline Roger, Pablo Urizar
 Date creation  : 26.05.2022
 Description    : Fichier d'en-tête contenant la structure des différents véhicules
                  permettant la gestion d'un parking
 Remarque(s)    : -
 Compilateur    : Mingw-w64 gcc 8.1.0
 -----------------------------------------------------------------------------------
*/

#ifndef PRG2_L2_VEHICULE_H
#define PRG2_L2_VEHICULE_H

#include <stdlib.h>
#include <inttypes.h>

typedef const char* Marque;
typedef const char* Plaque;

typedef enum {CAMIONETTE, VOITURE} TypeVehicule;
typedef enum {STANDARD, HAUT_GAMME} TypeVoiture;
typedef enum {EST_CAMIONETTE, EST_STANDARD, EST_HAUT_GAMME} Critere;

static const char* const TYPE_VEHICULE_STR[] = {"Camionnette", "Voiture"};
static const char* const TYPE_VOITURE_STR[] = {"Standard", "Haut-de-gamme"};
static const char* const CRITERE_STR[] = {"Camionette", "Standard", "Haut-de-gamme"};

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

Critere quelType(const Vehicule* v);

// Renvoie un tableau remplit uniquement d'un vehicule du type choisit
Vehicule* triTypeVehicule(const Vehicule* parking, size_t tailleParking, Critere type);

#endif //PRG2_L2_VEHICULE_H
