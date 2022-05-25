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
   Vehicule test = {.plaque = "test", .marque = "test", .typeVehicule = CAMIONETTE,
                    .categorieVehicule.voiture.typeVoiture = STANDARD};

   afficherVehicule(&test);
   return EXIT_SUCCESS;
}
