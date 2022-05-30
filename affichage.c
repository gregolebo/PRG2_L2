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
#include "vehicule.h"
#include "taxes.h"
#include "calculs.h"

#define str(x) #x
#define xstr(x) str(x)
#define NBR_ESPACES 29
#define FORMAT_SPECS(param) "%-" xstr(NBR_ESPACES) "s : " param "\n"
#define PRECISION_AFFICHAGE "%.2f"

void afficherParking(Vehicule *parking, size_t tailleParking) {
   assert(parking != NULL);

   for (size_t i = 0; i < tailleParking; ++i) {
      assert(&parking[i] != NULL);
      afficherVehicule(&parking[i]);
   }
}

void afficherTaxe(const Vehicule *vehicule) {
   printf(FORMAT_SPECS(PRECISION_AFFICHAGE), "Taxe annuelle [CHF]", taxeAnnuelle(vehicule));
}

void afficherVehicule(const Vehicule *vehicule) {
   assert(vehicule != NULL);
   // type du vehicule
   // plaque immatriculation et marque
   // si camionette : volume de transport m3
   // poids
   // si voiture standard : cylindrée cm3
   // si haut de gamme : puissance CV
   printf("+ ----------------- VEHICULE ----------------- +\n");
   //printf("Marque : %s", vehicule->marque);
   printf(FORMAT_SPECS("%s"), "Marque", vehicule->marque);
   printf(FORMAT_SPECS("%s"), "Plaque", vehicule->plaque);
   printf(FORMAT_SPECS("%s"), "Type de vehicule", TYPE_VEHICULE_STR[vehicule->typeVehicule]);

   switch (vehicule->typeVehicule) {
      case CAMIONETTE:
         printf(FORMAT_SPECS(PRECISION_AFFICHAGE), "Volume de transport",
                vehicule->categorieVehicule.camionnette.volumeTransport);
         break;
      case VOITURE:
         printf(FORMAT_SPECS("%" PRIu16), "Poids [Kg]", vehicule->categorieVehicule.voiture.poids);
         switch (vehicule->categorieVehicule.voiture.typeVoiture) {
            case STANDARD:
               printf(FORMAT_SPECS("%" PRIu16), "Taille cylindree [cm3]",
                      vehicule->categorieVehicule.voiture.specVoiture.voitureStandard.cylindree);
               break;
            case HAUT_GAMME:
               printf(FORMAT_SPECS("%" PRIu16), "Puissance [CV]",
                      vehicule->categorieVehicule.voiture.specVoiture.voitureHautGamme.puissance);
               break;
         }
         break;
   }
   afficherTaxe(vehicule);
}

void afficherStatType(const Vehicule *parking, size_t tailleParking, Critere type) {
   assert(parking != NULL);

   Vehicule *tabTrie = triTypeVehicule(parking, tailleParking, type);

   size_t cpt = compterType(parking, tailleParking, type); // Le compteur correspond à la taille du tableau de taxes
   double* tabTaxe = calculTaxe(tabTrie, cpt);

   printf("%f", *tabTaxe);
}
