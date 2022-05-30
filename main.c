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
//   Vehicule test2 = {.plaque = "VD-17654", .marque = "Toyota", .typeVehicule = VOITURE,
//      .categorieVehicule.voiture.specVoiture.voitureStandard.cylindree = 10};
//   Vehicule test3 = {.plaque = "VD-12223", .marque = "Toyota", .typeVehicule = VOITURE,
//      .categorieVehicule.voiture.specVoiture.voitureHautGamme.puissance = 12};
//   afficherVehicule(&test);
//   afficherVehicule(&test2);
//   afficherVehicule(&test3);

   double tab1[] = {28, 34, 51, 19, 62, 43, 29, 38, 45, 26, 49, 33};
   const size_t TAILLE = sizeof(tab1) / sizeof(double);
   printf("mediane : %f\n", mediane(tab1, TAILLE));
   printf("somme : %f\n",   somme(tab1, TAILLE));
   printf("moyenne : %f\n", moyenne(tab1, TAILLE));

   double tab2[] = {5,2,3,4,8};
   printf("ecart-type : %f\n", ecartType(tab2, 5));

   printf("Taxe annuelle du bateau 1: CHF %.2f", taxeAnnuelle(&test));

   Vehicule parking[] = {camionnette("troller", "troller", 1000),
                         voitureHautGamme("trollerHG", "Khaled", 12, 12),
                         voitureStandard("Michael", "Mich", 10, 10, 10)};

   const size_t TAILLE_PARKING = sizeof(parking) / sizeof(Vehicule);

   afficherParking(parking, TAILLE_PARKING);

   printf("Type %d", quelType(&test));

   return EXIT_SUCCESS;
}
