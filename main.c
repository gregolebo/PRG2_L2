/*
 ---------------------------------------------------------------------------------------------------------------------
 Nom du fichier : main.c
 Auteur(s)      : Céline Roger, Grégoire Guyot et Pablo Urizar
 Date creation  : 26.05.2022
 Description    : Programme permettant la création d'un parking et affichant l'ensemble des caractéristiques ainsi
                  que la taxe annuelle due des différents véhicules s'y trouvant
 Remarque(s)    : -
 Compilateur    : Mingw-w64 gcc 8.1.0
 ---------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "vehicule.h"
#include "affichage.h"

int main(void) {

   Vehicule parking[] = {camionnette("VD-16570", "Toyota", 4.6),
                         camionnette("VD-2566", "Renault", 8.0),
                         camionnette("VD-189732", "Mercedes", 7.8),
                         camionnette("VD-27839", "Volkswagen", 11.3),
                         voitureStandard("VD-43795", "Mazda", 1400, 1200, 100),
                         voitureStandard("VD-42098", "Honda", 1350, 1100, 130),
                         voitureStandard("VD-42694", "Skoda", 1200, 1150, 150),
                         voitureStandard("VD-53683", "Alfa Romeo", 1300, 1400, 115),
                         voitureStandard("VD-19034", "Dacia", 1350, 1420, 135),
                         voitureHautGamme("VD-32640", "Subaru", 1250, 225),
                         voitureHautGamme("VD-42874", "Suzuki", 1000, 250),
                         voitureHautGamme("VD-39812", "Volkswagen", 1325, 260)};

   const size_t TAILLE_PARKING = sizeof(parking) / sizeof(Vehicule);

   afficherParking(parking, TAILLE_PARKING);

   afficherStatType(parking, TAILLE_PARKING, EST_CAMIONETTE);
   afficherStatType(parking, TAILLE_PARKING, EST_STANDARD);
   afficherStatType(parking, TAILLE_PARKING, EST_HAUT_GAMME);

   return EXIT_SUCCESS;
}
