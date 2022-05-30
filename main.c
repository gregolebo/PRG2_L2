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
#include "vehicule.h"
#include "affichage.h"

int main(void) {
   Vehicule parking[] = {camionnette("VD16570", "Toyota", 4.6),
                         voitureStandard("VD43795", "Mazda", 1400, 1200, 100),
                         voitureStandard("VD42098", "Honda", 1350, 1100, 130),
                         voitureStandard("VD42694", "Skoda", 1200, 1150, 150),
                         voitureStandard("VD53683", "Alfa Romeo", 1300, 1400, 115),
                         voitureStandard("VD19034", "Dacia", 1350, 1420, 135),
                         voitureHautGamme("VD32640", "Subaru", 1250, 225),
                         voitureHautGamme("VD42874", "Suzuki", 1000, 250),
                         voitureHautGamme("VD39812", "Volkswagen", 1325, 260)};

   const size_t TAILLE_PARKING = sizeof(parking) / sizeof(Vehicule);

   afficherParking(parking, TAILLE_PARKING);
   afficherStatType(parking, TAILLE_PARKING,  1);

   return EXIT_SUCCESS;
}
