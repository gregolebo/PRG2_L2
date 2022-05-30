/*
 ---------------------------------------------------------------------------------------------------------------------
 Nom du fichier : taxes.c
 Auteur(s)      :
 Date creation  :
 Description    :
 Remarque(s)    :
 Compilateur    : Mingw-w64 gcc 8.1.0
 ---------------------------------------------------------------------------------------------------------------------
*/

#include <stdlib.h>
#include "taxes.h"
//#include "voitures.h"

CHF taxeAnnuelle(const Vehicule* vehicule) {
   CHF taxe = 0.f;

   switch(vehicule->typeVehicule) {
      case CAMIONETTE:
         taxe += (TAXE_BASE_CAMIONNETTE + COEFF_TAXE_VOL_TRANSP_CAM *
            vehicule->categorieVehicule.camionnette.volumeTransport);
         break;

      case VOITURE:
         taxe += TAXE_BASE_VOITURE;

         // Inclure voitures.h pour utiliser "STANDARD" au lieu de "0" dans le if ?
         //if (vehicule->categorieVehicule.voiture.typeVoiture == STANDARD)

         // Voiture Standard
         if (vehicule->categorieVehicule.voiture.typeVoiture == 0) {
            if (vehicule->categorieVehicule.voiture.specVoiture.voitureStandard.cylindree < SEUIL_CYLINDREE) {
               if (vehicule->categorieVehicule.voiture.specVoiture.voitureStandard.rejetCo2 >= SEUIL_REJET_CO2)
                  taxe += TAXE_CRITERES1_STAND;

            } else
               taxe += (COEFF_TAXE_CYLINDREE_STAND *
                  vehicule->categorieVehicule.voiture.specVoiture.voitureStandard.cylindree);

         } else {
            // Voiture haut de gamme
            if (vehicule->categorieVehicule.voiture.specVoiture.voitureHautGamme.puissance <= SEUIL_PUISSANCE)
               taxe += TAXE_PUISSANCE_HDG;
            else
               taxe += (TAXE_POIDS_BASE_HDG + (COEFF_TAXE_POIDS_HDG * vehicule->categorieVehicule.voiture.poids));

         }
         break;

      default:
         break;

   }
   return taxe;
}

double* calculTaxe(const Vehicule* tabTrie, size_t taille) {
   double* tabTaxe = (double*) calloc(taille, sizeof(double));

   for(size_t i = 0; i < taille; ++i) {
      tabTaxe[i] = taxeAnnuelle(&tabTrie[i]);
   }

   return tabTaxe;
}
