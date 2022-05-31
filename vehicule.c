/*
 ---------------------------------------------------------------------------------------------------------------------
 Nom du fichier : vehicule.c
 Auteur(s)      : Céline Roger, Grégoire Guyot et Pablo Urizar
 Date creation  : 31.05.2022
 Description    : Implémentation de la librairie contenant les constructeurs des différents véhicules ainsi que les
                  définitions des fonctions liées à leur usage
 Remarque(s)    : -
 Compilateur    : Mingw-w64 gcc 8.1.0
 ---------------------------------------------------------------------------------------------------------------------
*/

#include <assert.h>
#include "vehicule.h"
#include "calculs.h"


Vehicule camionnette(Plaque plaque, Marque marque, double volTransport) {
    assert(volTransport > 0);
    return (Vehicule) {
        .plaque = plaque,
        .marque = marque,
        .typeVehicule = CAMIONETTE,
        .categorieVehicule = { .camionnette = {.volumeTransport = volTransport}}};
}

Vehicule voitureStandard(Plaque plaque, Marque marque, uint16_t poids, uint16_t cylindree, uint16_t rejetCo2) {
    assert(poids && cylindree); // TODO besoin de vérifier rejetCo2 ? pt possible d'avoir un rejetCo2 nul ?
    return (Vehicule) {
            .plaque = plaque,
            .marque = marque,
            .typeVehicule = VOITURE,
            .categorieVehicule = { .voiture = { .poids = poids,
                    .typeVoiture = STANDARD,
                    .specVoiture = { .voitureStandard = { .cylindree = cylindree, .rejetCo2 = rejetCo2 }}}}};

}

Vehicule voitureHautGamme(Plaque plaque, Marque marque, uint16_t poids, uint16_t puissance) {
    assert(poids && puissance); // TODO même question pour rejetCo2
    return (Vehicule) {
        .plaque = plaque,
        .marque = marque,
        .typeVehicule = VOITURE,
        .categorieVehicule = { .voiture = { .poids = poids,
                                            .typeVoiture = HAUT_GAMME,
                                            .specVoiture = { .voitureHautGamme = { .puissance = puissance }}}}};

}

Vehicule* triTypeVehicule(const Vehicule* parking, size_t tailleParking, Critere type) {
   size_t cpt = compteurType(parking, tailleParking, type); // Le compteur correspond à la taille du tableau du type choisi

   Vehicule* tabType = (Vehicule*) calloc(cpt, sizeof(Vehicule));
   size_t index = 0;

   for (size_t i = 0; i < tailleParking; ++i) {
      if (quelType(&parking[i]) == type) {
         tabType[index++] = parking[i];
      }
   }

   return tabType;
}

Critere quelType(const Vehicule* v) {
    assert(v != NULL);
    switch (v->typeVehicule) {
        case CAMIONETTE:
            return EST_CAMIONETTE;
        case VOITURE:
            switch (v->categorieVehicule.voiture.typeVoiture) {
                case STANDARD:
                    return EST_STANDARD;
                case HAUT_GAMME:
                    return EST_HAUT_GAMME;
            }
    }
}
