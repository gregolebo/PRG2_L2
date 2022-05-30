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
   printf("\n");
}

void afficherTaxe(const Vehicule *vehicule) {
   printf(FORMAT_SPECS(PRECISION_AFFICHAGE), "Taxe annuelle [CHF]", taxeAnnuelle(vehicule));
}

void afficherVehicule(const Vehicule *vehicule) {
   assert(vehicule != NULL);

   printf("+ ----------------- VEHICULE ----------------- +\n");

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

   size_t cpt = compteurType(parking, tailleParking, type); // Le compteur correspond à la taille du tableau de taxes
   double* tabTaxe = calculTaxe(tabTrie, cpt);
   free(tabTrie);

   printf("+ ------------- TAXES / " "%s" "%s", CRITERE_STR[type], " ------------- +\n");
   printf(FORMAT_SPECS(PRECISION_AFFICHAGE), "Somme", somme(tabTaxe, cpt));
   printf(FORMAT_SPECS(PRECISION_AFFICHAGE), "Moyenne", moyenne(tabTaxe, cpt));
   printf(FORMAT_SPECS(PRECISION_AFFICHAGE), "Mediane", mediane(tabTaxe, cpt));
   printf(FORMAT_SPECS(PRECISION_AFFICHAGE), "Ecart-type", ecartType(tabTaxe, cpt));

   //printf("%f", *tabTaxe);
   free(tabTaxe);
}
