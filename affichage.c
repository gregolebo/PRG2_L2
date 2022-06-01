/*
 -----------------------------------------------------------------------------------
 Nom du fichier : affichage.c
 Auteur(s)      : Grégoire Guyot, Céline Roger, Pablo Urizar
 Date creation  : 26.05.2022
 Description    : Implémentation de la librairie affichage.h permettant d'afficher:
                     - un parking en affichant son contenu (véhicules)
                     - un véhicule en affichant ses caractéristiques
                     - la taxe annuelle d'un véhicule choisi
 Remarque(s)    : -
 Compilateur    : Mingw-w64 gcc 8.1.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <assert.h>
#include "affichage.h"
#include "taxes.h"
#include "calculs.h"

#define str(x) #x
#define xstr(x) str(x)
#define NBR_ESPACES 30
#define FORMAT_AFFICHAGE(param) "%-" xstr(NBR_ESPACES) "s : " param "\n"
#define PRECISION_AFFICHAGE "%.2f"
#define FORMAT_UINT16 "%" PRIu16

void afficherParking(Vehicule* parking, size_t tailleParking) {
   if (!parking) return;

   printf("+ ----------------- PARKING ------------------ +\n");

   qsort(parking, tailleParking, sizeof(Vehicule), compareTaxes);

   for (size_t i = 0; i < tailleParking; ++i) {
      assert(&parking[i] != NULL);
      afficherVehicule(&parking[i]);
   }

   printf("+ ---------------------------------------------- +\n");
   printf("\n");
}

void afficherTaxe(const Vehicule* vehicule) {
   printf(FORMAT_AFFICHAGE(PRECISION_AFFICHAGE), "Taxe annuelle [CHF]",
          taxeAnnuelle(vehicule));
   printf("\n");
}

void afficherVehicule(const Vehicule* vehicule) {
   if (!vehicule) return;

   printf("+ ----------------- VEHICULE ----------------- +\n");
   printf(FORMAT_AFFICHAGE("%s"), "Marque", vehicule->marque);
   printf(FORMAT_AFFICHAGE("%s"), "Plaque", vehicule->plaque);
   printf(FORMAT_AFFICHAGE("%s"), "Type de vehicule",
          TYPE_VEHICULE_STR[vehicule->typeVehicule]);

   switch (vehicule->typeVehicule) {
      case CAMIONETTE:
         printf(FORMAT_AFFICHAGE(PRECISION_AFFICHAGE), "Volume de transport [m3]",
                vehicule->categorieVehicule.camionnette.volumeTransport);
         break;
      case VOITURE:
         printf(FORMAT_AFFICHAGE("%s"), "Voiture de type",
                TYPE_VOITURE_STR[vehicule->categorieVehicule.voiture.typeVoiture]);
         printf(FORMAT_AFFICHAGE(FORMAT_UINT16), "Poids [kg]",
                vehicule->categorieVehicule.voiture.poids);
         switch (vehicule->categorieVehicule.voiture.typeVoiture) {
            case STANDARD:
               printf(FORMAT_AFFICHAGE(FORMAT_UINT16), "Taille cylindree [cm3]",
                      vehicule->categorieVehicule.voiture.specVoiture.voitureStandard.cylindree);
               printf(FORMAT_AFFICHAGE(FORMAT_UINT16), "Rejet CO2 [g/Km]",
                      vehicule->categorieVehicule.voiture.specVoiture
                         .voitureStandard.rejetCo2);
               break;
            case HAUT_GAMME:
               printf(FORMAT_AFFICHAGE(FORMAT_UINT16), "Puissance [CV]",
                      vehicule->categorieVehicule.voiture.specVoiture.voitureHautGamme.puissance);
               break;
         }
         break;
   }
   afficherTaxe(vehicule);
}

void afficherStatType(const Vehicule* parking, size_t tailleParking, Critere type) {
   if (!parking) return;

   Vehicule *tabTrie = triTypeVehicule(parking, tailleParking, type);

   size_t cpt = compteurType(parking, tailleParking, type);

   // Le compteur (cpt) correspond à la taille du tableau de taxes (tabTaxe), car s'il y a 3
   // camionnettes dans le parking, il y aura 3 taxes à calculer
   double* tabTaxe = calculTaxe(tabTrie, cpt);

   free(tabTrie);
   tabTrie = NULL;

   printf("+ ------------- TAXES / " "%s" "%s",
          CRITERE_STR[type], " ------------- +\n");
   printf(FORMAT_AFFICHAGE(PRECISION_AFFICHAGE), "Somme", somme(tabTaxe, cpt));
   printf(FORMAT_AFFICHAGE(PRECISION_AFFICHAGE), "Moyenne", moyenne(tabTaxe, cpt));
   printf(FORMAT_AFFICHAGE(PRECISION_AFFICHAGE), "Mediane", mediane(tabTaxe, cpt));
   printf(FORMAT_AFFICHAGE(PRECISION_AFFICHAGE), "Ecart-type",
          ecartType(tabTaxe, cpt));

   free(tabTaxe);
   tabTaxe = NULL;
}
