/*
 -----------------------------------------------------------------------------------
 Nom du fichier : taxes.c
 Auteur(s)      : Grégoire Guyot, Céline Roger, Pablo Urizar
 Date creation  : 26.05.2022
 Description    : Implémentation de la librairie taxes.h permettant de calculer les
                  taxes annuelles dues par les véhicules pour stationner dans le parking
 Remarque(s)    : -
 Compilateur    : Mingw-w64 gcc 8.1.0
 -----------------------------------------------------------------------------------
*/

#include <stdlib.h>
#include "taxes.h"

CHF taxeAnnuelle(const Vehicule *vehicule) {
   CHF taxe = 0.f;

   switch (vehicule->typeVehicule) {
      case CAMIONETTE:
         taxe += TAXE_BASE_CAMIONNETTE +
                 COEFF_TAXE_VOL_TRANSP_CAM *
                 vehicule->categorieVehicule.camionnette.volumeTransport;
         break;

      case VOITURE:
         taxe += TAXE_BASE_VOITURE;

         // Voiture Standard
         if (vehicule->categorieVehicule.voiture.typeVoiture == STANDARD) {
            if (
               vehicule->categorieVehicule.voiture.specVoiture.voitureStandard.cylindree <
               SEUIL_CYLINDREE) {
               if (
                  vehicule->categorieVehicule.voiture.specVoiture.voitureStandard.rejetCo2 >=
                  SEUIL_REJET_CO2)
                  taxe += TAXE_CRITERES1_STAND;

            } else
               taxe += (COEFF_TAXE_CYLINDREE_STAND *
                        vehicule->categorieVehicule.voiture.specVoiture.voitureStandard.cylindree);

         } else {
            // Voiture haut de gamme
            if (
               vehicule->categorieVehicule.voiture.specVoiture.voitureHautGamme.puissance <=
               SEUIL_PUISSANCE)
               taxe += TAXE_PUISSANCE_HDG;
            else
               taxe += TAXE_POIDS_BASE_HDG + COEFF_TAXE_POIDS_HDG *
                                             vehicule->categorieVehicule.voiture.poids;
         }
         break;

      default:
         break;

   }
   return taxe;
}


double* calculTaxe(const Vehicule* tabTrie, size_t taille) {
   double* tabTaxe = (double*) calloc(taille, sizeof(double));

   for (size_t i = 0; i < taille; ++i) {
      tabTaxe[i] = taxeAnnuelle(&tabTrie[i]);
   }

   return tabTaxe;
}
