/*
 ---------------------------------------------------------------------------------------------------------------------
 Nom du fichier : affichage.c
 Auteur(s)      :
 Date creation  :
 Description    :
 Remarque(s)    :
 Compilateur    : Mingw-w64 gcc 8.1.0
 ---------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <assert.h>
#include "affichage.h"
#include "voitures.h"

void afficherVehicule(const Vehicule* vehicule) {
   assert(vehicule != NULL);
   // type du vehicule
   // plaque immatriculation et marque
   // si camionette : volume de transport m3
   // poids
   // si voiture standard : cylindrée cm3
   // si haut de gamme : puissance CV
   printf("%s", vehicule->marque);
}
