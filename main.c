/*
 ---------------------------------------------------------------------------------------------------------------------
 Nom du fichier : main.c
 Auteur(s)      : Grégoire Guyot, Céline Roger, Pablo Urizar
 Date creation  :
 Description    :
 Remarque(s)    :
 Compilateur    : Mingw-w64 gcc 8.1.0
 ---------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "voitures.h"
#include "taxes.h"
#include "affichage.h"
#include "calculs.h"

// Attention au choix des véhicules créés -> pertinent avec les cas limites

int main(void) {
   Vehicule test = {.plaque = "VD-15674", .marque = "Toyota", .typeVehicule = CAMIONETTE,
                    .categorieVehicule.camionnette.volumeTransport = 10};
   Vehicule test2 = {.plaque = "VD-17654", .marque = "Toyota", .typeVehicule = VOITURE,
      .categorieVehicule.voiture.specVoiture.voitureStandard.cylindree = 10};
   Vehicule test3 = {.plaque = "VD-12223", .marque = "Toyota", .typeVehicule = VOITURE,
      .categorieVehicule.voiture.specVoiture.voitureHautGamme.puissance = 12};
   afficherVehicule(&test);
   afficherVehicule(&test2);
   afficherVehicule(&test3);
   return EXIT_SUCCESS;
}
