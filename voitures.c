/*
 ---------------------------------------------------------------------------------------------------------------------
 Nom du fichier : voitures.c
 Auteur(s)      :
 Date creation  :
 Description    :
 Remarque(s)    :
 Compilateur    : Mingw-w64 gcc 8.1.0
 ---------------------------------------------------------------------------------------------------------------------
*/

#include "voitures.h"
#include <assert.h>

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
